#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <sstream>
#include <bitset>
#include <cassert>
#include <fstream>
#include <queue>

#define len(X) ((int)(X).size())

#ifdef __LOCAL
	#define DEBUG_OUTPUT_ENABLED 1
#else
	#define DEBUG_OUTPUT_ENABLED 0
#endif

#define dout   debug::instance
#define DBG(X) dout << #X << "=" << (X) << '\n';
#define SAY(X) dout << (X) << '\n';

using namespace std;

template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }
namespace debug {
	struct DebugStream {
		private:
			bool is_first;
		public:
			DebugStream(bool _is_first): is_first(_is_first) {}
			template<typename T> DebugStream operator<<(const T& value) const {
				if(DEBUG_OUTPUT_ENABLED) {
					if(is_first) cout << "[DBG] ";
					cout << value;
				}
				return DebugStream(false);
			};
	};
	DebugStream instance(true);
};

using ll = long long int;
using ull = unsigned long long int;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e18);

const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for(auto& elem: ret) cin >> elem; return ret; }
const int MAXN = 5007;
struct Edge {
	int from, to, val;
	int get(int vert) {
		assert(vert == from || vert == to);
		return from ^ to ^ vert;
	}
};
vector<int> G[MAXN];
Edge edges[MAXN];
int n, m;
vector<pii> Q[MAXN];
int pa[MAXN];
void dfsik(int v, int prv) {
	for(auto& id: G[v]) {
		int u = edges[id].get(v);
		if(u != prv) {
			pa[u] = id;
			dfsik(u, v);
		}
	}
}
void solve() {
	cin >> n;
	for(int i = 0; i < n - 1; ++i) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;
		edges[i].from = v;
		edges[i].to   = u;
		edges[i].val  = 1;
		G[v].push_back(i);
		G[u].push_back(i);
	}
	cin >> m;
	for(int i = 0; i < m; ++i) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;
		int mn = fetch<int>();
		Q[v].emplace_back(u, mn);
	}
	for(int rootik = 0; rootik < n; ++rootik) {
		pa[rootik] = NIL;
		dfsik(rootik, NIL);
		for(auto& q: Q[rootik]) {
			int cur = q.first;
			int mn  = q.second;
			while(true) {
				int id = pa[cur];
				if(id == NIL) break;
				edges[id].val = max(edges[id].val, mn);
				cur = edges[id].get(cur);
			}
		}
	}
	for(int rootik = 0; rootik < n; ++rootik) {
		pa[rootik] = NIL;
		dfsik(rootik, NIL);
		for(auto& q: Q[rootik]) {
			int cur = q.first;
			int mn  = q.second;
			int rly = INT_INF;
			while(true) {
				int id = pa[cur];
				if(id == NIL) break;
				rly = min(rly, edges[id].val);
				cur = edges[id].get(cur);
			}
			if(mn != rly) {
				cout << "-1\n";
				return;
			}
		}
	}
	for(int i = 0; i < n - 1; ++i) cout << edges[i].val << ' ';
	cout << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}