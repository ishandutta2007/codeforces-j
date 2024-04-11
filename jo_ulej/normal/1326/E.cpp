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

#define dout   debug::instance

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
const int MAXN = (int)3e5 + 7;
int n, p[MAXN], q[MAXN], where[MAXN];
int bal[MAXN];
int mod[4 * MAXN], mx[4 * MAXN];
inline int read(int v) {
	return mod[v] + mx[v];
}
inline void relax(int v) {
	mx[v] = max(read(2*v+1), read(2*v+2));
}
inline void push(int v) {
	mod[2*v+1] += mod[v];
	mod[2*v+2] += mod[v];
	mx[v] += mod[v];
	mod[v] = 0;
}
void change(int v, int tl, int tr, int l, int r, int x) {
	if(l < tl) l = tl;
	if(r > tr) r = tr;
	if(l > r) return;
	if(tl == l && tr == r) {
		mod[v] += x;
	} else {
		push(v);
		int tm = (tl+tr)/2;
		change(2*v+1, tl, tm, l, r, x);
		change(2*v+2, tm + 1, tr, l, r, x);
		relax(v);
	}
}
int check() {
	return read(0) > 0;
}
void solve() {
	cin >> n;
	for(int i = 0; i < n; ++i) p[i] = fetch<int>() - 1;
	for(int i = 0; i < n; ++i) q[i] = fetch<int>() - 1;
	for(int i = 0; i < n; ++i) where[p[i]] = i;
	int rez = n;
	for(int i = 0; i < n; ++i) {
		while(!check()) {
			--rez;
			change(0, 0, MAXN - 1, 0, where[rez], +1);
		}
		change(0, 0, MAXN - 1, 0, q[i], -1);
		cout << rez + 1 << ' ';
	}
	cout << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}