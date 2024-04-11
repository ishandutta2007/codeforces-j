#ifdef DEBUG
    #define _GLIBCXX_DEBUG
#endif 
#if !defined(LOCAL) && !defined(DEBUG)
    #pragma GCC optimize("Ofast")
#endif
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <complex>
#include <iomanip>
#include <bitset>
#include <random>

#define iostream_untie true
#define stdout_precision 10
#define stderr_precision 10
#define itrep(i,v) for(auto i = begin(v); i != end(v); ++i)
#define ritrep(i,v) for(auto i = rbegin(v); i != rend(v); ++i)
#define rep(i,n) for(int_fast64_t i = 0; i < (int_fast64_t)(n); ++i)
#define rrep(i,n) for(int_fast64_t i = (int_fast64_t)(n) - 1; i >= 0; --i)
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define fir first
#define sec second
#define u_map unordered_map
#define u_set unordered_set
#define l_bnd lower_bound
#define u_bnd upper_bound
#define emp emplace
#define emf emplace_front
#define emb emplace_back
#define pof pop_front
#define pob pop_back
#define mkp make_pair
#define mkt make_tuple
#define popcnt __builtin_popcountll

using namespace std;
using i64 = int_fast64_t;
using pii = pair<int, int>;
using pll = pair<int_fast64_t, int_fast64_t>;
template <class T> using heap = priority_queue<T>;
template <class T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template <class T> constexpr T inf = numeric_limits<T>::max() / (T)2 - (T)1234567;
constexpr int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
constexpr int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr long double Pi = 3.1415926535897932384626433832;
constexpr long double Golden = 1.61803398874989484820;

namespace setup {
    struct setupper {
        setupper() {
            if(iostream_untie) {
                ios::sync_with_stdio(false);
                std::cin.tie(nullptr);
                // std::cout.tie(nullptr);
                // std::cerr.tie(nullptr);
            }
            std::cout << std::fixed << std::setprecision(stdout_precision);
            std::cerr << std::fixed << std::setprecision(stderr_precision);
    #ifdef LOCAL
            if(!freopen("stderr.txt","wt",stderr)) {
                freopen("CON","wt",stderr);
                std::cerr << "Failed to open the stderr file\n";
            }
            if(!freopen("stdout.txt","wt",stdout)) {
                freopen("CON","wt",stdout);
                std::cerr << "Failed to open the stdout file\n";
            }
            // auto print_atexit = []() {
            //     std::cerr << "Exec time : " << clock() / (double)CLOCKS_PER_SEC * 1000.0 << "ms\n";
            //     std::cerr << "------------\n";
            // };
            // atexit((void(*)())print_atexit);
    #endif
        }
    } __setupper;
}

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
    template <class tuple_t, size_t index = tuple_size<tuple_t>::value - 1>
    struct hashval_calc {
        static void apply(size_t& seed, tuple_t const& t) {
            hashval_calc<tuple_t, index - 1>::apply(seed, t);
            hash_combine(seed,get<index>(t));
        }
    };
    template <class tuple_t>
    struct hashval_calc<tuple_t, 0> {
        static void apply(size_t& seed, tuple_t const& t) {
            hash_combine(seed,get<0>(t));
        }
    };
    template <class ...T> struct hash<tuple<T...>> {
        size_t operator()(tuple<T...> const& t) const
        {
            size_t seed = 0;
            hashval_calc<tuple<T...>>::apply(seed,t);
            return seed;
        }
    };
}

template <class T, class U> istream &operator>> (istream &s, pair<T,U> &p) { return s >> p.first >> p.second; }
template <class T, class U> ostream &operator<< (ostream &s, const pair<T,U> p) { return s << p.first << " " << p.second; }
template <class T> istream &operator>> (istream &s, vector<T> &v) { for(T &e : v) { s >> e; }   return s; }
template <class T> ostream &operator<< (ostream &s, const vector<T> &v) {
    for(size_t i = 0; i < v.size(); ++i) { s << (i ? " " : "") << v[i]; }   return s;
}
template <class tuple_t, size_t index>
struct tupleos {
    static ostream &apply(ostream &s, const tuple_t &t) {
        tupleos<tuple_t,index - 1>::apply(s,t);
        return s << " " << get<index>(t);
    }
}; 
template <class tuple_t>
struct tupleos<tuple_t, 0> {
    static ostream &apply(ostream &s, const tuple_t &t) {
        return s << get<0>(t);
    }
};
template <class ...T> ostream &operator<< (ostream &s, const tuple<T...> &t) {
    return tupleos<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(s,t);
}
template <> ostream &operator<< (ostream &s, const tuple<> &t) { return s; }
#ifdef DEBUG
    #define dump(...) cerr << " [ " << __LINE__ << " : " << __FUNCTION__ << " ] " << #__VA_ARGS__ << " : ", dump_func(__VA_ARGS__)
#else
    #define dump(...) 
#endif
template <class T> void dump_func(T x) { cerr << x << '\n'; }
template <class T,class ...Rest> void dump_func(T x, Rest ... rest) { cerr << x << ","; dump_func(rest...); }
template <class T> void write(T x) { cout << x << '\n'; }
template <class T, class ...Rest> void write(T x, Rest ... rest) { cout << x << ' '; write(rest...); }
void writeln() {}
template <class T, class ...Rest> void writeln(T x, Rest ... rest) { cout << x << '\n'; writeln(rest...); }
#define esc(...) writeln(__VA_ARGS__), exit(0)
template <class P> void read(P __first, P __second) {
    for(P i = __first; i != __second; ++i) cin >> *i;
}

namespace updater {
    template <class T> static void add(T &x, const T &y) { x += y; }
    template <class T> static void ext_add(T &x, const T &y, size_t w) { x += y * w; }
    template <class T> static void mul(T &x, const T &y) { x *= y; }
    template <class T> static void ext_mul(T &x, const T &y, size_t w) { x *= (T)pow(y,w); }
    template <class T> static bool chmax(T &x, const T &y) { return x < y ? x = y, true : false; }
    template <class T> static bool chmin(T &x, const T &y) { return x > y ? x = y, true : false; }
};
using updater::add;
using updater::mul;
using updater::chmax;
using updater::chmin;
template <class T> constexpr T minf(const T &x, const T &y) { return min(x,y); }
template <class T> constexpr T maxf(const T &x, const T &y) { return max(x,y); }
constexpr bool odd(int_fast64_t n) { return n & 1; }
constexpr bool even(int_fast64_t n) { return (int)odd(n) ^ 1; }
constexpr bool bit(int_fast64_t n, int e) { return (n >> e) & 1; }
constexpr int_fast64_t mask(int_fast64_t n, int e) { return n & ((1 << e) - 1); }
constexpr int_fast64_t ilog(int_fast64_t x, int_fast64_t b = 2) { return x ? 1 + ilog(x / b, b) : -1; }
constexpr int_fast64_t gcd(int_fast64_t x, int_fast64_t y) { return x = max(x, -x), y = max(y, -y) ? gcd(y, x % y) : x; }
constexpr int_fast64_t lcm(int_fast64_t x, int_fast64_t y) { return x ? x / gcd(x, y) * y : 0; }
int_fast64_t binry(int_fast64_t ok, int_fast64_t ng, const function<bool(int_fast64_t)> &fn) {
    while (abs(ok - ng) > 1) {
        int_fast64_t mid = (ok + ng) / 2;
        (fn(mid) ? ok : ng) = mid;
    }
    return ok;
}
template <class A, size_t N, class T> void init(A (&array)[N], const T &val) { fill((T*)array, (T*)(array + N), val); }
template <class T> vector<int> cmprs(const vector<T> &v) {
    vector<T> tmp = v; vector<int> ret;
    sort(begin(tmp),end(tmp));
    tmp.erase(unique(begin(tmp),end(tmp)), end(tmp));
    for(T i : v) ret.emplace_back(lower_bound(begin(tmp),end(tmp),i) - begin(tmp));
    return ret;
}
template <class T> vector<int> cmprs(const T *__first, const T *__last) {
    return cmprs(vector<T>(__first, __last));
}
void for_subset(int_fast64_t s, const function<void(int_fast64_t)> &fn) {
    int_fast64_t tmp = s;
    do { fn(tmp); } while((--tmp &= s) != s);
}


/* The main code follows. */


signed main() {
    void solve();
    void input();
    
    int t = 1;
    // cin >> t;
    while(t--) {
        input();
        solve();
    }
}

int n;
i64 a[1<<18];

void input() {
    cin>>n;
    read(a,a+n);
}

int cnt[64];
vector<int> bi[64];
vector<int> g[1<<17];
bool vis[1<<17];
// int la[1<<17];
// int cyc[1<<17];
// vector<int> his[1<<17];

void solve() {
    rep(i,n) {
        i64 b=a[i];
        int t=0;
        while(b) {
            if(b&1) cnt[t]++,bi[t].emplace_back(i);
            b>>=1;
            ++t;
        }
    }
    if(*max_element(cnt,cnt+64)>2) {
        cout<<"3\n"; return;
    }
    u_set<pii> edge;
    rep(i,64) {
        if(cnt[i]>1) {
            edge.emplace(bi[i][0],bi[i][1]);
        }
    }

    for(auto &e:edge) {
        g[e.fir].emplace_back(e.sec);
        g[e.sec].emplace_back(e.fir);
    }

    int ans=inf<int>;
    vector<int> dist(n,-1);
    vector<int> par[18];
    for(int i=0; i<=17; ++i) par[i].resize(n);

    for(int i=0; i<n; ++i) {
        if(!vis[i]) {
            vector<int> vrts;
            vector<pii> check;
            queue<pii> que;
            dist[i]=0;
            vis[i]=1;
            for(int h=0; h<18; ++h) par[h][i]=i;
            que.emplace(i,-1);
            // his[i].emplace_back(i);

            while(!que.empty()) 
            {
                int v,p;
                tie(v,p)=que.front(); que.pop();
                vrts.emplace_back(v);
                for(int u:g[v]) {
                    if(u==p) continue;
                    if(vis[u]) {
                        check.emplace_back(u,v);
                        // int tt=0;
                        // while(tt<=dist[u] and tt<= dist[v] and his[u][tt]==his[v][tt]) {
                        //     ++tt;
                        // }
                        // --tt;

                        // if(chmin(ans,dist[u]+dist[v]+1-tt*2)) {
                        //     dump(i,ans,u,v,dist[u],dist[v],tt);
                        // }
                    } else {
                        que.emplace(u,v);
                        par[0][u]=v;
                        dist[u]=dist[v]+1;
                        vis[u]=1;
                        // his[u]=his[v];
                        // his[u].emplace_back(u);
                    }
                }
            }

            for(int h=0; h<17; ++h) {
                for(int v:vrts) {
                    par[h+1][v]=par[h][par[h][v]];
                }
            }

            for(auto &e:check) {
                int a,b; tie(a,b)=e;
                if(dist[a]>dist[b]) {
                    swap(a,b);
                }
                int dif=dist[b]-dist[a];
                for(int i=0,d=dif; d; ++i,d>>=1) {
                    if(dif&1) {
                        b=par[i][b];
                    }
                }
                if(a!=b) {
                    for(int h=17; h>=0; --h) {
                        if(par[h][a]!=par[h][b]) {
                            a=par[h][a];
                            b=par[h][b];
                            dif+=2<<h;
                        }
                    }
                    ans=min(ans,dif+3);
                } else {
                    ans=min(ans,dif+1);
                }
            }
        }
    }

    if(ans<inf<int>) {
        cout<<ans<<"\n";
    } else {
        cout<<"-1\n";
    }
}