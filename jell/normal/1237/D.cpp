#line 1 "atcoder-workspace/n.cc"
/**
 * @file template.cpp
 * @brief Template
 */

// #undef _GLIBCXX_DEBUG
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
#else
#warning 128bit integer is not available.
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

#line 1 "Library/lib/bit"



#line 5 "Library/lib/bit"
#include <type_traits>

namespace std {

template <typename _Tp> constexpr _Tp __rotl(_Tp __x, int __s) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  const int __r = __s % _Nd;
  if (__r == 0)
    return __x;
  else if (__r > 0)
    return (__x << __r) | (__x >> ((_Nd - __r) % _Nd));
  else
    return (__x >> -__r) | (__x << ((_Nd + __r) % _Nd));  // rotr(x, -r)
}

template <typename _Tp> constexpr _Tp __rotr(_Tp __x, int __s) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  const int __r = __s % _Nd;
  if (__r == 0)
    return __x;
  else if (__r > 0)
    return (__x >> __r) | (__x << ((_Nd - __r) % _Nd));
  else
    return (__x << -__r) | (__x >> ((_Nd + __r) % _Nd));  // rotl(x, -r)
}

template <typename _Tp> constexpr int __countl_zero(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return _Nd;

  constexpr auto _Nd_ull = numeric_limits<unsigned long long>::digits;
  constexpr auto _Nd_ul = numeric_limits<unsigned long>::digits;
  constexpr auto _Nd_u = numeric_limits<unsigned>::digits;

  if _GLIBCXX17_CONSTEXPR (_Nd <= _Nd_u) {
    constexpr int __diff = _Nd_u - _Nd;
    return __builtin_clz(__x) - __diff;
  } else if _GLIBCXX17_CONSTEXPR (_Nd <= _Nd_ul) {
    constexpr int __diff = _Nd_ul - _Nd;
    return __builtin_clzl(__x) - __diff;
  } else if _GLIBCXX17_CONSTEXPR (_Nd <= _Nd_ull) {
    constexpr int __diff = _Nd_ull - _Nd;
    return __builtin_clzll(__x) - __diff;
  } else  // (_Nd > _Nd_ull)
  {
    static_assert(_Nd <= (2 * _Nd_ull),
                  "Maximum supported integer size is 128-bit");

    unsigned long long __high = __x >> _Nd_ull;
    if (__high != 0) {
      constexpr int __diff = (2 * _Nd_ull) - _Nd;
      return __builtin_clzll(__high) - __diff;
    }
    constexpr auto __max_ull = numeric_limits<unsigned long long>::max();
    unsigned long long __low = __x & __max_ull;
    return (_Nd - _Nd_ull) + __builtin_clzll(__low);
  }
}

template <typename _Tp> constexpr int __countl_one(_Tp __x) noexcept {
  if (__x == numeric_limits<_Tp>::max()) return numeric_limits<_Tp>::digits;
  return __countl_zero<_Tp>((_Tp)~__x);
}

template <typename _Tp> constexpr int __countr_zero(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return _Nd;

  constexpr auto _Nd_ull = numeric_limits<unsigned long long>::digits;
  constexpr auto _Nd_ul = numeric_limits<unsigned long>::digits;
  constexpr auto _Nd_u = numeric_limits<unsigned>::digits;

  if _GLIBCXX17_CONSTEXPR (_Nd <= _Nd_u)
    return __builtin_ctz(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= _Nd_ul)
    return __builtin_ctzl(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= _Nd_ull)
    return __builtin_ctzll(__x);
  else  // (_Nd > _Nd_ull)
  {
    static_assert(_Nd <= (2 * _Nd_ull),
                  "Maximum supported integer size is 128-bit");

    constexpr auto __max_ull = numeric_limits<unsigned long long>::max();
    unsigned long long __low = __x & __max_ull;
    if (__low != 0) return __builtin_ctzll(__low);
    unsigned long long __high = __x >> _Nd_ull;
    return __builtin_ctzll(__high) + _Nd_ull;
  }
}

template <typename _Tp> constexpr int __countr_one(_Tp __x) noexcept {
  if (__x == numeric_limits<_Tp>::max()) return numeric_limits<_Tp>::digits;
  return __countr_zero((_Tp)~__x);
}

template <typename _Tp> constexpr int __popcount(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return 0;

  constexpr auto _Nd_ull = numeric_limits<unsigned long long>::digits;
  constexpr auto _Nd_ul = numeric_limits<unsigned long>::digits;
  constexpr auto _Nd_u = numeric_limits<unsigned>::digits;

  if _GLIBCXX17_CONSTEXPR (_Nd <= _Nd_u)
    return __builtin_popcount(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= _Nd_ul)
    return __builtin_popcountl(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= _Nd_ull)
    return __builtin_popcountll(__x);
  else  // (_Nd > _Nd_ull)
  {
    static_assert(_Nd <= (2 * _Nd_ull),
                  "Maximum supported integer size is 128-bit");

    constexpr auto __max_ull = numeric_limits<unsigned long long>::max();
    unsigned long long __low = __x & __max_ull;
    unsigned long long __high = __x >> _Nd_ull;
    return __builtin_popcountll(__low) + __builtin_popcountll(__high);
  }
}

template <typename _Tp> constexpr bool __has_single_bit(_Tp __x) noexcept {
  return __popcount(__x) == 1;
}

template <typename _Tp> constexpr _Tp __bit_ceil(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  if (__x == 0 || __x == 1) return 1;
  auto __shift_exponent = _Nd - __countl_zero((_Tp)(__x - 1u));
#ifdef _GLIBCXX_HAVE_BUILTIN_IS_CONSTANT_EVALUATED
  if (!__builtin_is_constant_evaluated()) {
    __glibcxx_assert(__shift_exponent != numeric_limits<_Tp>::digits);
  }
#endif
  using __promoted_type = decltype(__x << 1);
  if _GLIBCXX17_CONSTEXPR (!is_same<__promoted_type, _Tp>::value) {
    const int __extra_exp = sizeof(__promoted_type) / sizeof(_Tp) / 2;
    __shift_exponent |= (__shift_exponent & _Nd) << __extra_exp;
  }
  return (_Tp)1u << __shift_exponent;
}

template <typename _Tp> constexpr _Tp __bit_floor(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  if (__x == 0) return 0;
  return (_Tp)1u << (_Nd - __countl_zero((_Tp)(__x >> 1)));
}

template <typename _Tp> constexpr _Tp __bit_width(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  return _Nd - __countl_zero(__x);
}

}  // namespace std


#line 9 "Library/lib/cxx20"

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
  __cont.erase(remove_if(__cont.begin(), __cont.end(), __pred), __cont.end());
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
  __cont.erase(remove(__cont.begin(), __cont.end(), __value), __cont.end());
  return __osz - __cont.size();
}

}  // namespace std

#endif
#line 2 "Library/lib/direct"

/*
 * @file direct
 * @brief Pragma Directive
 */

#ifdef ONLINE_JUDGE

#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2")
#pragma GCC optimize("unroll-loops")

#endif
#line 2 "Library/src/opt/binary_search.hpp"

/*
 * @file binary_search.hpp
 * @brief Binary Search
 */

#line 12 "Library/src/opt/binary_search.hpp"

namespace workspace {

/*
 * @fn binary_search
 * @brief binary search on a discrete range.
 * @param ok pred(ok) is true
 * @param ng pred(ng) is false
 * @param pred the predicate
 * @return the closest point to (ng) where pred is true
 */
template <class Iter, class Pred>
typename std::enable_if<
    std::is_convertible<decltype(std::declval<Pred>()(std::declval<Iter>())),
                        bool>::value,
    Iter>::type
binary_search(Iter ok, Iter ng, Pred pred) {
  assert(ok != ng);
  typename std::make_signed<decltype(ng - ok)>::type dist(ng - ok);
  while (1 < dist || dist < -1) {
    const Iter mid(ok + dist / 2);
    if (pred(mid))
      ok = mid, dist -= dist / 2;
    else
      ng = mid, dist /= 2;
  }
  return ok;
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
template <class Real, class Pred>
typename std::enable_if<
    std::is_convertible<decltype(std::declval<Pred>()(std::declval<Real>())),
                        bool>::value,
    Real>::type
binary_search(Real ok, Real ng, const Real eps, Pred pred) {
  assert(ok != ng);
  for (auto loops = 0; loops != std::numeric_limits<Real>::digits &&
                       (ok + eps < ng || ng + eps < ok);
       ++loops) {
    const Real mid{(ok + ng) / 2};
    (pred(mid) ? ok : ng) = mid;
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
template <class Array,
          class Iter = typename std::decay<
              decltype(std::get<0>(std::declval<Array>()[0]))>::type,
          class Pred>
typename std::enable_if<
    std::is_convertible<
        decltype(std::declval<Pred>()(std::declval<std::vector<Iter>>())[0]),
        bool>::value,
    std::vector<Iter>>::type
parallel_binary_search(Array ends, Pred pred) {
  std::vector<Iter> mids(std::size(ends));
  for (;;) {
    bool all_found = true;
    for (size_t i{}; i != std::size(ends); ++i) {
      const Iter &ok = std::get<0>(ends[i]);
      const Iter &ng = std::get<1>(ends[i]);
      const Iter mid(
          ok + typename std::make_signed<decltype(ng - ok)>::type(ng - ok) / 2);
      if (mids[i] != mid) {
        all_found = false;
        mids[i] = mid;
      }
    }
    if (all_found) break;
    const auto res = pred(mids);
    for (size_t i{}; i != std::size(ends); ++i) {
      (res[i] ? std::get<0>(ends[i]) : std::get<1>(ends[i])) = mids[i];
    }
  }
  return mids;
}

/*
 * @fn parallel_binary_search
 * @brief parallel binary search on the real number line.
 * @param ends a vector of pairs; pred(first) is true, pred(second) is false
 * @param eps the error tolerance
 * @param pred the predicate
 * @return the boundary points
 */
template <class Array,
          class Real = typename std::decay<
              decltype(std::get<0>(std::declval<Array>()[0]))>::type,
          class Pred>
typename std::enable_if<
    std::is_convertible<
        decltype(std::declval<Pred>()(std::declval<std::vector<Real>>())[0]),
        bool>::value,
    std::vector<Real>>::type
parallel_binary_search(Array ends, const Real eps, Pred pred) {
  std::vector<Real> mids(std::size(ends));
  for (auto loops = 0; loops != std::numeric_limits<Real>::digits; ++loops) {
    bool all_found = true;
    for (size_t i{}; i != std::size(ends); ++i) {
      const Real ok = std::get<0>(ends[i]);
      const Real ng = std::get<1>(ends[i]);
      if (ok + eps < ng || ng + eps < ok) {
        all_found = false;
        mids[i] = (ok + ng) / 2;
      }
    }
    if (all_found) break;
    const auto res = pred(mids);
    for (size_t i{}; i != std::size(ends); ++i) {
      (res[i] ? std::get<0>(ends[i]) : std::get<1>(ends[i])) = mids[i];
    }
  }
  return mids;
}

}  // namespace workspace
#line 2 "Library/src/opt/exponential_search.hpp"

/*
 * @file exponential_search.hpp
 * @brief Exponential Search
 */

#line 9 "Library/src/opt/exponential_search.hpp"

namespace workspace {

/*
 * @fn exponential_search
 * @brief Exponential search on a discrete range.
 * @param range Range of search, exclusive
 * @param pred Predicate
 * @return Minimum non-negative integer where pred is false.
 */
template <class Index, class Pred>
typename std::enable_if<
    std::is_convertible<decltype(std::declval<Pred>()(std::declval<Index>())),
                        bool>::value,
    Index>::type
exponential_search(Index range, Pred pred) {
  Index step(1);
  while (step < range && pred(step)) step <<= 1;
  if (range < step) step = range;
  return binary_search(Index(0), step, pred);
}

/*
 * @fn exponential_search
 * @brief Exponential search on the real number line.
 * @param range Range of search
 * @param eps Error tolerance
 * @param pred Predicate
 * @return Boundary point.
 */
template <class Real, class Pred>
typename std::enable_if<
    std::is_convertible<decltype(std::declval<Pred>()(std::declval<Real>())),
                        bool>::value,
    Real>::type
exponential_search(Real range, Real const &eps, Pred pred) {
  Real step(1);
  while (step < range && pred(step)) step += step;
  if (range < step) step = range;
  return binary_search(Real(0), step, eps, pred);
}

}  // namespace workspace
#line 2 "Library/src/opt/trinary_search.hpp"

/*
 * @file trinary_search.hpp
 * @brief Trinary Search
 */

#line 10 "Library/src/opt/trinary_search.hpp"

namespace workspace {

/*
 * @brief Trinary search on discrete range.
 * @param first Left end, inclusive
 * @param last Right end, exclusive
 * @param comp Compare function
 * @return Local minimal point.
 */
template <class Iter, class Comp>
typename std::enable_if<
    std::is_convertible<decltype(std::declval<Comp>()(std::declval<Iter>(),
                                                      std::declval<Iter>())),
                        bool>::value,
    Iter>::type
trinary_search(Iter first, Iter last, Comp comp) {
  assert(first < last);
  typename std::make_signed<decltype(last - first)>::type dist(last - first);
  while (2 < dist) {
    Iter left(first + dist / 3), right(first + dist * 2 / 3);
    if (comp(left, right))
      last = right, dist = (dist + dist) / 3;
    else
      first = left, dist -= dist / 3;
  }
  if (1 < dist && comp(first + 1, first)) ++first;
  return first;
}

/*
 * @brief Trinary search on discrete range.
 * @param first Left end, inclusive
 * @param last Right end, exclusive
 * @param func Function
 * @return Local minimal point.
 */
template <class Iter, class Func>
typename std::enable_if<
    std::is_same<decltype(std::declval<Func>()(std::declval<Iter>()), nullptr),
                 std::nullptr_t>::value,
    Iter>::type
trinary_search(Iter const &first, Iter const &last, Func func) {
  return trinary_search(first, last, [&](Iter const &__i, Iter const &__j) {
    return func(__i) < func(__j);
  });
}

/*
 * @brief Trinary search on the real number line.
 * @param first Left end
 * @param last Right end
 * @param eps Error tolerance
 * @param comp Compare function
 * @return Local minimal point.
 */
template <class Real, class Comp>
typename std::enable_if<
    std::is_convertible<decltype(std::declval<Comp>()(std::declval<Real>(),
                                                      std::declval<Real>())),
                        bool>::value,
    Real>::type
trinary_search(Real first, Real last, Real const &eps, Comp comp) {
  assert(first < last);
  while (eps < last - first) {
    Real left{(first * 2 + last) / 3}, right{(first + last * 2) / 3};
    if (comp(left, right))
      last = right;
    else
      first = left;
  }
  return first;
}

/*
 * @brief Trinary search on the real number line.
 * @param first Left end
 * @param last Right end
 * @param eps Error tolerance
 * @param func Function
 * @return Local minimal point.
 */
template <class Real, class Func>
typename std::enable_if<
    std::is_same<decltype(std::declval<Func>()(std::declval<Real>()), nullptr),
                 std::nullptr_t>::value,
    Real>::type
trinary_search(Real const &first, Real const &last, Real const &eps,
               Func func) {
  return trinary_search(
      first, last, eps,
      [&](Real const &__i, Real const &__j) { return func(__i) < func(__j); });
}

}  // namespace workspace
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

  void read() { (std::cin >> total).ignore(); }

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

#line 11 "Library/src/utils/sfinae.hpp"

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
#line 15 "atcoder-workspace/n.cc"

int main() {
  using namespace workspace;

  io_setup(15);

  /* given
  case_info.read();  //*/

  /* unspecified
  case_info.total = -1; //*/

  return case_info.iterate();
}

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
#line 2 "Library/src/data_structure/segment_tree/basic.hpp"

/**
 * @file basic.hpp
 * @brief Segment Tree
 */

#line 11 "Library/src/data_structure/segment_tree/basic.hpp"

#line 2 "Library/src/algebra/system/monoid.hpp"

/*
 * @file monoid.hpp
 * @brief Monoid
 */

#line 9 "Library/src/algebra/system/monoid.hpp"

namespace workspace {

template <class T, class E = T> struct min_monoid {
  using value_type = T;
  static T min, max;
  T value;
  min_monoid() : value(max) {}
  min_monoid(const T &value) : value(value) {}
  operator T() const { return value; }
  min_monoid operator+(const min_monoid &rhs) const {
    return value < rhs.value ? *this : rhs;
  }
  min_monoid operator*(const E &rhs) const;
};

template <class T, class E>
T min_monoid<T, E>::min = std::numeric_limits<T>::min() / 2;
template <class T, class E>
T min_monoid<T, E>::max = std::numeric_limits<T>::max() / 2;

template <class T, class E = T> struct max_monoid : min_monoid<T, E> {
  using base = min_monoid<T, E>;
  using base::min_monoid;
  max_monoid() : base(base::min) {}
  max_monoid operator+(const max_monoid &rhs) const {
    return !(base::value < rhs.value) ? *this : rhs;
  }
  max_monoid operator*(const E &rhs) const;
};

}  // namespace workspace
#line 13 "Library/src/data_structure/segment_tree/basic.hpp"

namespace workspace {

/**
 * @tparam Monoid `operator+`
 * @tparam Container_tmpl `operator[]`, `size_type`
 */
template <class Monoid, template <class> class Container_tmpl = std::vector>
class segment_tree {
  static_assert(
      std::is_same<Monoid, decltype(std::declval<const Monoid>() +
                                    std::declval<const Monoid>())>::value,
      "\'Monoid\' has no proper binary \'operator+\'.");

  struct node {
    Monoid value{};
    bool latest{true};
  };

  using container_type = Container_tmpl<node>;

 public:
  using size_type = typename container_type::size_type;

  class iterator {
    segment_tree *__p;
    size_type __i;

   public:
    using difference_type = typename std::make_signed<size_type>::type;
    using value_type = Monoid;
    using reference = Monoid &;
    using pointer = iterator;
    using iterator_category = std::random_access_iterator_tag;

    iterator() = default;
    iterator(segment_tree *__p, size_type __i) : __p(__p), __i(__i) {}

    bool operator==(iterator const &rhs) const {
      return __p == rhs.__p && __i == rhs.__i;
    }
    bool operator!=(iterator const &rhs) const { return !operator==(rhs); }

    bool operator<(iterator const &rhs) const { return __i < rhs.__i; }
    bool operator>(iterator const &rhs) const { return __i > rhs.__i; }
    bool operator<=(iterator const &rhs) const { return __i <= rhs.__i; }
    bool operator>=(iterator const &rhs) const { return __i >= rhs.__i; }

    iterator &operator++() { return ++__i, *this; }
    iterator &operator--() { return --__i, *this; }

    difference_type operator-(iterator const &rhs) const {
      return __i - rhs.__i;
    }

    reference operator*() const { return __p->operator[](__i); }
  };

  using value_type = typename iterator::value_type;
  using reference = typename iterator::reference;

  iterator begin() { return {this, 0}; }
  iterator end() { return {this, size_orig}; }

  auto rbegin() { return std::make_reverse_iterator(end()); }
  auto rend() { return std::make_reverse_iterator(begin()); }

 protected:
  size_type size_orig, height, size_ext;
  container_type data;

  Monoid const &pull(size_type __i) noexcept {
    if (!data[__i].latest)
      data[__i] = {pull(__i << 1) + pull(__i << 1 | 1), true};
    return data[__i].value;
  }

  template <class Pred>
  static constexpr decltype(std::declval<Pred>()(Monoid{})) pass_args(
      Pred pred, Monoid const &_1, size_type _2) {
    return pred(_1);
  }

  template <class Pred>
  static constexpr decltype(std::declval<Pred>()(Monoid{}, size_type{}))
  pass_args(Pred pred, Monoid const &_1, size_type _2) {
    return pred(_1, _2);
  }

  template <class Pred>
  size_type left_partition_subtree(size_type node, Monoid mono, size_type step,
                                   Pred pred) {
    assert(node);
    while (node < size_ext) {
      const Monoid tmp = pull((node <<= 1) | 1) + mono;
      if (pass_args(pred, tmp, ((node | 1) << --step) ^ size_ext))
        mono = tmp;
      else
        ++node;
    }
    return ++node -= size_ext;
  }

  template <class Pred>
  size_type right_partition_subtree(size_type node, Monoid mono, size_type step,
                                    Pred pred) {
    assert(node);
    while (node < size_ext) {
      const Monoid tmp = mono + pull(node <<= 1);
      if (pass_args(pred, tmp, ((node | 1) << --step) ^ size_ext))
        ++node, mono = tmp;
    }
    return (node -= size_ext) < size_orig ? node : size_orig;
  }

 public:
  segment_tree(size_type n = 0)
      : size_orig{n},
        height(n > 1 ? 64 - __builtin_clzll(n - 1) : 0),
        size_ext{size_type{1} << height} {
    if constexpr (std::is_constructible_v<container_type, size_t>)
      data = container_type(size_ext << 1);
  }

  template <class Tp,
            std::enable_if_t<std::is_convertible_v<Tp, Monoid>> * = nullptr>
  segment_tree(size_type n, Tp const &init) : segment_tree(n) {
    for (auto i = begin(); i != end(); ++i) *i = init;
  }

  template <class Iterator,
            std::enable_if_t<std::is_convertible_v<
                typename std::iterator_traits<Iterator>::value_type, Monoid>>
                * = nullptr>
  segment_tree(Iterator __first, Iterator __last)
      : segment_tree(std::distance(__first, __last)) {
    for (auto i = begin(); __first != __last; ++i, ++__first) *i = *__first;
  }

  /**
   * @fn size
   * @return Number of elements.
   */
  size_type size() const { return size_orig; }

  /**
   * @fn operator[]
   * @param __i Index of the element
   * @return Reference to the element.
   */
  reference operator[](size_type __i) {
    assert(__i < size_orig);
    __i |= size_ext;
    for (size_type __j{__i >> 1}; __j && data[__j].latest; __j >>= 1)
      data[__j].latest = false;
    return data[__i].value;
  }

  /**
   * @fn fold
   * @param first Left end, inclusive
   * @param last Right end, exclusive
   * @return Sum of elements in the interval.
   */
  value_type fold(size_type first, size_type last) {
    assert(last <= size_orig);
    Monoid left{}, right{};
    first += size_ext, last += size_ext;
    while (first < last) {
      if (first & 1) left = left + pull(first++);
      if (last & 1) right = pull(--last) + right;
      first >>= 1, last >>= 1;
    }
    return left + right;
  }

  /**
   * @fn fold
   * @return Sum of all elements.
   */
  value_type fold() { return fold(0, size_orig); }

  /**
   * @fn left_partition
   * @brief Binary search for the partition point.
   * @param right Right fixed end of the interval, exclusive
   * @param pred Predicate in the form of either 'bool(Monoid)' or 'bool(Monoid,
   * size_type)'
   * @return Left end of the extremal interval satisfying the condition,
   * inclusive.
   */
  template <class Pred> size_type left_partition(size_type right, Pred pred) {
    assert(right <= size_orig);
    right += size_ext;
    Monoid mono{};
    for (size_type left{size_ext}, step{}; left != right;
         left >>= 1, right >>= 1, ++step) {
      if ((left & 1) != (right & 1)) {
        const Monoid tmp = pull(--right) + mono;
        if (!pass_args(pred, tmp, (right << step) ^ size_ext))
          return left_partition_subtree(right, mono, step, pred);
        mono = tmp;
      }
    }
    return 0;
  }

  /**
   * @fn right_partition
   * @brief Binary search for the partition point.
   * @param left Left fixed end of the interval, inclusive
   * @param pred Predicate in the form of either 'bool(Monoid)' or 'bool(Monoid,
   * size_type)'
   * @return Right end of the extremal interval satisfying the condition,
   * exclusive.
   */
  template <class Pred> size_type right_partition(size_type left, Pred pred) {
    assert(left <= size_orig);
    left += size_ext;
    Monoid mono{};
    for (size_type right{size_ext << 1}, step{}; left != right;
         left >>= 1, right >>= 1, ++step) {
      if ((left & 1) != (right & 1)) {
        const Monoid tmp = mono + pull(left);
        if (!pass_args(pred, tmp, ((left + 1) << step) ^ size_ext))
          return right_partition_subtree(left, mono, step, pred);
        mono = tmp;
        ++left;
      }
    }
    return size_orig;
  }
};

}  // namespace workspace
#line 32 "atcoder-workspace/n.cc"

namespace workspace {

struct mono {
  int val = 1e9;
  mono() {}
  mono(int v) : val(v) {}
  mono operator+(const mono &rhs) const { return val < rhs.val ? *this : rhs; }
};

void main() {
  // start here!

  size_t n;
  cin >> n;
  vector<int> a(n);
  segment_tree<mono> seg(n * 3);
  for (auto i = 0; i < n; ++i) {
    cin >> a[i];
    seg[i] = seg[i + n] = seg[i + n * 2] = {a[i]};
  }
  vector<int> ans(n);
  for (size_t i = n * 3, r = n * 3; i--;) {
    auto pred = [&](const mono &e) -> bool { return e.val * 2 >= a[i % n]; };
    r = min(r, seg.right_partition(i, pred));
    if (i < n) ans[i] = r == n * 3 ? -1 : r - i;
  }
  for (int &e : ans) cout << e << " ";
  cout << "\n";
}

}  // namespace workspace