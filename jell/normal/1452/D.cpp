#line 1 "codeforces-workspace/contest/1452/d/d.cpp"
/*
 * @file template.cpp
 * @brief Template
 */

#include <bits/extc++.h>

#line 2 "Library/lib/alias"

/*
 * @file alias
 * @brief Alias
 */

#line 13 "Library/lib/alias"

namespace workspace {

constexpr char eol = '\n';

using namespace std;

using i32 = int_least32_t;
using i64 = int_least64_t;
using i128 = __int128_t;
using u32 = uint_least32_t;
using u64 = uint_least64_t;
using u128 = __uint128_t;

template <class T, class Comp = less<T>>
using priority_queue = std::priority_queue<T, vector<T>, Comp>;

template <class T> using stack = std::stack<T, vector<T>>;

}  // namespace workspace
#line 2 "Library/lib/cxx20"

/*
 * @file cxx20
 * @brief C++20 Features
 */

#if __cplusplus <= 201703L

#include <vector>

namespace std {

/*
 * @fn erase_if
 * @brief Erase the elements of a container that do not satisfy the condition.
 * @param __cont Container.
 * @param __pred Predicate.
 * @return Number of the erased elements.
 */
template <typename _Tp, typename _Alloc, typename _Predicate>
inline typename vector<_Tp, _Alloc>::size_type erase_if(
    vector<_Tp, _Alloc>& __cont, _Predicate __pred) {
  const auto __osz = __cont.size();
  __cont.erase(std::remove_if(__cont.begin(), __cont.end(), __pred),
               __cont.end());
  return __osz - __cont.size();
}

/*
 * @fn erase
 * @brief Erase the elements of a container that are equal to the given value.
 * @param __cont Container.
 * @param __value Value.
 * @return Number of the erased elements.
 */
template <typename _Tp, typename _Alloc, typename _Up>
inline typename vector<_Tp, _Alloc>::size_type erase(
    vector<_Tp, _Alloc>& __cont, const _Up& __value) {
  const auto __osz = __cont.size();
  __cont.erase(std::remove(__cont.begin(), __cont.end(), __value),
               __cont.end());
  return __osz - __cont.size();
}

}  // namespace std

#endif
#line 2 "Library/lib/option"

/*
 * @file option
 * @brief Optimize Options
 */

#ifdef ONLINE_JUDGE

#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2")
#pragma GCC optimize("unroll-loops")

#endif
#line 2 "Library/src/utils/binary_search.hpp"

/*
 * @file binary_search.hpp
 * @brief Binary Search
 */

#if __cplusplus >= 201703L

#include <cassert>
#include <cmath>
#include <vector>

namespace workspace {

/*
 * @fn binary_search
 * @brief binary search on a discrete range.
 * @param ok pred(ok) is true
 * @param ng pred(ng) is false
 * @param pred the predicate
 * @return the closest point to (ng) where pred is true
 */
template <class iter_type, class pred_type>
std::enable_if_t<
    std::is_convertible_v<std::invoke_result_t<pred_type, iter_type>, bool>,
    iter_type>
binary_search(iter_type ok, iter_type ng, pred_type pred) {
  assert(ok != ng);
  std::make_signed_t<decltype(ng - ok)> dist(ng - ok);
  while (1 < dist || dist < -1) {
    iter_type mid(ok + dist / 2);
    if (pred(mid))
      ok = mid, dist -= dist / 2;
    else
      ng = mid, dist /= 2;
  }
  return ok;
}

/*
 * @fn parallel_binary_search
 * @brief parallel binary search on discrete ranges.
 * @param ends a vector of pairs; pred(first) is true, pred(second) is false
 * @param pred the predicate
 * @return the closest points to (second) where pred is true
 */
template <class iter_type, class pred_type>
std::enable_if_t<std::is_convertible_v<
                     std::invoke_result_t<pred_type, std::vector<iter_type>>,
                     std::vector<bool>>,
                 std::vector<iter_type>>
parallel_binary_search(std::vector<std::pair<iter_type, iter_type>> ends,
                       pred_type pred) {
  std::vector<iter_type> mids(ends.size());
  for (;;) {
    bool all_found = true;
    for (size_t i{}; i != ends.size(); ++i) {
      auto [ok, ng] = ends[i];
      iter_type mid(ok + (ng - ok) / 2);
      if (mids[i] != mid) {
        all_found = false;
        mids[i] = mid;
      }
    }
    if (all_found) break;
    auto res = pred(mids);
    for (size_t i{}; i != ends.size(); ++i) {
      (res[i] ? ends[i].first : ends[i].second) = mids[i];
    }
  }
  return mids;
}

/*
 * @fn binary_search
 * @brief binary search on the real number line.
 * @param ok pred(ok) is true
 * @param ng pred(ng) is false
 * @param eps the error tolerance
 * @param pred the predicate
 * @return the boundary point
 */
template <class real_type, class pred_type>
std::enable_if_t<
    std::is_convertible_v<std::invoke_result_t<pred_type, real_type>, bool>,
    real_type>
binary_search(real_type ok, real_type ng, const real_type eps, pred_type pred) {
  assert(ok != ng);
  for (auto loops = 0; loops != std::numeric_limits<real_type>::digits &&
                       (ok + eps < ng || ng + eps < ok);
       ++loops) {
    real_type mid{(ok + ng) / 2};
    (pred(mid) ? ok : ng) = mid;
  }
  return ok;
}

/*
 * @fn parallel_binary_search
 * @brief parallel binary search on the real number line.
 * @param ends a vector of pairs; pred(first) is true, pred(second) is false
 * @param eps the error tolerance
 * @param pred the predicate
 * @return the boundary points
 */
template <class real_type, class pred_type>
std::enable_if_t<std::is_convertible_v<
                     std::invoke_result_t<pred_type, std::vector<real_type>>,
                     std::vector<bool>>,
                 std::vector<real_type>>
parallel_binary_search(std::vector<std::pair<real_type, real_type>> ends,
                       const real_type eps, pred_type pred) {
  std::vector<real_type> mids(ends.size());
  for (auto loops = 0; loops != std::numeric_limits<real_type>::digits;
       ++loops) {
    bool all_found = true;
    for (size_t i{}; i != ends.size(); ++i) {
      auto [ok, ng] = ends[i];
      if (ok + eps < ng || ng + eps < ok) {
        all_found = false;
        mids[i] = (ok + ng) / 2;
      }
    }
    if (all_found) break;
    auto res = pred(mids);
    for (size_t i{}; i != ends.size(); ++i) {
      (res[i] ? ends[i].first : ends[i].second) = mids[i];
    }
  }
  return mids;
}

}  // namespace workspace

#endif
#line 2 "Library/src/utils/chval.hpp"

/*
 * @file chval.hpp
 * @brief Change Less/Greater
 */

#line 9 "Library/src/utils/chval.hpp"

namespace workspace {

/*
 * @fn chle
 * @brief Substitute y for x if comp(y, x) is true.
 * @param x Reference
 * @param y Const reference
 * @param comp Compare function
 * @return Whether or not x is updated
 */
template <class Tp, class Comp = std::less<Tp>>
bool chle(Tp &x, const Tp &y, Comp comp = Comp()) {
  return comp(y, x) ? x = y, true : false;
}

/*
 * @fn chge
 * @brief Substitute y for x if comp(x, y) is true.
 * @param x Reference
 * @param y Const reference
 * @param comp Compare function
 * @return Whether or not x is updated
 */
template <class Tp, class Comp = std::less<Tp>>
bool chge(Tp &x, const Tp &y, Comp comp = Comp()) {
  return comp(x, y) ? x = y, true : false;
}

}  // namespace workspace
#line 5 "Library/src/utils/coordinate_compression.hpp"

template <class T> class coordinate_compression {
  std::vector<T> uniquely;
  std::vector<size_t> compressed;

 public:
  coordinate_compression(const std::vector<T> &raw)
      : uniquely(raw), compressed(raw.size()) {
    std::sort(uniquely.begin(), uniquely.end());
    uniquely.erase(std::unique(uniquely.begin(), uniquely.end()),
                   uniquely.end());
    for (size_t i = 0; i != size(); ++i)
      compressed[i] =
          std::lower_bound(uniquely.begin(), uniquely.end(), raw[i]) -
          uniquely.begin();
  }

  size_t operator[](const size_t idx) const {
    assert(idx < size());
    return compressed[idx];
  }

  size_t size() const { return compressed.size(); }

  size_t count() const { return uniquely.size(); }

  T value(const size_t ord) const {
    assert(ord < count());
    return uniquely[ord];
  }

  size_t order(const T &value) const {
    return std::lower_bound(uniquely.begin(), uniquely.end(), value) -
           uniquely.begin();
  }

  auto begin() { return compressed.begin(); }
  auto end() { return compressed.end(); }
  auto rbegin() { return compressed.rbegin(); }
  auto rend() { return compressed.rend(); }
};
#line 2 "Library/src/utils/ejection.hpp"

/*
 * @file ejection.hpp
 * @brief Ejection
 */

#line 9 "Library/src/utils/ejection.hpp"

namespace workspace {

/*
 * @brief eject from a try block, throw nullptr
 * @param arg output
 */
template <class Tp> void eject(Tp const &arg) {
  std::cout << arg << "\n";
  throw nullptr;
}

}  // namespace workspace
#line 2 "Library/src/utils/fixed_point.hpp"

/*
 * @file fixed_point.hpp
 * @brief Fixed Point Combinator
 */

#line 9 "Library/src/utils/fixed_point.hpp"

namespace workspace {

/*
 * @class fixed_point
 * @brief Recursive calling of lambda expression.
 */
template <class lambda_type> class fixed_point {
  lambda_type func;

 public:
  /*
   * @param func 1st arg callable with the rest of args, and the return type
   * specified.
   */
  fixed_point(lambda_type &&func) : func(std::move(func)) {}

  /*
   * @brief Recursively apply *this to 1st arg of func.
   * @param args Arguments of the recursive method.
   */
  template <class... Args> auto operator()(Args &&... args) const {
    return func(*this, std::forward<Args>(args)...);
  }
};

}  // namespace workspace
#line 2 "Library/src/utils/grid/rotate.hpp"

#line 2 "Library/src/utils/sfinae.hpp"

/*
 * @file sfinae.hpp
 * @brief SFINAE
 */

#line 10 "Library/src/utils/sfinae.hpp"
#include <type_traits>

template <class type, template <class> class trait>
using enable_if_trait_type = typename std::enable_if<trait<type>::value>::type;

template <class Container>
using element_type = typename std::decay<decltype(
    *std::begin(std::declval<Container&>()))>::type;

template <class T, class = int> struct mapped_of {
  using type = element_type<T>;
};
template <class T>
struct mapped_of<T,
                 typename std::pair<int, typename T::mapped_type>::first_type> {
  using type = typename T::mapped_type;
};
template <class T> using mapped_type = typename mapped_of<T>::type;

template <class T, class = void> struct is_integral_ext : std::false_type {};
template <class T>
struct is_integral_ext<
    T, typename std::enable_if<std::is_integral<T>::value>::type>
    : std::true_type {};
template <> struct is_integral_ext<__int128_t> : std::true_type {};
template <> struct is_integral_ext<__uint128_t> : std::true_type {};
#if __cplusplus >= 201402
template <class T>
constexpr static bool is_integral_ext_v = is_integral_ext<T>::value;
#endif

template <typename T, typename = void> struct multiplicable_uint {
  using type = uint_least32_t;
};
template <typename T>
struct multiplicable_uint<T, typename std::enable_if<(2 < sizeof(T))>::type> {
  using type = uint_least64_t;
};
template <typename T>
struct multiplicable_uint<T, typename std::enable_if<(4 < sizeof(T))>::type> {
  using type = __uint128_t;
};
#line 4 "Library/src/utils/grid/rotate.hpp"

namespace workspace {

template <class Grid> Grid transposed(Grid const &grid) {
  auto height = std::size(grid);
  // auto width = grid[0]
  using Row = element_type<Grid>;
  Grid transposed;
  for (auto &&row : grid) {
    auto iter = std::begin(transposed);
    for (auto &&e : row) {
      if (iter == std::end(transposed)) {
      } else {
        iter->insert(iter->end(), e);
      }
      ++iter;
    }
  }
  return transposed;
}

template <class Grid> Grid rotated(Grid const &grid) {}

}  // namespace workspace
#line 6 "Library/src/utils/hash.hpp"

#line 8 "Library/src/utils/hash.hpp"
namespace workspace {
template <class T, class = void> struct hash : std::hash<T> {};
#if __cplusplus >= 201703L
template <class Unique_bits_type>
struct hash<Unique_bits_type,
            enable_if_trait_type<Unique_bits_type,
                                 std::has_unique_object_representations>> {
  size_t operator()(uint64_t x) const {
    static const uint64_t m = std::random_device{}();
    x ^= x >> 23;
    x ^= m;
    x ^= x >> 47;
    return x - (x >> 32);
  }
};
#endif
template <class Key> size_t hash_combine(const size_t &seed, const Key &key) {
  return seed ^
         (hash<Key>()(key) + 0x9e3779b9 /* + (seed << 6) + (seed >> 2) */);
}
template <class T1, class T2> struct hash<std::pair<T1, T2>> {
  size_t operator()(const std::pair<T1, T2> &pair) const {
    return hash_combine(hash<T1>()(pair.first), pair.second);
  }
};
template <class... T> class hash<std::tuple<T...>> {
  template <class Tuple, size_t index = std::tuple_size<Tuple>::value - 1>
  struct tuple_hash {
    static uint64_t apply(const Tuple &t) {
      return hash_combine(tuple_hash<Tuple, index - 1>::apply(t),
                          std::get<index>(t));
    }
  };
  template <class Tuple> struct tuple_hash<Tuple, size_t(-1)> {
    static uint64_t apply(const Tuple &t) { return 0; }
  };

 public:
  uint64_t operator()(const std::tuple<T...> &t) const {
    return tuple_hash<std::tuple<T...>>::apply(t);
  }
};
template <class hash_table> struct hash_table_wrapper : hash_table {
  using key_type = typename hash_table::key_type;
  size_t count(const key_type &key) const {
    return hash_table::find(key) != hash_table::end();
  }
  template <class... Args> auto emplace(Args &&... args) {
    return hash_table::insert(typename hash_table::value_type(args...));
  }
};
template <class Key, class Mapped = __gnu_pbds::null_type>
using cc_hash_table =
    hash_table_wrapper<__gnu_pbds::cc_hash_table<Key, Mapped, hash<Key>>>;
template <class Key, class Mapped = __gnu_pbds::null_type>
using gp_hash_table =
    hash_table_wrapper<__gnu_pbds::gp_hash_table<Key, Mapped, hash<Key>>>;
template <class Key, class Mapped>
using unordered_map = std::unordered_map<Key, Mapped, hash<Key>>;
template <class Key> using unordered_set = std::unordered_set<Key, hash<Key>>;
}  // namespace workspace
#line 2 "Library/src/utils/io/casefmt.hpp"

/*
 * @file castfmt
 * @brief Case Output Format
 */

#line 2 "Library/src/utils/iterate_case.hpp"

/*
 * @file iterate_case.hpp
 * @brief Iterate Testcases
 */

namespace workspace {

namespace internal {
// The 1-based index of the current testcase.
unsigned caseid;
}  // namespace internal

void main();
unsigned case_number();

/*
 * @fn iterate_main
 * @brief Iterate main function.
 */
void iterate_main() {
  for (unsigned total = case_number(), &counter = (internal::caseid = 1);
       counter <= total; ++counter) {
    try {
      main();
    } catch (std::nullptr_t) {
    }
  }
}

}  // namespace workspace
#line 9 "Library/src/utils/io/casefmt.hpp"

namespace workspace {

/*
 * @fn casefmt
 * @brief printf("Case #%u: ", internal::caseid)
 * @param os Reference to ostream
 * @return os
 */
std::ostream& casefmt(std::ostream& os) {
  return os << "Case #" << internal::caseid << ": ";
}

}  // namespace workspace
#line 3 "Library/src/utils/io/read.hpp"
namespace workspace {
// read with std::cin.
template <class T = void>
struct read
{
    typename std::remove_const<T>::type value;
    template <class... types>
    read(types... args) : value(args...) { std::cin >> value; }
    operator T() const { return value; }
};
template <>
struct read<void>
{
    template <class T>
    operator T() const { T value; std::cin >> value; return value; }
};
} // namespace workspace
#line 4 "Library/src/utils/io/stream.hpp"

#line 6 "Library/src/utils/io/stream.hpp"

namespace std {
template <class T, class U> istream &operator>>(istream &is, pair<T, U> &p) {
  return is >> p.first >> p.second;
}
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  return os << p.first << ' ' << p.second;
}
template <class tuple_t, size_t index> struct tuple_is {
  static istream &apply(istream &is, tuple_t &t) {
    tuple_is<tuple_t, index - 1>::apply(is, t);
    return is >> get<index>(t);
  }
};
template <class tuple_t> struct tuple_is<tuple_t, SIZE_MAX> {
  static istream &apply(istream &is, tuple_t &t) { return is; }
};
template <class... T> istream &operator>>(istream &is, tuple<T...> &t) {
  return tuple_is<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(is,
                                                                          t);
}
template <class tuple_t, size_t index> struct tuple_os {
  static ostream &apply(ostream &os, const tuple_t &t) {
    tuple_os<tuple_t, index - 1>::apply(os, t);
    return os << ' ' << get<index>(t);
  }
};
template <class tuple_t> struct tuple_os<tuple_t, 0> {
  static ostream &apply(ostream &os, const tuple_t &t) {
    return os << get<0>(t);
  }
};
template <class tuple_t> struct tuple_os<tuple_t, SIZE_MAX> {
  static ostream &apply(ostream &os, const tuple_t &t) { return os; }
};
template <class... T> ostream &operator<<(ostream &os, const tuple<T...> &t) {
  return tuple_os<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(os,
                                                                          t);
}
template <class Container, typename Value = element_type<Container>>
typename enable_if<!is_same<typename decay<Container>::type, string>::value &&
                       !is_same<typename decay<Container>::type, char *>::value,
                   istream &>::type
operator>>(istream &is, Container &cont) {
  for (auto &&e : cont) is >> e;
  return is;
}
template <class Container, typename Value = element_type<Container>>
typename enable_if<!is_same<typename decay<Container>::type, string>::value &&
                       !is_same<typename decay<Container>::type, char *>::value,
                   ostream &>::type
operator<<(ostream &os, const Container &cont) {
  bool head = true;
  for (auto &&e : cont) head ? head = 0 : (os << ' ', 0), os << e;
  return os;
}
}  // namespace std
#line 2 "Library/src/utils/make_vector.hpp"

/*
 * @file make_vector.hpp
 * @brief Multi-dimensional Vector
 */

#if __cplusplus >= 201703L

#include <tuple>
#include <vector>

namespace workspace {

/*
 * @brief Make a multi-dimensional vector.
 * @tparam Tp type of the elements
 * @tparam N dimension
 * @tparam S integer type
 * @param sizes The size of each dimension
 * @param init The initial value
 */
template <typename Tp, size_t N, typename S>
constexpr auto make_vector(S* sizes, Tp const& init = Tp()) {
  static_assert(std::is_convertible_v<S, size_t>);
  if constexpr (N)
    return std::vector(*sizes,
                       make_vector<Tp, N - 1, S>(std::next(sizes), init));
  else
    return init;
}

/*
 * @brief Make a multi-dimensional vector.
 * @param sizes The size of each dimension
 * @param init The initial value
 */
template <typename Tp, size_t N, typename S>
constexpr auto make_vector(const S (&sizes)[N], Tp const& init = Tp()) {
  return make_vector<Tp, N, S>((S*)sizes, init);
}

/*
 * @brief Make a multi-dimensional vector.
 * @param sizes The size of each dimension
 * @param init The initial value
 */
template <typename Tp, size_t N, typename S, size_t I = 0>
constexpr auto make_vector(std::array<S, N> const& sizes,
                           Tp const& init = Tp()) {
  static_assert(std::is_convertible_v<S, size_t>);
  if constexpr (I == N)
    return init;
  else
    return std::vector(sizes[I], make_vector<Tp, N, S, I + 1>(sizes, init));
}

/*
 * @brief Make a multi-dimensional vector.
 * @param sizes The size of each dimension
 * @param init The initial value
 */
template <typename Tp, size_t N = SIZE_MAX, size_t I = 0, class... Args>
constexpr auto make_vector(std::tuple<Args...> const& sizes,
                           Tp const& init = Tp()) {
  using tuple_type = std::tuple<Args...>;
  if constexpr (I == std::tuple_size_v<tuple_type> || I == N)
    return init;
  else {
    static_assert(
        std::is_convertible_v<std::tuple_element_t<I, tuple_type>, size_t>);
    return std::vector(std::get<I>(sizes),
                       make_vector<Tp, N, I + 1>(sizes, init));
  }
}

/*
 * @brief Make a multi-dimensional vector.
 * @param sizes The size of each dimension
 * @param init The initial value
 */
template <typename Tp, class Fst, class Snd>
constexpr auto make_vector(std::pair<Fst, Snd> const& sizes,
                           Tp const& init = Tp()) {
  static_assert(std::is_convertible_v<Fst, size_t>);
  static_assert(std::is_convertible_v<Snd, size_t>);
  return make_vector({(size_t)sizes.first, (size_t)sizes.second}, init);
}

}  // namespace workspace

#endif
#line 3 "Library/src/utils/random_number_generator.hpp"
template <typename num_type> class random_number_generator {
  typename std::conditional<std::is_integral<num_type>::value,
                            std::uniform_int_distribution<num_type>,
                            std::uniform_real_distribution<num_type>>::type
      unif;

  std::mt19937 engine;

 public:
  random_number_generator(num_type min = std::numeric_limits<num_type>::min(),
                          num_type max = std::numeric_limits<num_type>::max())
      : unif(min, max), engine(std::random_device{}()) {}

  num_type min() const { return unif.min(); }

  num_type max() const { return unif.max(); }

  // generate a random number in [min(), max()].
  num_type operator()() { return unif(engine); }
};
#line 2 "Library/src/utils/round_div.hpp"

/*
 * @file round_div.hpp
 * @brief Round Integer Division
 */

#line 9 "Library/src/utils/round_div.hpp"

#line 11 "Library/src/utils/round_div.hpp"

namespace workspace {

/*
 * @fn floor_div
 * @brief floor of fraction.
 * @param x the numerator
 * @param y the denominator
 * @return maximum integer z s.t. z <= x / y
 * @note y must be nonzero.
 */
template <typename T1, typename T2>
constexpr typename std::enable_if<(is_integral_ext<T1>::value &&
                                   is_integral_ext<T2>::value),
                                  typename std::common_type<T1, T2>::type>::type
floor_div(T1 x, T2 y) {
  assert(y != 0);
  if (y < 0) x = -x, y = -y;
  return x < 0 ? (x - y + 1) / y : x / y;
}

/*
 * @fn ceil_div
 * @brief ceil of fraction.
 * @param x the numerator
 * @param y the denominator
 * @return minimum integer z s.t. z >= x / y
 * @note y must be nonzero.
 */
template <typename T1, typename T2>
constexpr typename std::enable_if<(is_integral_ext<T1>::value &&
                                   is_integral_ext<T2>::value),
                                  typename std::common_type<T1, T2>::type>::type
ceil_div(T1 x, T2 y) {
  assert(y != 0);
  if (y < 0) x = -x, y = -y;
  return x < 0 ? x / y : (x + y - 1) / y;
}

}  // namespace workspace
#line 2 "Library/src/utils/setup.hpp"

/*
 * @file setup.hpp
 * @brief Setup
 */

#line 11 "Library/src/utils/setup.hpp"

namespace workspace {

/*
 * @fn io_setup
 * @brief Setup I/O before main process.
 */
__attribute__((constructor)) void io_setup() {
  using namespace std;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(15);

#ifdef _buffer_check
  atexit([] {
    char bufc;
    if (cin >> bufc)
      cerr << "\n\033[43m\033[30mwarning: buffer not empty.\033[0m\n\n";
  });
#endif
}

namespace internal {
// The start time of the program.
const auto start_time{std::chrono::system_clock::now()};
}  // namespace internal

/*
 * @fn elapsed
 * @return elapsed time of the program
 */
int64_t elapsed() {
  using namespace std::chrono;
  const auto end_time{system_clock::now()};
  return duration_cast<milliseconds>(end_time - internal::start_time).count();
}

}  // namespace workspace
#line 4 "Library/src/utils/trinary_search.hpp"
// trinary search on discrete range.
template <class iter_type, class comp_type>
iter_type trinary(iter_type first, iter_type last, comp_type comp)
{
    assert(first < last);
    intmax_t dist(last - first);
    while(dist > 2)
    {
        iter_type left(first + dist / 3), right(first + dist * 2 / 3);
        if(comp(left, right)) last = right, dist = dist * 2 / 3;
        else first = left, dist -= dist / 3;
    }
    if(dist > 1 && comp(first + 1, first)) ++first;
    return first;
}
// trinary search on real numbers.
template <class comp_type>
long double trinary(long double first, long double last, const long double eps, comp_type comp)
{
    assert(first < last);
    while(last - first > eps)
    {
        long double left{(first * 2 + last) / 3}, right{(first + last * 2) / 3};
        if(comp(left, right)) last = right;
        else first = left;
    }
    return first;
}
#line 2 "Library/src/utils/wrapper.hpp"
template <class Container> class reversed {
  Container &ref, copy;

 public:
  constexpr reversed(Container &ref) : ref(ref) {}
  constexpr reversed(Container &&ref = Container()) : ref(copy), copy(ref) {}
  constexpr auto begin() const { return ref.rbegin(); }
  constexpr auto end() const { return ref.rend(); }
  constexpr operator Container() const { return ref; }
};
#line 12 "codeforces-workspace/contest/1452/d/d.cpp"

int main() { workspace::iterate_main(); }

unsigned workspace::case_number() {
  // return -1; // unspecified
  // int t; std::cin >> t; std::cin.ignore(); return t; // given
  return 1;
}

#line 2 "Library/src/combinatorics/binomial.hpp"

/*
 * @file binomial.hpp
 * @brief Binomial Coefficient
 */

#line 2 "Library/src/modular/inverse.hpp"

/*
 * @file inverse.hpp
 * @brief Inverse Table
 */

#line 9 "Library/src/modular/inverse.hpp"

#line 2 "Library/src/modular/modint.hpp"

/*
 * @file modint.hpp
 * @brief Modular Arithmetic
 */

#line 10 "Library/src/modular/modint.hpp"

#line 12 "Library/src/modular/modint.hpp"

namespace workspace {

namespace internal {

/*
 * @struct modint_base
 * @brief base of modular arithmetic.
 * @tparam Mod identifier, which represents modulus if positive
 */
template <auto Mod> struct modint_base {
  static_assert(is_integral_ext<decltype(Mod)>::value,
                "Mod must be integral type.");

  using mod_type =
      typename std::conditional<0 < Mod,
                                typename std::add_const<decltype(Mod)>::type,
                                decltype(Mod)>::type;
  static mod_type mod;

  using value_type = typename std::decay<mod_type>::type;

  constexpr operator value_type() const noexcept { return value; }

  constexpr static modint_base one() noexcept { return 1; }

  constexpr modint_base() noexcept = default;

  template <class int_type,
            typename std::enable_if<is_integral_ext<int_type>::value>::type * =
                nullptr>
  constexpr modint_base(int_type n) noexcept
      : value((n %= mod) < 0 ? mod + n : n) {}

  constexpr modint_base(bool n) noexcept : modint_base(int(n)) {}

  constexpr modint_base operator++(int) noexcept {
    modint_base t{*this};
    return operator+=(1), t;
  }

  constexpr modint_base operator--(int) noexcept {
    modint_base t{*this};
    return operator-=(1), t;
  }

  constexpr modint_base &operator++() noexcept { return operator+=(1); }

  constexpr modint_base &operator--() noexcept { return operator-=(1); }

  constexpr modint_base operator-() const noexcept {
    return value ? mod - value : 0;
  }

  constexpr modint_base &operator+=(const modint_base &rhs) noexcept {
    return (value += rhs.value) < mod ? 0 : value -= mod, *this;
  }

  constexpr modint_base &operator-=(const modint_base &rhs) noexcept {
    return (value += mod - rhs.value) < mod ? 0 : value -= mod, *this;
  }

  constexpr modint_base &operator*=(const modint_base &rhs) noexcept {
    return value = (typename multiplicable_uint<value_type>::type)value *
                   rhs.value % mod,
           *this;
  }

  constexpr modint_base &operator/=(const modint_base &rhs) noexcept {
    return operator*=(rhs.inverse());
  }

  template <class int_type>
  constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                    modint_base>::type
  operator+(const int_type &rhs) const noexcept {
    return modint_base{*this} += rhs;
  }

  constexpr modint_base operator+(const modint_base &rhs) const noexcept {
    return modint_base{*this} += rhs;
  }

  template <class int_type>
  constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                    modint_base>::type
  operator-(const int_type &rhs) const noexcept {
    return modint_base{*this} -= rhs;
  }

  constexpr modint_base operator-(const modint_base &rhs) const noexcept {
    return modint_base{*this} -= rhs;
  }

  template <class int_type>
  constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                    modint_base>::type
  operator*(const int_type &rhs) const noexcept {
    return modint_base{*this} *= rhs;
  }

  constexpr modint_base operator*(const modint_base &rhs) const noexcept {
    return modint_base{*this} *= rhs;
  }

  template <class int_type>
  constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                    modint_base>::type
  operator/(const int_type &rhs) const noexcept {
    return modint_base{*this} /= rhs;
  }

  constexpr modint_base operator/(const modint_base &rhs) const noexcept {
    return modint_base{*this} /= rhs;
  }

  template <class int_type>
  constexpr friend typename std::enable_if<is_integral_ext<int_type>::value,
                                           modint_base>::type
  operator+(const int_type &lhs, const modint_base &rhs) noexcept {
    return modint_base(lhs) + rhs;
  }

  template <class int_type>
  constexpr friend typename std::enable_if<is_integral_ext<int_type>::value,
                                           modint_base>::type
  operator-(const int_type &lhs, const modint_base &rhs) noexcept {
    return modint_base(lhs) - rhs;
  }

  template <class int_type>
  constexpr friend typename std::enable_if<is_integral_ext<int_type>::value,
                                           modint_base>::type
  operator*(const int_type &lhs, const modint_base &rhs) noexcept {
    return modint_base(lhs) * rhs;
  }

  template <class int_type>
  constexpr friend typename std::enable_if<is_integral_ext<int_type>::value,
                                           modint_base>::type
  operator/(const int_type &lhs, const modint_base &rhs) noexcept {
    return modint_base(lhs) / rhs;
  }

  constexpr modint_base inverse() const noexcept {
    assert(value);
    value_type a{mod}, b{value}, u{}, v{1}, t{};
    while (b)
      t = a / b, a ^= b ^= (a -= t * b) ^= b, u ^= v ^= (u -= t * v) ^= v;
    return {u};
  }

  template <class int_type>
  constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                    modint_base>::type
  power(int_type e) noexcept {
    return pow(*this, e);
  }

  template <class int_type>
  friend constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                           modint_base>::type
  pow(modint_base b, int_type e) noexcept {
    modint_base res{1};
    for (e < 0 ? b = b.inverse(), e = -e : 0; e; e >>= 1, b *= b)
      if (e & 1) res *= b;
    return res;
  }

  friend std::ostream &operator<<(std::ostream &os,
                                  const modint_base &rhs) noexcept {
    return os << rhs.value;
  }

  friend std::istream &operator>>(std::istream &is, modint_base &rhs) noexcept {
    intmax_t value;
    rhs = (is >> value, value);
    return is;
  }

 protected:
  value_type value = 0;
};

template <auto Mod>
typename modint_base<Mod>::mod_type modint_base<Mod>::mod = Mod;

}  // namespace internal

/*
 * @typedef modint
 * @brief modular arithmetic.
 * @tparam Mod modulus
 */
template <auto Mod, typename std::enable_if<(Mod > 0)>::type * = nullptr>
using modint = internal::modint_base<Mod>;

/*
 * @typedef modint_runtime
 * @brief runtime modular arithmetic.
 * @tparam type_id uniquely assigned
 */
template <unsigned type_id = 0>
using modint_runtime = internal::modint_base<-(signed)type_id>;

// #define modint_newtype modint_runtime<__COUNTER__>

}  // namespace workspace
#line 11 "Library/src/modular/inverse.hpp"

namespace workspace {

// Modulus must be prime.
template <class Modint> struct inverse_table {
  static_assert(std::is_same<std::nullptr_t,
                             decltype((void *)Modint::mod, nullptr)>::value);

  using value_type = Modint;

  constexpr value_type operator()(int n) const {
    constexpr int_fast64_t mod = value_type::mod;
    assert(n %= mod);
    if (n < 0) n += mod;
    if (inv.empty()) inv = {1, mod != 1};
    for (int m(inv.size()); m <= n; ++m)
      inv.emplace_back(mod / m * -inv[mod % m]);
    return inv[n];
  }

 private:
  static std::vector<value_type> inv;
};

template <class Modint> std::vector<Modint> inverse_table<Modint>::inv;

}  // namespace workspace
#line 4 "Library/src/combinatorics/factorial.hpp"
template <class T, class Op = std::multiplies<T>>
class factorial
{
    std::vector<T> fact;
    Op op;
public:
    factorial(T init = 1, Op op = Op()) : fact{init}, op{op} {}
    T operator()(const int &n)
    {
        if(n < 0) return 0;
        for(int m(fact.size()); m <= n; ++m) fact.emplace_back(op(fact.back(), m));
        return fact[n];
    }
}; // class factorial
#line 11 "Library/src/combinatorics/binomial.hpp"

namespace workspace {

template <class, class = int> struct binomial;
template <class Modint> struct binomial<Modint> {
  static_assert(std::is_same<std::nullptr_t,
                             decltype((void *)Modint::mod, nullptr)>::value);

  using value_type = Modint;
  struct mulinv_Op {
    value_type operator()(const value_type &f, const size_t &n) const {
      return f * inv(n);
    }
  };

  static inverse_table<value_type> inv;
  static factorial<value_type, mulinv_Op> fact_inv;
  static factorial<value_type> fact;

  value_type operator()(int_least32_t n, int_least32_t k) {
    return fact_inv(k) * fact_inv(n - k) * fact(n);
  }
};

template <class Modint> inverse_table<Modint> binomial<Modint>::inv;
template <class Modint>
factorial<Modint, class binomial<Modint>::mulinv_Op> binomial<Modint>::fact_inv;
template <class Modint> factorial<Modint> binomial<Modint>::fact;

}  // namespace workspace
#line 22 "codeforces-workspace/contest/1452/d/d.cpp"

namespace workspace {
void main() {
  // start here!
  using mint = modint<998244353>;
  binomial<mint> bin;
  int n;
  cin >> n;
  mint ans;
  for (auto k = 0; k <= n; ++k) {
    if ((n - k) & 1) continue;
    ans += bin(k - 1 + (n - k) / 2, k - 1);
  }
  for (auto i = 0; i < n; ++i) {
    ans /= 2;
  }
  cout << ans << eol;
}
}  // namespace workspace