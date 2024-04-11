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
	#define DBG(X) cout << "[DBG] " << #X << "=" << (X) << '\n';
	#define SAY(X) cout << "[SAY] " << (X) << '\n';
#else
	#define DBG(X)
	#define SAY(X)
#endif
 
using namespace std;

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
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for(auto& elem: ret) cin >> elem; return ret; }

const int MOD  = (int)1e9 + 7;
int add(int x, int y) {
	return (x + y >= MOD ? x + y - MOD : x + y);
}
int sub(int x, int y) {
	return (x - y < 0 ? x - y + MOD : x - y);
}
int mult(int x, int y) {
	return (x * 1LL * y) % MOD;
}
const int MAXN = 2007;
vector<int> G[MAXN];
int a[MAXN], n, d;
int dp[MAXN], used[MAXN];
void dfs(int v, int L, int R) {
	if(a[v] < L || a[v] > R) return;
	used[v] = 1;
	dp[v] = 1;
	for(auto& u: G[v]) {
		if(!used[u]) {
			dfs(u, L, R);
			dp[v] = mult(dp[v], add(1, dp[u]));
		}
	}
}
int query(int L, int R) {
	if(L > R) return 0;
	memset(dp, 0, sizeof(dp));
	memset(used, 0, sizeof(used));
	int rez = 0;
	for(int v = 0; v < n; ++v) if(!used[v]) dfs(v, L, R);
	for(int v = 0; v < n; ++v) rez = add(rez, dp[v]);
	return rez;
}
void solve() {
	cin >> d >> n;
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < n - 1; ++i) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;
		G[v].push_back(u);
		G[u].push_back(v);
	}
	int answ = 0;
	for(int val = 0; val < MAXN; ++val) {
		answ = add(answ, query(val, val + d));
		answ = sub(answ, query(val + 1, val + d));
	}
	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}