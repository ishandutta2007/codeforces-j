#pragma GCC optimize("Ofast")
#include <cassert>
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <complex>
#include <iomanip>
#include <bitset>
#include <random>

using namespace std;
using i64 = int_fast64_t;
using ui64 = uint_fast64_t;
using db = long double;
using pii = pair<int, int>;
using pli = pair<int_fast64_t, int>;
using pll = pair<int_fast64_t, int_fast64_t>;
using pdi = pair<double, int>;
template <class T> using vct = vector<T>;
template <class T> using heap = priority_queue<T>;
template <class T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template <class T> constexpr T inf = numeric_limits<T>::max() / (T)1024;
constexpr int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
constexpr int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr long double Pi = 3.1415926535897932384626433832795028841971;
constexpr long double Golden = 1.61803398874989484820;
constexpr long double eps = 1e-15;

#define iostream_untie true
#define mod 998244353LL
#define stdout_precision 10
#define stderr_precision 5
#define itr(i,v) for(auto i = begin(v); i != end(v); ++i)
#define ritr(i,v) for(auto i = rbegin(v); i != rend(v); ++i)
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n) - 1; i >= 0; --i)
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define fir first
#define sec second
#define u_map unordered_map
#define u_set unordered_set
#define l_bnd lower_bound
#define u_bnd upper_bound
#define rsz resize
#define ers erase
#define emp emplace
#define emf emplace_front
#define emb emplace_back
#define pof pop_front
#define pob pop_back
#define mkp make_pair
#define mkt make_tuple
#define popcnt __builtin_popcount

struct setupper {
    setupper() {
        if(iostream_untie) {
            ios::sync_with_stdio(false);
            std::cin.tie(nullptr);
            std::cout.tie(nullptr);
            std::cerr.tie(nullptr);
        }
        std::cout << fixed << setprecision(stdout_precision);
        std::cerr << fixed << setprecision(stderr_precision);
#ifdef LOCAL
        if(!freopen("stdin.txt","rt",stdin)) {
            cerr << "Failed to open the input file.\n"; exit(EXIT_FAILURE);
        }
        // if(!freopen("output.txt","wt",stdout)) {
        //     cerr << "Failed to open the output file.\n"; exit(EXIT_FAILURE);
        // }
        // std::cerr << "\n---stderr---\n";
        // auto print_atexit = []() {
        //     std::cerr << "Exec time : " << clock() / (double)CLOCKS_PER_SEC * 1000.0 << "ms\n";
        //     std::cerr << "------------\n";
        // };
        // atexit((void(*)())print_atexit);
        // atexit((void(*)())fclose(stdin));
#endif
    }
} __setupper;

namespace std {
    template <class RAitr> void rsort(RAitr __first, RAitr __last) {
        sort(__first, __last, greater<>());
    }
    template <class T> void hash_combine(size_t &seed, T const &key) {
        seed ^= hash<T>()(key) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    template <class T, class U> struct hash<pair<T,U>> {
        size_t operator()(pair<T,U> const &pr) const
        {
            size_t seed = 0;
            hash_combine(seed,pr.first);
            hash_combine(seed,pr.second);
            return seed;
        }
    };
    template <class Tup, size_t index = tuple_size<Tup>::value - 1> struct hashval_calc {
        static void apply(size_t& seed, Tup const& tup) {
            hashval_calc<Tup, index - 1>::apply(seed, tup);
            hash_combine(seed,get<index>(tup));
        }
    };
    template <class Tup> struct hashval_calc<Tup,0> {
        static void apply(size_t& seed, Tup const& tup) {
            hash_combine(seed,get<0>(tup));
        }
    };
    template <class ...T> struct hash<tuple<T...>> {
        size_t operator()(tuple<T...> const& tup) const
        {
            size_t seed = 0;
            hashval_calc<tuple<T...>>::apply(seed,tup);
            return seed;
        }
    };
}

template <class T, class U> istream &operator>> (istream &s, pair<T,U> &p) { return s >> p.first >> p.second; }
template <class T, class U> ostream &operator<< (ostream &s, const pair<T,U> p) { return s << p.first << " " << p.second; }
template <class T> ostream &operator<< (ostream &s, const vector<T> &v) {
    for(size_t i = 0; i < v.size(); ++i) s << (i ? " " : "") << v[i]; return s;
}
#define dump(...) cerr << " [ " << __LINE__ << " : " << __FUNCTION__ << " ] " << #__VA_ARGS__ << " : ";\
dump_func(__VA_ARGS__)
template <class T> void dump_func(T x) { cerr << x << '\n'; }
template <class T,class ...Rest> void dump_func(T x, Rest ... rest) { cerr << x << ","; dump_func(rest...); }
template <class T = i64> T read() { T x; return cin >> x, x; }
template <class T> void write(T x) { cout << x << '\n'; }
template <class T, class ...Rest> void write(T x, Rest ... rest) { cout << x << ' '; write(rest...); }
void writeln() {}
template <class T, class ...Rest> void writeln(T x, Rest ... rest) { cout << x << '\n'; writeln(rest...); }
#define esc(...) writeln(__VA_ARGS__), exit(0)

namespace updater {
    template <class T> static void add(T &x, const T &y) { x += y; }
    template <class T> static void ext_add(T &x, const T &y, size_t w) { x += y * w; }
    template <class T> static void mul(T &x, const T &y) { x *= y; }
    template <class T> static void ext_mul(T &x, const T &y, size_t w) { x *= (T)pow(y,w); }
    template <class T, class U> static bool chmax(T &x, const U &y) { return x < y ? x = y,true : false; }
    template <class T, class U> static bool chmin(T &x, const U &y) { return x > y ? x = y,true : false; }
};
using updater::chmax;
using updater::chmin;

template <class T> T minf(const T &x, const T &y) { return min(x,y); }
template <class T> T maxf(const T &x, const T &y) { return max(x,y); }
bool bit(i64 n, uint8_t e) { return (n >> e) & 1; }
i64 mask(i64 n, uint8_t e) { return n & ((1 << e) - 1); }
int ilog(uint64_t x, uint64_t b = 2) { return x ? 1 + ilog(x / b,b) : -1; }
template <class F> i64 binry(i64 ok, i64 ng, const F &fn) {
    while (abs(ok - ng) > 1) {
        i64 mid = (ok + ng) / 2;
        (fn(mid) ? ok : ng) = mid;
    }
    return ok;
}
template <class A, size_t N, class T> void init(A (&array)[N], const T &val) { fill((T*)array,(T*)(array + N),val); }
template <class A> void cmprs(A ary[], size_t n) {
    vector<A> tmp(ary,ary + n);
    tmp.erase(unique(begin(tmp),end(tmp)), end(tmp));
    for(A *i = ary; i != ary + n; ++i) *i = l_bnd(all(tmp),*i) - begin(tmp);
}
template <class T> void cmprs(vector<T> &v) {
    vector<T> tmp = v; sort(begin(tmp),end(tmp));
    tmp.erase(unique(begin(tmp),end(tmp)), end(tmp));
    for(auto i = begin(v); i != end(v); ++i) *i = l_bnd(all(tmp),*i) - begin(tmp);
}
template <class F> void for_subset(uint_fast64_t s, const F &fn) {
    uint_fast64_t tmp = s;
    do { fn(tmp); } while((--tmp &= s) != s);
}


/* The main code follows. */

int n;
int bb[1<<17],cc[1<<17];
vector<pair<int,int>> g[1<<17];
int itr[1<<17];
bool used[1<<17];
vector<int> num;


void dfs(int v, vector<int> &trail) {
    for(int &i=itr[v]; i<g[v].size(); ++i) {
        int u,e; tie(u,e)=g[v][i];
        if(!used[e]) {
            used[e]=true;
            dfs(u,trail);
        }
    }
    trail.emplace_back(v);
}

signed main() {
    cin>>n;
    rep(i,n-1) cin>>bb[i],num.emplace_back(bb[i]);
    rep(i,n-1) cin>>cc[i],num.emplace_back(cc[i]);
    rep(i,n-1) if(bb[i]>cc[i]) esc(-1);

    sort(all(num));
    num.erase(unique(all(num)),end(num));
    if(num.size()>n) esc(-1);

    rep(i,n-1) {
        bb[i]=l_bnd(all(num),bb[i])-num.begin();
        cc[i]=l_bnd(all(num),cc[i])-num.begin();
        g[bb[i]].emplace_back(cc[i],i);
        g[cc[i]].emplace_back(bb[i],i);
    }

    int oddcnt=0;
    int s=0;
    rep(i,1<<17) {
        if(g[i].size()%2) {
            oddcnt++;
            s=i;
        }
    }
    if(oddcnt!=0 && oddcnt!=2) esc(-1);

    vector<int> ans;
    dfs(s,ans);
    if(ans.size()!=n) esc(-1);

    for(int &v:ans) v=num[v];
    esc(ans);
}