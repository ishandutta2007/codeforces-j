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
	#define DBG(X) dout << #X << "=" << (X) << '\n';
	#define SAY(X) dout << (X) << '\n';
#else
	#define DEBUG_OUTPUT_ENABLED 0
	#define DBG(X) 42;
	#define SAY(X) 42;
#endif

#define dout   ___debug::instance

using namespace std;
using ll = long long int;
using ull = unsigned long long int;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const set<T>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const map<T, S>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const multiset<T>& v) { for(auto el: v) cout << el << " "; return os; }
namespace ___debug {
	struct DebugStream {
		private:
			bool is_first;
		public:
			DebugStream(bool _is_first): is_first(_is_first) {}
			template<typename T> DebugStream operator<<(const T& value) const {
				assert(DEBUG_OUTPUT_ENABLED);
				if(is_first) cout << "[DBG] ";
				cout << value;
				return DebugStream(false);
			};

			template<typename T> DebugStream printArray(T* l, T* r) {
				assert(DEBUG_OUTPUT_ENABLED);
				if(is_first) cout << "[DBG] ";
				while(l != r) {
					cout << (*l);
					++l;
					if(l == r) {
						cout << '\n';
					} else {
						cout << ' ';
					}
				}
				return DebugStream(false);
			}
	};
	DebugStream instance(true);
};

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e18);

const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for(auto& elem: ret) cin >> elem; return ret; }
const int MAXN = (int)1e6 + 7;
int Q[MAXN], head;
vector<int> BFS(const vector<vector<int>>& G, int src) {
	int n = len(G);
	vector<int> dist(n, INT_INF);
	dist[src] = 0;
	head = 0;
	Q[head++] = src;
	for(int j = 0; j < head; ++j) {
		int v = Q[j];
		for(auto& u: G[v]) if(dist[u] > dist[v] + 1) {
			dist[u] = dist[v] + 1;
			Q[head++] = u;
		}
	}
	return dist;
}
void solve() {
	int n = fetch<int>();
	int m = fetch<int>();
	int a = fetch<int>() - 1;
	int b = fetch<int>() - 1;
	int c = fetch<int>() - 1;
	vector<vector<int>> G(n, vector<int>());
	auto cost = fetch_vec<ll>(m);
	for(int id = 0; id < m; ++id) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;
		G[v].emplace_back(u);
		G[u].emplace_back(v);
	}
	sort(cost.begin(), cost.end());
	vector<ll> pref(m + 1, 0);
	for(int i = 1; i <= m; ++i) pref[i] = pref[i - 1] + cost[i - 1];
	auto dA = BFS(G, a);
	auto dB = BFS(G, b);
	auto dC = BFS(G, c);
	ll answ = LL_INF;
	for(int x = 0; x < n; ++x) {
		if(dA[x] + dB[x] + dC[x] <= m) {
			ll loc = pref[dA[x] + dB[x] + dC[x]] + pref[dB[x]];
			answ = min(answ, loc);
		}
	}
	cout << answ << '\n';
}

int main() {
	fast_io();
	int T = fetch<int>();
	while(T--) solve();

	return 0;
}