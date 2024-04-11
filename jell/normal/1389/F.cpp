#pragma region preprocessor
#ifdef LOCAL
//*
    #define _GLIBCXX_DEBUG  // gcc
/*/
    #define _LIBCPP_DEBUG 0 // clang
//*/
    // #define __buffer_check__
#else
    #pragma GCC optimize("Ofast")
    // #define NDEBUG
#endif
#define __precision__ 15
#define __iostream_untie__ true
#include <bits/stdc++.h>
#include <ext/rope>

#ifdef LOCAL
    #include "dump.hpp"
    #define mesg(str) std::cerr << "[ " << __LINE__ << " : " << __FUNCTION__ << " ]  " << str << "\n"
#else
    #define dump(...) ((void)0)
    #define mesg(str) ((void)0)
#endif
#pragma endregion

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
#pragma endregion

#pragma region config
namespace config
{
    const auto start_time{std::chrono::system_clock::now()};
    int64_t elapsed()
    {
        using namespace std::chrono;
        const auto end_time{std::chrono::system_clock::now()};
        return duration_cast<milliseconds>(end_time - start_time).count();
    }
    __attribute__((constructor)) void setup()
    {
        using namespace std;
        if(__iostream_untie__) ios::sync_with_stdio(false), cin.tie(nullptr);
                cout << fixed << setprecision(__precision__);
        #ifdef DEBUG
                freopen("debug.out","w",stdout);
                freopen("debug.err","w",stderr);
                if(!freopen("debug.in","r",stdin))
                {
                    cerr << "error: \"./debug.in\" not found.\n";
                    exit(EXIT_FAILURE);
                }
        #endif
        #ifdef stderr_path
                freopen(stderr_path, "a", stderr);
        #endif
        #ifdef LOCAL
                cerr << fixed << setprecision(__precision__) << boolalpha << "\n----- stderr at LOCAL -----\n\n";
                atexit([]{ cerr << "\n----- Exec time : " << elapsed() << " ms -----\n\n"; });
        #endif
        #ifdef __buffer_check__
                atexit([]{ ofstream cnsl("CON"); char bufc; if(cin >> bufc) cnsl << "\n\033[1;35mwarning\033[0m: buffer not empty.\n\n"; });
        #endif
    }
} // namespace config
#pragma endregion

#pragma region utility
// lambda wrapper for recursive method.
template <class lambda_type>
class fixed_point
{
    lambda_type func;
public:
    fixed_point(lambda_type &&f) : func(std::move(f)) {}
    template <class... Args> auto operator()(Args &&... args) const { return func(*this, std::forward<Args>(args)...); }
};
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
        iter_type __left(__first + dist / 3), __right(__first + dist * 2 / 3);
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
#pragma endregion

#pragma region alias
using namespace std;
using i32 = int_least32_t; using i64 = int_least64_t; using u32 = uint_least32_t; using u64 = uint_least64_t;
using p32 = pair<i32, i32>; using p64 = pair<i64, i64>;
template <class T, class Comp = less<T>> using heap = priority_queue<T, vector<T>, Comp>;
template <class T> using hashset = unordered_set<T>;
template <class Key, class Value> using hashmap = unordered_map<Key, Value>;
using namespace __gnu_cxx;
#pragma endregion

#pragma region library

#include <cassert>
#include <vector>

template <class monoid, class homomorphism>
class lazy_segment_tree
{
    using size_type = typename std::vector<monoid>::size_type;

    size_type size_orig, height, size_ext;
    std::vector<monoid> data;
    std::vector<homomorphism> lazy;

    void recalc(const size_type node) { data[node] = data[node << 1] + data[node << 1 | 1]; }

    void apply(size_type index, const homomorphism &homo)
    {
        homo.apply(data[index]);
        if(index < size_ext) lazy[index] *= homo;
    }

    void push(size_type index)
    {
        if(index >= size_ext) return;
        apply(index << 1, lazy[index]);
        apply(index << 1 | 1, lazy[index]);
        lazy[index] = homomorphism{};
    }

    template <class pred_type>
    size_type left_search_subtree(size_type index, const pred_type pred, monoid mono)
    {
        assert(index);
        while(index < size_ext)
        {
            push(index);
            const monoid tmp = data[(index <<= 1) | 1] + mono;
            if(pred(tmp)) mono = tmp;
            else ++index;
        }
        return ++index -= size_ext;
    }

    template <class pred_type>
    size_type right_search_subtree(size_type index, const pred_type pred, monoid mono)
    {
        assert(index);
        while(index < size_ext)
        {
            push(index);
            const monoid tmp = mono + data[index <<= 1];
            if(pred(tmp)) ++index, mono = tmp;
        }
        return (index -= size_ext) < size_orig ? index : size_orig;
    }

public:
    lazy_segment_tree(const size_type n = 0) : size_orig{n}, height(n > 1 ? 32 - __builtin_clz(n - 1) : 0), size_ext{1u << height}, data(size_ext << 1), lazy(size_ext) {}

    lazy_segment_tree(const size_type n, const monoid &init) : lazy_segment_tree(n)
    {
        std::fill(std::next(std::begin(data), size_ext), std::end(data), init);
        for(size_type i{size_ext}; --i; ) recalc(i);
    }

    template <class iter_type, class value_type = typename std::iterator_traits<iter_type>::value_type>
    lazy_segment_tree(iter_type first, iter_type last)
        : size_orig(std::distance(first, last)), height(size_orig > 1 ? 32 - __builtin_clz(size_orig - 1) : 0), size_ext{1u << height}, data(size_ext << 1), lazy(size_ext)
    {
        static_assert(std::is_constructible<monoid, value_type>::value, "monoid(iter_type::value_type) is not constructible.");
        for(auto iter{std::next(std::begin(data), size_ext)}; iter != std::end(data) && first != last; ++iter, ++first) *iter = monoid(*first);
        for(size_type i{size_ext}; --i; ) recalc(i);
    }

    template <class container_type, typename = typename container_type::value_type>
    lazy_segment_tree(const container_type &cont) : lazy_segment_tree(std::begin(cont), std::end(cont)) {}

    size_type size() const { return size_orig; }
    size_type capacity() const { return size_ext; }

    monoid operator[](size_type index) { return fold(index, index + 1); }

    void update(const size_type index, const homomorphism &homo) { update(index, index + 1, homo); }

    void update(size_type first, size_type last, const homomorphism &homo)
    {
        assert(last <= size_orig);
        if(first >= last) return;
        first += size_ext, last += size_ext - 1;
        for(size_type i = height; i; --i) push(first >> i), push(last >> i);
        for(size_type l = first, r = last + 1; last; l >>= 1, r >>= 1)
        {
            if(l < r)
            {
                if(l & 1) apply(l++, homo);
                if(r & 1) apply(--r, homo);
            }
            if(first >>= 1, last >>= 1)
            {
                recalc(first), recalc(last);
            }
        }
    }

    monoid fold() { return fold(0, size_orig); }

    monoid fold(size_type first, size_type last)
    {
        assert(last <= size_orig);
        if(first >= last) return monoid{};
        first += size_ext, last += size_ext - 1;
        monoid left_val{}, right_val{};
        for(size_type l = first, r = last + 1; last; l >>= 1, r >>= 1)
        {
            if(l < r)
            {
                if(l & 1) left_val = left_val + data[l++];
                if(r & 1) right_val = data[--r] + right_val;
            }
            if(first >>= 1, last >>= 1)
            {
                lazy[first].apply(left_val);
                lazy[last].apply(right_val);
            }
        }
        return left_val + right_val;
    }

    template <class pred_type>
    size_type left_search(size_type right, const pred_type pred)
    {
        assert(right <= size_orig);
        right += size_ext - 1;
        for(size_type i{height}; i; --i) push(right >> i);
        ++right;
        monoid mono{};
        for(size_type left{size_ext}; left != right; left >>= 1, right >>= 1)
        {
            if((left & 1) != (right & 1))
            {
                const monoid tmp = data[--right] + mono;
                if(!pred(tmp)) return left_search_subtree(right, pred, mono);
                mono = tmp;
            }
        }
        return 0;
    }

    template <class pred_type>
    size_type right_search(size_type left, const pred_type pred)
    {
        assert(left <= size_orig);
        left += size_ext;
        for(size_type i{height}; i; --i) push(left >> i);
        monoid mono{};
        for(size_type right{size_ext << 1}; left != right; left >>= 1, right >>= 1)
        {
            if((left & 1) != (right & 1))
            {
                const monoid tmp = mono + data[left];
                if(!pred(tmp)) return right_search_subtree(left, pred, mono);
                mono = tmp;
                ++left;
            }
        }
        return size_orig;
    }
}; //class lazy_segment_tree


#include <algorithm>
#include <cassert>
#include <vector>

template <class T>
class coordinate_compression
{
    std::vector<T> uniquely;
    std::vector<size_t> compressed;

public:
    coordinate_compression(const std::vector<T> &raw) : uniquely(raw), compressed(uniquely.size())
    {
        std::sort(uniquely.begin(), uniquely.end());
        uniquely.erase(std::unique(uniquely.begin(), uniquely.end()), uniquely.end());
        for(size_t i = 0; i != raw.size(); ++i)
            compressed[i] = std::lower_bound(uniquely.begin(), uniquely.end(), raw[i]) - uniquely.begin();
    }

    size_t operator[](const size_t idx) const
    {
        assert(idx < compressed.size());
        return compressed[idx];
    }

    size_t kind() const { return uniquely.size(); }

    T restore(const size_t ord) const
    {
        assert(ord < uniquely.size());
        return uniquely[ord];
    }

    size_t order_of(const T &val) const { return std::lower_bound(uniquely.begin(), uniquely.end(), val) - uniquely.begin(); }

    std::vector<size_t>::iterator begin() { return compressed.begin(); }
    std::vector<size_t>::iterator end() { return compressed.end(); }
    std::vector<size_t>::reverse_iterator rbegin() { return compressed.rbegin(); }
    std::vector<size_t>::reverse_iterator rend() { return compressed.rend(); }
};

#pragma endregion

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

template <class T>
struct max_mono
{
    T val;
    max_mono(T v=0) : val(v) {}

    // binary operation
    max_mono operator+(const max_mono& rhs) const { return max_mono{*this} += rhs; }

    // operation assignment
    max_mono &operator+=(const max_mono &rhs)
    {
        if(val < rhs.val) val = rhs.val;
        return *this;
    }
};

struct endo
{
    int val=0;

    // compose.
    void operator*=(const endo& rhs)
    {
        val+=rhs.val;
    }

    // apply self to an element of X.
    template <class X>
    void apply(X &rhs) const
    {
        rhs.val+=val;
    }
};

struct solver
{

    solver()
    {
        const int n=read<int>();
        struct seg { int l,r,t; };
        vector<seg> segs(n);
        for(auto& [l,r,t]: segs) cin>>l>>r>>t;
        vector<vector<seg>> red(n*2+1);
        // compress
        {
            vector<int> pos;
            for(auto [l,r,t]: segs)
            {
                pos.emplace_back(l);
                pos.emplace_back(r);
            }
            coordinate_compression cp(pos);
            for(auto &[l,r,t]: segs)
            {
                l=cp.order_of(l);
                r=cp.order_of(r);
                red[r+1].push_back({l+1,r,t});
            }
        }
        lazy_segment_tree<max_mono<int>,endo> dp1(n*2+1),dp2(n*2+1);
        for(int r=0; r<=n*2; r++)
        {
            for(auto [l,_,t]: red[r])
            {
                dump(l,r,t);
                if(t==1) dp2.update(0,l,{1});
                else dp1.update(0,l,{1});
            }
            int nd1=dp1.fold().val;
            int nd2=dp2.fold().val;
            dp1.update(r,{nd2});
            dp2.update(r,{nd1});
        }
        cout<<(dp1.fold()+dp2.fold()).val<<endl;
    }
};