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
	#define DBG(X) cout << #X << "=" << (X) << '\n';
	#define SAY(X) cout << (X) << '\n';
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

const int MAXN = (int)2e5 + 777;
int pa[MAXN], cnt[MAXN];
int n;

void init_DSU() {
	for(int i = 0; i < MAXN; ++i) {
		pa[i] = i;
		cnt[i] = 1;
	}
}

int get_parent(int i) {
	while(pa[i] != i) {
		i = pa[i];
	}

	return i;
}

int connect(int i, int j) {
	i = get_parent(i);
	j = get_parent(j);

	if(i != j) {
		if(cnt[j] > cnt[i]) {
			swap(i, j);
		}

		pa[j] = i;
		cnt[i] += cnt[j];

		return 1;
	} else {
		return 0;
	}
}

void solve() {
	cin >> n;
	init_DSU();

	for(int i = 0; i < n; ++i) {
		auto S = fetch<string>();

		for(auto& ch: S) {
			int code = ch - 'a';
			connect(i, n + code);
		}
	}

	set<int> answ;

	for(int i = 0; i < n; ++i) {
		answ.insert(get_parent(i));
	}

	cout << len(answ) << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}