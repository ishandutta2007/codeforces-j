#line 1 "codeforces-workspace/contest/1450/f/f.cpp"
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
using u32 = uint_least32_t;
using i64 = int_least64_t;
using u64 = uint_least64_t;

#ifdef __SIZEOF_INT128__
using i128 = __int128_t;
using u128 = __uint128_t;
#endif

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

#include <algorithm>
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
#line 2 "Library/src/sys/ejection.hpp"

/*
 * @file ejection.hpp
 * @brief Ejection
 */

#line 9 "Library/src/sys/ejection.hpp"

namespace workspace {

struct ejection {
  bool exit = 0;
};

/*
 * @brief eject from a try block, throw nullptr
 * @param arg output
 */
template <class Tp> void eject(Tp const &arg) {
  std::cout << arg << "\n";
  throw ejection{};
}

void exit() { throw ejection{true}; }

}  // namespace workspace
#line 2 "Library/src/sys/iteration.hpp"

/*
 * @file iteration.hpp
 * @brief Case Iteration
 */

#line 9 "Library/src/sys/iteration.hpp"

#line 11 "Library/src/sys/iteration.hpp"

namespace workspace {

void main();

struct {
  unsigned current{0}, total{1};
  int iterate() {
    static bool once = false;
    assert(!once);
    once = true;
    while (current++ < total) {
      try {
        main();
      } catch (ejection const& status) {
        if (status.exit) break;
      }
    }
    return 0;
  }
} case_info;

}  // namespace workspace
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
#line 2 "Library/src/utils/clock.hpp"

/*
 * @fn clock.hpp
 * @brief Clock
 */

#line 9 "Library/src/utils/clock.hpp"

namespace workspace {

using namespace std::chrono;

namespace internal {
// The start time of the program.
const auto start_time{system_clock::now()};
}  // namespace internal

/*
 * @fn elapsed
 * @return elapsed time of the program
 */
int64_t elapsed() {
  const auto end_time{system_clock::now()};
  return duration_cast<milliseconds>(end_time - internal::start_time).count();
}

}  // namespace workspace
#line 2 "Library/src/utils/exponential_search.hpp"

/*
 * @file exponential_search.hpp
 * @brief Exponential Search
 */

#line 9 "Library/src/utils/exponential_search.hpp"

#if __cplusplus >= 201703L

namespace workspace {

/*
 * @fn exponential_search
 * @brief Exponential search on a discrete range.
 * @param range Range of search, exclusive
 * @param pred Predicate
 * @return The minimum non-negative integer where pred is false.
 */
template <class size_type, class pred_type>
std::enable_if_t<
    std::is_convertible_v<std::invoke_result_t<pred_type, size_type>, bool>,
    size_type>
exponential_search(size_type range, pred_type pred) {
  size_type step(1);
  while (step < range && pred(step)) step <<= 1;
  if (range < step) step = range;
  return binary_search(size_type(0), step, pred);
}

/*
 * @fn exponential_search
 * @brief Exponential search on the real number line.
 * @param range Range of search
 * @param eps Error tolerance
 * @param pred Predicate
 * @return The boundary point.
 */
template <class real_type, class pred_type>
std::enable_if_t<
    std::is_convertible_v<std::invoke_result_t<pred_type, real_type>, bool>,
    real_type>
exponential_search(real_type range, const real_type eps, pred_type pred) {
  real_type step(1);
  while (step < range && pred(step)) step += step;
  if (range < step) step = range;
  return binary_search(real_type(0), step, eps, pred);
}

}  // namespace workspace

#endif
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
#line 2 "Library/src/utils/hash.hpp"

#line 8 "Library/src/utils/hash.hpp"

#line 2 "Library/src/utils/sfinae.hpp"

/*
 * @file sfinae.hpp
 * @brief SFINAE
 */

#line 10 "Library/src/utils/sfinae.hpp"
#include <type_traits>

namespace workspace {

template <class type, template <class> class trait>
using enable_if_trait_type = typename std::enable_if<trait<type>::value>::type;

template <class Container>
using element_type = typename std::decay<decltype(
    *std::begin(std::declval<Container&>()))>::type;

template <class T, class = std::nullptr_t>
struct has_begin : std::false_type {};

template <class T>
struct has_begin<T, decltype(std::begin(std::declval<T>()), nullptr)>
    : std::true_type {};

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

#ifdef __SIZEOF_INT128__
template <> struct is_integral_ext<__int128_t> : std::true_type {};
template <> struct is_integral_ext<__uint128_t> : std::true_type {};
#endif

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

#ifdef __SIZEOF_INT128__
template <typename T>
struct multiplicable_uint<T, typename std::enable_if<(4 < sizeof(T))>::type> {
  using type = __uint128_t;
};
#endif

}  // namespace workspace
#line 10 "Library/src/utils/hash.hpp"
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
#line 2 "Library/src/utils/io/istream.hpp"

/*
 * @file stream.hpp
 * @brief Input Stream
 */

#include <cxxabi.h>

#line 13 "Library/src/utils/io/istream.hpp"

#line 15 "Library/src/utils/io/istream.hpp"

namespace workspace {

/*
 * @class istream
 * @brief A wrapper class for std::istream.
 */
class istream : public std::istream {
  template <class Tp, typename = std::nullptr_t> struct helper {
    helper(std::istream &is, Tp &x) {
      if constexpr (has_begin<Tp>::value)
        for (auto &&e : x)
          helper<typename std::decay<decltype(e)>::type>(is, e);
      else
        static_assert(has_begin<Tp>::value, "istream unsupported type.");
    }
  };

  template <class Tp>
  struct helper<
      Tp,
      decltype(std::declval<std::decay<decltype(
                   std::declval<std::istream &>() >> std::declval<Tp &>())>>(),
               nullptr)> {
    helper(std::istream &is, Tp &x) { is >> x; }
  };

  template <class T1, class T2> struct helper<std::pair<T1, T2>> {
    helper(std::istream &is, std::pair<T1, T2> &x) {
      helper<T1>(is, x.first), helper<T2>(is, x.second);
    }
  };

  template <class... Tps> struct helper<std::tuple<Tps...>> {
    helper(std::istream &is, std::tuple<Tps...> &x) { iterate(is, x); }

   private:
    template <class Tp, size_t N = 0> void iterate(std::istream &is, Tp &x) {
      if constexpr (N == std::tuple_size<Tp>::value)
        return;
      else
        helper<typename std::tuple_element<N, Tp>::type>(is, std::get<N>(x)),
            iterate<Tp, N + 1>(is, x);
    }
  };

 public:
  template <typename Tp> istream &operator>>(Tp &x) {
    helper<Tp>(*this, x);
    if (std::istream::fail()) {
      static auto once = atexit([] {
        std::cerr << "\n\033[43m\033[30mwarning: failed to read \'"
                  << abi::__cxa_demangle(typeid(Tp).name(), 0, 0, 0)
                  << "\'.\033[0m\n\n";
      });
      assert(!once);
    }
    return *this;
  }
};

namespace internal {
auto *const cin_ptr = (istream *)&std::cin;
}
auto &cin = *internal::cin_ptr;

}  // namespace workspace
#line 2 "Library/src/utils/io/ostream.hpp"

/*
 * @file ostream.hpp
 * @brief Output Stream
 */

#line 10 "Library/src/utils/io/ostream.hpp"

namespace workspace {

template <class T, class U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p) {
  return os << p.first << ' ' << p.second;
}
template <class tuple_t, size_t index> struct tuple_os {
  static std::ostream &apply(std::ostream &os, const tuple_t &t) {
    tuple_os<tuple_t, index - 1>::apply(os, t);
    return os << ' ' << std::get<index>(t);
  }
};
template <class tuple_t> struct tuple_os<tuple_t, 0> {
  static std::ostream &apply(std::ostream &os, const tuple_t &t) {
    return os << std::get<0>(t);
  }
};
template <class tuple_t> struct tuple_os<tuple_t, SIZE_MAX> {
  static std::ostream &apply(std::ostream &os, const tuple_t &t) { return os; }
};

template <class... T>
std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &t) {
  return tuple_os<std::tuple<T...>,
                  std::tuple_size<std::tuple<T...>>::value - 1>::apply(os, t);
}

template <class Container,
          typename = decltype(std::begin(std::declval<Container>()))>
typename std::enable_if<
    !std::is_same<typename std::decay<Container>::type, std::string>::value &&
        !std::is_same<typename std::decay<Container>::type, char *>::value,
    std::ostream &>::type
operator<<(std::ostream &os, const Container &cont) {
  bool head = true;
  for (auto &&e : cont) head ? head = 0 : (os << ' ', 0), os << e;
  return os;
}

}  // namespace workspace
#line 3 "Library/src/utils/io/read.hpp"
namespace workspace {

namespace internal {
struct cast_read {
  template <class T> operator T() const {
    T value;
    workspace::cin >> value;
    return value;
  }
};
}  // namespace internal

/*
 * @fn read
 * @tparam Tp The type of input.
 * @brief Read from stdin.
 */
template <class Tp = void> auto read() {
  typename std::remove_const<Tp>::type value;
  cin >> value;
  return value;
}

/*
 * @fn read
 * @brief Read from stdin on type casting.
 */
template <> auto read<void>() { return internal::cast_read(); }

}  // namespace workspace
#line 2 "Library/src/utils/io/setup.hpp"

/*
 * @file setup.hpp
 * @brief I/O Setup
 */

#line 10 "Library/src/utils/io/setup.hpp"

namespace workspace {

/*
 * @fn io_setup
 * @brief Setup I/O.
 * @param precision Standard output precision
 */
void io_setup(int precision) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout << std::fixed << std::setprecision(precision);

#ifdef _buffer_check
  atexit([] {
    char bufc;
    if (std::cin >> bufc)
      std::cerr << "\n\033[43m\033[30mwarning: buffer not empty.\033[0m\n\n";
  });
#endif
}

}  // namespace workspace
#line 2 "Library/src/utils/iterator/category.hpp"

/*
 * @file category.hpp
 * @brief Iterator Category
 */

#line 10 "Library/src/utils/iterator/category.hpp"

namespace workspace {

/*
 * @tparam Tuple Tuple of iterator types
 */
template <class Tuple, size_t N = std::tuple_size<Tuple>::value - 1>
struct common_iterator_category {
  using type = typename std::common_type<
      typename common_iterator_category<Tuple, N - 1>::type,
      typename std::iterator_traits<typename std::tuple_element<
          N, Tuple>::type>::iterator_category>::type;
};

template <class Tuple> struct common_iterator_category<Tuple, 0> {
  using type = typename std::iterator_traits<
      typename std::tuple_element<0, Tuple>::type>::iterator_category;
};

}  // namespace workspace
#line 2 "Library/src/utils/iterator/reverse.hpp"

/*
 * @file reverse_iterator.hpp
 * @brief Reverse Iterator
 */

#if __cplusplus >= 201703L

#include <iterator>
#include <optional>

namespace workspace {

/*
 * @class reverse_iterator
 * @brief Wrapper class for `std::reverse_iterator`.
 * @see http://gcc.gnu.org/PR51823
 */
template <class Iterator>
class reverse_iterator : public std::reverse_iterator<Iterator> {
  using base_std = std::reverse_iterator<Iterator>;
  std::optional<typename base_std::value_type> deref;

 public:
  using base_std::reverse_iterator;

  constexpr typename base_std::reference operator*() noexcept {
    if (!deref) {
      Iterator tmp = base_std::current;
      deref = *--tmp;
    }
    return deref.value();
  }

  constexpr reverse_iterator &operator++() noexcept {
    base_std::operator++();
    deref.reset();
    return *this;
  }
  constexpr reverse_iterator &operator--() noexcept {
    base_std::operator++();
    deref.reset();
    return *this;
  }
  constexpr reverse_iterator operator++(int) noexcept {
    base_std::operator++();
    deref.reset();
    return *this;
  }
  constexpr reverse_iterator operator--(int) noexcept {
    base_std::operator++();
    deref.reset();
    return *this;
  }
};

}  // namespace workspace

#endif
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
#line 2 "Library/src/utils/py-like/enumerate.hpp"

/*
 * @file enumerate.hpp
 * @brief Enumerate
 */

#line 2 "Library/src/utils/py-like/range.hpp"

/*
 * @file range.hpp
 * @brief Range
 */

#line 9 "Library/src/utils/py-like/range.hpp"

#line 2 "Library/src/utils/py-like/reversed.hpp"

/*
 * @file reversed.hpp
 * @brief Reversed
 */

#include <initializer_list>
#line 10 "Library/src/utils/py-like/reversed.hpp"

namespace workspace {

template <class Container> class reversal {
  Container cont;

 public:
  constexpr reversal(Container &&cont) : cont(cont) {}

  constexpr auto begin() { return std::rbegin(cont); }
  constexpr auto end() { return std::rend(cont); }
};

template <class Container> constexpr auto reversed(Container &&cont) noexcept {
  return reversal<Container>{std::forward<Container>(cont)};
}

template <class Tp>
constexpr auto reversed(std::initializer_list<Tp> &&cont) noexcept {
  return reversal<std::initializer_list<Tp>>{
      std::forward<std::initializer_list<Tp>>(cont)};
}

}  // namespace workspace
#line 12 "Library/src/utils/py-like/range.hpp"

#if __cplusplus >= 201703L

namespace workspace {

template <class Index> class range {
  Index first, last;

 public:
  class iterator {
    Index current;

   public:
    using difference_type = std::ptrdiff_t;
    using value_type = Index;
    using reference = typename std::add_const<Index>::type &;
    using pointer = iterator;
    using iterator_category = std::bidirectional_iterator_tag;

    constexpr iterator(Index const &__i = Index()) noexcept : current(__i) {}

    constexpr bool operator==(iterator const &rhs) const noexcept {
      return current == rhs.current;
    }
    constexpr bool operator!=(iterator const &rhs) const noexcept {
      return current != rhs.current;
    }

    constexpr iterator &operator++() noexcept {
      ++current;
      return *this;
    }
    constexpr iterator &operator--() noexcept {
      --current;
      return *this;
    }

    constexpr reference operator*() const noexcept { return current; }
  };

  constexpr range(Index first, Index last) noexcept
      : first(first), last(last) {}
  constexpr range(Index last) noexcept : first(), last(last) {}

  constexpr iterator begin() const noexcept { return iterator{first}; }
  constexpr iterator end() const noexcept { return iterator{last}; }

  constexpr reverse_iterator<iterator> rbegin() const noexcept {
    return reverse_iterator<iterator>(end());
  }
  constexpr reverse_iterator<iterator> rend() const noexcept {
    return reverse_iterator<iterator>(begin());
  }
};

template <class... Args> constexpr auto rrange(Args &&... args) noexcept {
  return reversal(range(std::forward<Args>(args)...));
}

}  // namespace workspace

#endif
#line 2 "Library/src/utils/py-like/zip.hpp"

/*
 * @file zip.hpp
 * @brief Zip
 */

#line 11 "Library/src/utils/py-like/zip.hpp"

#line 14 "Library/src/utils/py-like/zip.hpp"

#if __cplusplus >= 201703L

namespace workspace {

template <class> struct zipped_iterator;

template <class...> struct zipped_iterator_tuple;

template <class... Args> class zipped {
  using ref_tuple = std::tuple<Args...>;
  ref_tuple args;

  template <size_t N = 0> constexpr auto begin_cat() const noexcept {
    if constexpr (N != std::tuple_size<ref_tuple>::value) {
      return std::tuple_cat(std::tuple(std::begin(std::get<N>(args))),
                            begin_cat<N + 1>());
    } else
      return std::tuple<>();
  }

  template <size_t N = 0> constexpr auto end_cat() const noexcept {
    if constexpr (N != std::tuple_size<ref_tuple>::value) {
      return std::tuple_cat(std::tuple(std::end(std::get<N>(args))),
                            end_cat<N + 1>());
    } else
      return std::tuple<>();
  }

 public:
  constexpr zipped(Args &&... args) noexcept : args(args...) {}

  class iterator {
    using base_tuple = typename zipped_iterator_tuple<Args...>::type;

   public:
    using iterator_category =
        typename common_iterator_category<base_tuple>::type;
    using difference_type = std::ptrdiff_t;
    using value_type = zipped_iterator<base_tuple>;
    using reference = zipped_iterator<base_tuple> &;
    using pointer = iterator;

   protected:
    value_type current;

    template <size_t N = 0>
    constexpr bool equal(const iterator &rhs) const noexcept {
      if constexpr (N != std::tuple_size<base_tuple>::value) {
        return std::get<N>(current) == std::get<N>(rhs.current) ||
               equal<N + 1>(rhs);
      } else
        return false;
    }

    template <size_t N = 0> constexpr void increment() noexcept {
      if constexpr (N != std::tuple_size<base_tuple>::value) {
        ++std::get<N>(current);
        increment<N + 1>();
      }
    }

    template <size_t N = 0> constexpr void decrement() noexcept {
      if constexpr (N != std::tuple_size<base_tuple>::value) {
        --std::get<N>(current);
        decrement<N + 1>();
      }
    }

   public:
    constexpr iterator() noexcept = default;
    constexpr iterator(base_tuple const &current) noexcept : current(current) {}

    constexpr bool operator==(const iterator &rhs) const noexcept {
      return equal(rhs);
    }
    constexpr bool operator!=(const iterator &rhs) const noexcept {
      return !equal(rhs);
    }

    constexpr iterator &operator++() noexcept {
      increment();
      return *this;
    }
    constexpr iterator &operator--() noexcept {
      decrement();
      return *this;
    }

    constexpr reference operator*() noexcept { return current; }
  };

  constexpr iterator begin() const noexcept { return iterator{begin_cat()}; }
  constexpr iterator end() const noexcept { return iterator{end_cat()}; }

  constexpr reverse_iterator<iterator> rbegin() const noexcept {
    return reverse_iterator<iterator>{end()};
  }
  constexpr reverse_iterator<iterator> rend() const noexcept {
    return reverse_iterator<iterator>{begin()};
  }
};

template <class Tp, class... Args> struct zipped_iterator_tuple<Tp, Args...> {
  using type = decltype(std::tuple_cat(
      std::declval<std::tuple<decltype(std::begin(std::declval<Tp>()))>>(),
      std::declval<typename zipped_iterator_tuple<Args...>::type>()));
};

template <> struct zipped_iterator_tuple<> { using type = std::tuple<>; };

template <class Iter_tuple> struct zipped_iterator : Iter_tuple {
  constexpr zipped_iterator(Iter_tuple const &__t) noexcept
      : Iter_tuple::tuple(__t) {}

  template <size_t N>
  friend constexpr auto &get(zipped_iterator<Iter_tuple> const &__z) noexcept {
    return *std::get<N>(__z);
  }

  template <size_t N>
  friend constexpr auto get(zipped_iterator<Iter_tuple> const &&__z) noexcept {
    return std::move(*std::get<N>(__z));
  }
};

}  // namespace workspace

namespace std {

template <size_t N, class Iter_tuple>
struct tuple_element<N, workspace::zipped_iterator<Iter_tuple>> {
  using type = typename remove_reference<typename iterator_traits<
      typename tuple_element<N, Iter_tuple>::type>::reference>::type;
};

template <class Iter_tuple>
struct tuple_size<workspace::zipped_iterator<Iter_tuple>>
    : tuple_size<Iter_tuple> {};

}  // namespace std

namespace workspace {

template <class... Args> constexpr auto zip(Args &&... args) noexcept {
  return zipped<Args...>(std::forward<Args>(args)...);
}

template <class... Args>
constexpr auto zip(std::initializer_list<Args> const &... args) noexcept {
  return zipped<std::vector<Args>...>(args...);
}

}  // namespace workspace

#endif
#line 10 "Library/src/utils/py-like/enumerate.hpp"

#if __cplusplus >= 201703L

namespace workspace {

constexpr size_t min_size() noexcept { return SIZE_MAX; }

template <class Container, class... Args>
constexpr size_t min_size(Container const &cont, Args &&... args) noexcept {
  return std::min(std::size(cont), min_size(std::forward<Args>(args)...));
}

template <class... Args> constexpr auto enumerate(Args &&... args) noexcept {
  return zip(range(min_size(args...)), std::forward<Args>(args)...);
}

template <class... Args>
constexpr auto enumerate(std::initializer_list<Args> const &... args) noexcept {
  return zip(range(min_size(args...)), std::vector(args)...);
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
#line 13 "codeforces-workspace/contest/1450/f/f.cpp"

int main() {
  using namespace workspace;

  io_setup(15);

  //* given
  std::cin >> case_info.total, std::cin.ignore();  //*/

  /* unspecified
  case_info.total = -1; //*/

  case_info.iterate();
}

namespace workspace {

void main() {
  // start here!
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> cnt(n);
  for (auto &&e : a) {
    cin >> e;
    --e;
    cnt[e] += 2;
  }
  auto arx = max_element(begin(cnt), end(cnt));
  if (*arx > n + 1) {
    cout << -1 << endl;
    return;
  }

  for (auto i = 1; i < n; ++i) {
    if (a[i - 1] != a[i]) {
      cnt[a[i - 1]]--;
      cnt[a[i]]--;
    }
  }
  arx = max_element(begin(cnt), end(cnt));

  auto tot = accumulate(begin(cnt), end(cnt), 0);
  auto ans = max(*arx, tot - *arx);
  if (*arx > tot - *arx) {
    ans -= 2;
  } else {
    ans = (tot + 1) / 2 - 1;
  }
  cout << ans << endl;
}

}  // namespace workspace