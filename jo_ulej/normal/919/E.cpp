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
ll a, b, p, x;
ll add(ll xx, ll yy) {
	return (xx + yy >= p ? xx + yy - p : xx + yy);
}
ll sub(ll xx, ll yy) {
	return (xx - yy < 0 ? xx - yy + p : xx - yy);
}
ll mult(ll xx, ll yy) {
	ll R = xx * yy;
	if(R >= p) R %= p;
	return R;
}
ll binpow(ll xx, ll yy) {
	if(xx==1||yy==0) return 1;
	if(xx==0) return 0;
	ll rez = binpow(xx, yy>>1LL);
	rez = mult(rez, rez);
	if(yy&1LL) rez = mult(rez, xx);
	return rez;
}
ll divide(ll x, ll y) {
	return mult(x, binpow(y, p - 2));
}
void solve() {
	a = fetch<ll>();
	b = fetch<ll>();
	p = fetch<ll>();
	x = fetch<ll>();
	ll M = p*(p-1);
	vector<ll> rems;
	for(ll i = 0; i < p-1; ++i) {
		ll j = divide(b, binpow(a, i));
		//dout << "n % " << p-1 << " = " << i << '\n';
		//dout << "n % " << p   << " = " << j << '\n';
		ll rem = sub(i%p, j%p) * (p - 1) + i;
		if(rem >= M) rem %= M;
		rems.emplace_back(rem);
	}
	sort(rems.begin(), rems.end());
	rems.erase(unique(rems.begin(), rems.end()), rems.end());
	//DBG(M); DBG(rems);
	ll answ = 0;
	for(auto& rem: rems) {
		answ += x/M;
		answ += (x%M >= rem);
		answ -= rem==0;
	}
	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}