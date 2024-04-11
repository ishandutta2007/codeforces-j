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
const int MAXN = (int)1.1e6 + 7;
vector<int> G[MAXN];
int n, m, cnt;
int E[30];
vector<int> L, R;
int InDeg[MAXN], OutDeg[MAXN], used[MAXN];
void Dfsik(int v) {
	used[v] = 1;
	for(auto& u: G[v]) if(!used[u]) Dfsik(u);
}
int dp[MAXN];
#define ppc __builtin_popcount
void solve() {
	cin >> n >> m;
	for(int id = 0; id < m; ++id) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;
		G[v].emplace_back(u);
		++OutDeg[v];
		++InDeg[u];
	}
	for(int v = 0; v < n; ++v) {
		if(!InDeg[v]) L.emplace_back(v);
		if(!OutDeg[v]) R.emplace_back(v);
	}
	assert(len(L) == len(R));
	cnt = len(L);
	for(int i = 0; i < cnt; ++i) {
		int v = L[i];
		memset(used, 0, sizeof(used));
		Dfsik(v);
		for(int j = 0; j < cnt; ++j) {
			int u = R[j];
			if(used[u]) E[i] |= 1 << j;
		}
	}
	for(int i = 0; i < cnt; ++i) dp[1 << i] = E[i];
	for(int msk = 0; msk < (1 << cnt); ++msk) {
		int msk2 = msk & (msk - 1);
		if(msk2) {
			dp[msk] = dp[msk2] | dp[msk2 ^ msk];
		}
		//dout << msk << ' ' << dp[msk] << '\n';
		if(msk && msk != (1 << cnt) - 1 && ppc(msk) >= ppc(dp[msk])) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
	fast_io();
	solve();

	return 0;
}