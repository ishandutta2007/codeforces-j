#pragma region preprocessor
#ifdef LOCAL
//*
    #define _GLIBCXX_DEBUG  // gcc
/*/
    #define _LIBCPP_DEBUG 0 // clang
//*/
    #define __clock__
    // #define __buffer_check__
#else
    #pragma GCC optimize("Ofast")
    // #define __buffer_check__
    // #define NDEBUG
#endif
#define __precision__ 15
#define iostream_untie true
#include <bits/stdc++.h>
#include <ext/rope>
#define __all(v) std::begin(v), std::end(v)
#define __rall(v) std::rbegin(v), std::rend(v)
#define __popcount(n) __builtin_popcountll(n)
#define __clz32(n) __builtin_clz(n)
#define __clz64(n) __builtin_clzll(n)
#define __ctz32(n) __builtin_ctz(n)
#define __ctz64(n) __builtin_ctzll(n)

#ifdef __clock__
    #include "clock.hpp"
#else
    #define build_clock() ((void)0)
    #define set_clock() ((void)0)
    #define get_clock() ((void)0)
#endif

#ifdef LOCAL
    #include "dump.hpp"
    #define mesg(str) std::cerr << "[ " << __LINE__ << " : " << __FUNCTION__ << " ]  " << str << "\n"
#else
    #define dump(...) ((void)0)
    #define mesg(str) ((void)0)
#endif
#pragma endregion // preprocessor

#pragma region std-overload
namespace std
{
    // hash
    template <class T> size_t hash_combine(size_t seed, T const &key) { return seed ^ (hash<T>()(key) + 0x9e3779b9 + (seed << 6) + (seed >> 2)); }
    template <class T, class U> struct hash<pair<T, U>> { size_t operator()(pair<T, U> const &pr) const { return hash_combine(hash_combine(0, pr.first), pr.second); } };
    template <class tuple_t, size_t index = tuple_size<tuple_t>::value - 1> struct tuple_hash_calc { static size_t apply(size_t seed, tuple_t const &t) { return hash_combine(tuple_hash_calc<tuple_t, index - 1>::apply(seed, t), get<index>(t)); } };
    template <class tuple_t> struct tuple_hash_calc<tuple_t, 0> { static size_t apply(size_t seed, tuple_t const &t) { return hash_combine(seed, get<0>(t)); } };
    template <class... T> struct hash<tuple<T...>> { size_t operator()(tuple<T...> const &t) const { return tuple_hash_calc<tuple<T...>>::apply(0, t); } };
    // iostream
    template <class T, class U> istream &operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
    template <class T, class U> ostream &operator<<(ostream &os, const pair<T, U> &p) { return os << p.first << ' ' << p.second; }
    template <class tuple_t, size_t index> struct tupleis { static istream &apply(istream &is, tuple_t &t) { tupleis<tuple_t, index - 1>::apply(is, t); return is >> get<index>(t); } };
    template <class tuple_t> struct tupleis<tuple_t, SIZE_MAX> { static istream &apply(istream &is, tuple_t &t) { return is; } };
    template <class... T> istream &operator>>(istream &is, tuple<T...> &t) { return tupleis<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(is, t); }
    template <> istream &operator>>(istream &is, tuple<> &t) { return is; }
    template <class tuple_t, size_t index> struct tupleos { static ostream &apply(ostream &os, const tuple_t &t) { tupleos<tuple_t, index - 1>::apply(os, t); return os << ' ' << get<index>(t); } };
    template <class tuple_t> struct tupleos<tuple_t, 0> { static ostream &apply(ostream &os, const tuple_t &t) { return os << get<0>(t); } };
    template <class... T> ostream &operator<<(ostream &os, const tuple<T...> &t) { return tupleos<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(os, t); }
    template <> ostream &operator<<(ostream &os, const tuple<> &t) { return os; }
    template <class Container, typename Value = typename Container::value_type, enable_if_t<!is_same<decay_t<Container>, string>::value, nullptr_t> = nullptr>
    istream& operator>>(istream& is, Container &cont) { for(auto&& e : cont) is >> e; return is; }
    template <class Container, typename Value = typename Container::value_type, enable_if_t<!is_same<decay_t<Container>, string>::value, nullptr_t> = nullptr>
    ostream& operator<<(ostream& os, const Container &cont) { bool flag = 1; for(auto&& e : cont) flag ? flag = 0 : (os << ' ', 0), os << e; return os; }
} // namespace std
#pragma endregion // std-overload

#pragma region executive-setting
namespace setting
{
    using namespace std;
    using namespace chrono;
    system_clock::time_point start_time, end_time;
    long long get_elapsed_time() { end_time = system_clock::now(); return duration_cast<milliseconds>(end_time - start_time).count(); }
    void print_elapsed_time() { cerr << "\n----- Exec time : " << get_elapsed_time() << " ms -----\n\n"; }
    void buffer_check() { char bufc; if(cin >> bufc) cerr << "\n\033[1;35mwarning\033[0m: buffer not empty.\n"; }
    struct setupper
    {
        setupper()
        {
            if(iostream_untie) ios::sync_with_stdio(false), cin.tie(nullptr);
            cout << fixed << setprecision(__precision__);
    #ifdef stderr_path
            freopen(stderr_path, "a", stderr);
    #endif
    #ifdef LOCAL
            cerr << fixed << setprecision(__precision__) << boolalpha << "\n----- stderr at LOCAL -----\n\n";
    #endif
    #ifdef __clock__
            start_time = system_clock::now();
            atexit(print_elapsed_time);
    #endif
    #ifdef __buffer_check__
            atexit(buffer_check);
    #endif
        }
    } __setupper; // struct setupper
} // namespace setting
#pragma endregion // executive-setting

#pragma region fucntion-utility
// lambda wrapper for recursive method.
template <class lambda_type>
class make_recursive
{
    lambda_type func;
public:
    make_recursive(lambda_type &&f) : func(std::move(f)) {}
    template <class... Args> auto operator()(Args &&... args) const { return func(*this, std::forward<Args>(args)...); }
};
template <class T, class... types> T read(types... args) noexcept { typename std::remove_const<T>::type obj(args...); std::cin >> obj; return obj; }
// #define input(type, var, ...) type var{read<type>(__VA_ARGS__)}
// substitute y for x if x > y.
template <class T> inline bool chmin(T &x, const T &y) { return x > y ? x = y, true : false; }
// substitute y for x if x < y.
template <class T> inline bool chmax(T &x, const T &y) { return x < y ? x = y, true : false; }
// binary search on discrete range.
template <class iter_type, class pred_type>
iter_type binary(iter_type __ok, iter_type __ng, pred_type pred)
{
    assert(__ok != __ng);
    std::ptrdiff_t dist(__ng - __ok);
    while(std::abs(dist) > 1)
    {
        iter_type mid(__ok + dist / 2);
        if(pred(mid)) __ok = mid, dist -= dist / 2;
        else __ng = mid, dist /= 2;
    }
    return __ok;
}
// binary search on real numbers.
template <class pred_type>
long double binary(long double __ok, long double __ng, const long double eps, pred_type pred)
{
    assert(__ok != __ng);
    while(std::abs(__ok - __ng) > eps)
    {
        long double mid{(__ok + __ng) / 2};
        (pred(mid) ? __ok : __ng) = mid;
    }
    return __ok;
}
// trinary search on discrete range.
template <class iter_type, class comp_type>
iter_type trinary(iter_type __first, iter_type __last, comp_type comp)
{
    assert(__first < __last);
    std::ptrdiff_t dist(__last - __first);
    while(dist > 2)
    {
        iter_type __left(__first + dist / 3), __right = (__first + dist * 2 / 3);
        if(comp(__left, __right)) __last = __right, dist = dist * 2 / 3;
        else __first = __left, dist -= dist / 3;
    }
    if(dist > 1 && comp(next(__first), __first)) ++__first;
    return __first;
}
// trinary search on real numbers.
template <class comp_type>
long double trinary(long double __first, long double __last, const long double eps, comp_type comp)
{
    assert(__first < __last);
    while(__last - __first > eps)
    {
        long double __left{(__first * 2 + __last) / 3}, __right{(__first + __last * 2) / 3};
        if(comp(__left, __right)) __last = __right;
        else __first = __left;
    }
    return __first;
}
// size of array.
template <class A, size_t N> size_t size(A (&array)[N]) { return N; }
// be careful that val is type-sensitive.
template <class T, class A, size_t N> void init(A (&array)[N], const T &val) { std::fill((T*)array, (T*)(array + N), val); }
#pragma endregion // function-utility

#pragma region using-alias
using namespace std;
using i32 = int_least32_t; using i64 = int_least64_t; using u32 = uint_least32_t; using u64 = uint_least64_t;
using p32 = pair<i32, i32>; using p64 = pair<i64, i64>;
template <class T, class Comp = less<T>> using heap = priority_queue<T, vector<T>, Comp>;
template <class T> using hashset = unordered_set<T>;
template <class Key, class Value> using hashmap = unordered_map<Key, Value>;
using namespace __gnu_cxx;
#pragma endregion // using-alias

#pragma region library


#ifndef modint_hpp
#define modint_hpp
#include <cassert>
#include <iostream>

template <int mod>
class modint
{
    int val;
public:
    static constexpr modint identity() noexcept { return 1; }
    constexpr modint() noexcept : val(0) {}
    template <class int_type, std::enable_if_t<std::is_integral<int_type>::value, std::nullptr_t> = nullptr>
    constexpr modint(int_type _val) noexcept : val((_val %= mod) < 0 ? mod + _val : _val) {}
    constexpr long long value() const noexcept { return val; }
    constexpr modint operator++(int) noexcept { modint t = *this; return ++val, t; }
    constexpr modint operator--(int) noexcept { modint t = *this; return --val, t; }
    constexpr modint &operator++() noexcept { return ++val, *this; }
    constexpr modint &operator--() noexcept { return --val, *this; }
    constexpr modint operator-() const noexcept { return modint(-val); }
    constexpr modint &operator+=(const modint &rhs) noexcept { return (val += rhs.val) < mod ? 0 : val -= mod, *this; }
    constexpr modint &operator-=(const modint &rhs) noexcept { return (val += mod - rhs.val) < mod ? 0 : val -= mod, *this; }
    constexpr modint &operator*=(const modint &rhs) noexcept { return val = (long long)val * rhs.val % mod, *this; }
    constexpr modint &operator/=(const modint &rhs) noexcept { return *this *= inverse(rhs); }
    constexpr modint operator+(const modint &rhs) const noexcept { return modint(*this) += rhs; }
    constexpr modint operator-(const modint &rhs) const noexcept { return modint(*this) -= rhs; }
    constexpr modint operator*(const modint &rhs) const noexcept { return modint(*this) *= rhs; }
    constexpr modint operator/(const modint &rhs) const noexcept { return modint(*this) /= rhs; }
    constexpr bool operator==(const modint &rhs) const noexcept { return val == rhs.val; }
    constexpr bool operator!=(const modint &rhs) const noexcept { return val != rhs.val; }
    constexpr bool operator!() const noexcept { return !val; }
    friend constexpr modint operator+(long long lhs, modint rhs) noexcept { return modint(lhs) + rhs; }
    friend constexpr modint operator-(long long lhs, modint rhs) noexcept { return modint(lhs) - rhs; }
    friend constexpr modint operator*(long long lhs, modint rhs) noexcept { return modint(lhs) * rhs; }
    friend constexpr modint operator/(long long lhs, modint rhs) noexcept { return modint(lhs) / rhs; }
    static constexpr modint inverse(const modint &rhs) noexcept
    {
        assert(rhs != 0);
        int a{mod}, b{rhs.val}, u{}, v{1}, t{};
        while(b) t = a / b, a ^= b ^= (a -= t * b) ^= b, u ^= v ^= (u -= t * v) ^= v;
        return {u};
    }
    static constexpr modint pow(modint rhs, long long e) noexcept
    {
        if(e < 0) e = e % (mod - 1) + mod - 1;
        modint res{1};
        while(e) { if(e & 1) res *= rhs; rhs *= rhs, e >>= 1; }
        return res;
    }
    friend std::ostream &operator<<(std::ostream &os, const modint &rhs) noexcept { return os << rhs.val; }
    friend std::istream &operator>>(std::istream &is, modint &rhs) noexcept { long long val; rhs = {(is >> val, val)}; return is; }
}; // class modint

template <>
class modint<2>
{
    bool val;
public:
    static constexpr modint identity() noexcept { return 1; }
    constexpr modint() noexcept : val(false) {}
    template <class int_type, std::enable_if_t<std::is_integral<int_type>::value, std::nullptr_t> = nullptr>
    constexpr modint(int_type _val) noexcept : val(_val & 1) {}
    constexpr operator bool() const noexcept { return val; }
    constexpr bool value() const noexcept { return val; }
    constexpr modint &operator+=(const modint &rhs) noexcept { return val ^= rhs.val, *this; }
    constexpr modint &operator-=(const modint &rhs) noexcept { return val ^= rhs.val, *this; }
    constexpr modint &operator*=(const modint &rhs) noexcept { return val &= rhs.val, *this; }
    constexpr modint &operator/=(const modint &rhs) noexcept { assert(rhs.val); return *this; }
    constexpr modint operator!() const noexcept { return !val; }
    constexpr modint operator-() const noexcept { return *this; }
    constexpr modint operator+(const modint &rhs) const noexcept { return val != rhs.val; }
    constexpr modint operator-(const modint &rhs) const noexcept { return val != rhs.val; }
    constexpr modint operator*(const modint &rhs) const noexcept { return val && rhs.val; }
    constexpr modint operator/(const modint &rhs) const noexcept { assert(rhs.val); return *this; }
    constexpr bool operator==(const modint &rhs) const noexcept { return val == rhs.val; }
    constexpr bool operator!=(const modint &rhs) const noexcept { return val != rhs.val; }
    friend constexpr modint operator+(long long lhs, modint rhs) noexcept { return lhs & 1 ? !rhs : rhs; }
    friend constexpr modint operator-(long long lhs, modint rhs) noexcept { return lhs & 1 ? !rhs : rhs; }
    friend constexpr modint operator*(long long lhs, modint rhs) noexcept { return lhs & 1 ? rhs : modint<2>{0}; }
    friend constexpr modint operator/(long long lhs, modint rhs) noexcept { assert(rhs.val); return lhs & 1 ? rhs : modint<2>{0}; }
    friend std::ostream &operator<<(std::ostream &os, const modint &rhs) noexcept { return os << rhs.val; }
    friend std::istream &operator>>(std::istream &is, modint &rhs) noexcept { long long val; rhs.val = (is >> val, val & 1); return is; }
}; // class modint

#endif

#pragma endregion // library

#pragma region main-code
struct solver; template <class> void main_(); int main() { main_<solver>(); }
template <class solver> void main_()
{
    unsigned t = 1;
#ifdef LOCAL
    t = 1;
#endif
    // t = -1; // infinite loop
    // cin >> t; // case number given

    while(t--) solver();
}

struct solver
{

    solver()
    {
        using mint=modint<998244353>;

        int n,m; cin>>n>>m;
        vector<int> a(n),b(m);  cin>>a>>b;
        b.emplace_back(INT_MAX);

        mint now,pre;
        now=1;
        int x=m;
        bool flag=true;
        for(int i=n; i--; )
        {
            if(x>0 and b[x]>a[i])
            {
                if(!flag)
                {
                    cout << 0 << "\n";
                    return;
                }
                --x;
                pre=now;
                now=0;
                flag=false;
            }
            if(b[x]>a[i])
            {
                cout << 0 << "\n";
                return;
            }
            if(b[x]==a[i])
            {
                flag=true;
            }
            if(flag)
            {
                now+=pre;
            }
        }
        if(x or !flag) cout << 0 << "\n";
        else cout << pre << "\n";
    }
};
#pragma endregion // main-code