#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,mmx,sse,sse2,tune=native")
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
#define ppc __builtin_popcountll
const int MOD  = 998244353;
const int MAXN = (int)2e5 + 7777;
inline int add(int x, int y) {
	return (x + y >= MOD ? x + y - MOD : x + y);
}
inline int mult(int x, int y) {
	ll r = x * 1LL * y;
	if(r >= MOD) r %= MOD;
	return (int)r;
}
int n;
ll m, a[MAXN], basis[MAXN];
int insert(ll msk) {
	for(ll i = 0; i < m; ++i) {
		if((msk >> i) & 1LL) {
			if(basis[i]) {
				msk ^= basis[i];
			} else {
				basis[i] = msk;
				return 1;
			}
		}
	}
	return 0;
}
int check(ll msk) {
	for(ll i = 0; i < m; ++i) {
		if((msk >> i) & 1LL) {
			if(basis[i]) {
				msk ^= basis[i];
			} else {
				return 0;
			}
		}
	}
	return (msk == 0);
}
int answ[MAXN], pw2[MAXN];
int can[(1 << 12) + 777];
int cnt[(1 << 12) + 777][15];
void solve() {
	pw2[0] = 1; for(int i = 1; i < MAXN; ++i) pw2[i] = add(pw2[i - 1], pw2[i - 1]);
	cin >> n >> m;
	for(int i = 0; i < n; ++i) cin >> a[i];
	int basisSz = 0;
	for(int i = 0; i < n; ++i) basisSz += insert(a[i]);
	vector<int> nonZ;
	for(int i = 0; i < m; ++i) if(basis[i]) nonZ.emplace_back(i);
	if(m <= 23) {
		SAY("FIRST");
		for(int msk = 0; msk < (1 << basisSz); ++msk) {
			ll x = 0;
			for(int i = 0; i < basisSz; ++i) {
				if((msk >> i) & 1) x ^= basis[nonZ[i]];
			}
			++answ[ppc(x)];
		}
	} else {
		SAY("SECOND");
		ll b = 12;
		ll a = m - b;
		for(ll msk = 0; msk < (1LL << b); ++msk) {
			if(check(msk << a)) can[msk] = 1;
		}
		for(ll f = 0; f < (1LL << b); ++f) {
			for(ll msk = 0; msk < (1LL << b); ++msk) if(can[msk]) ++cnt[f][ppc(msk ^ f)];
		}
		for(ll msk = 0; msk < (1LL << a); ++msk) {
			ll x = msk;
			int good = 1, ones = ppc(msk);
			for(ll i = 0; i < a; ++i) {
				if((x >> i) & 1LL) {
					if(basis[i]) {
						x ^= basis[i];
					} else {
						good = 0;
						break;
					}
				}
			}
			if(!good) continue;
			x >>= a;
			for(ll i = 0; i <= b; ++i) {
				answ[ones + i] = add(answ[ones + i], cnt[x][i]);
			}
		}
	}
	for(int i = 0; i <= m; ++i) {
		answ[i] %= MOD;
		answ[i] = mult(answ[i], pw2[n - basisSz]);
	}
	for(int i = 0; i <= m; ++i) cout << answ[i] << ' ';
	cout << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}