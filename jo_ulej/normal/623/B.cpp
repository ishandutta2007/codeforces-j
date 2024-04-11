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
const int MAXN = (int)1e6 + 7;
ll arr[MAXN], a, b;
int n;
vector<ll> divs;
ll rem[MAXN], cost[MAXN];
void addDivs(ll num) {
	if(num <= 1) return;
	for(ll i = 2; i * i <= num; ++i) {
		if(num % i == 0) {
			divs.push_back(i);
			while(num % i == 0) num /= i;
		}
	}
	if(num > 1) divs.push_back(num);
}
ll calc(ll d) {
	int L = NIL, R = NIL;
	for(int i = 0; i < n; ++i) {
		rem[i] = arr[i]%d;
		if(rem[i] != 0 && rem[i] != 1 && rem[i] != d - 1) {
			if(L == NIL) L = i;
			R = i;
		}
	}
	if(L != NIL) {
		ll rez = 0;
		for(int i = 0; i < n; ++i) {
			if(i >= L && i <= R) {
				cost[i] = a;
			} else if(rem[i] == 0) {
				cost[i] = 0;
			} else {
				cost[i] = b;
			}
			rez += cost[i];
		}
		ll left = 0, leftChange = 0;
		ll right = 0, rightChange = 0;
		for(int i = L - 1; i >= 0; --i) {
			left += a - cost[i];
			leftChange = min(leftChange, left);
		}
		for(int i = R + 1; i < n; ++i) {
			right += a - cost[i];
			rightChange = min(rightChange, right);
		}
		rez += leftChange;
		rez += rightChange;
		return rez;
	} else {
		ll rez = 0;
		for(int i = 0; i < n; ++i) {
			if(rem[i] == 0) {
				cost[i] = 0;
			} else {
				cost[i] = b;
			}
			rez += cost[i];
		}
		ll pref = 0, mxpref = 0, change = 0;
		for(int i = 0; i < n; ++i) {
			pref += a - cost[i];
			change = min(change, pref - mxpref);
			mxpref = max(mxpref, pref);
		}
		rez += change;
		return rez;
	}
}
void solve() {
	cin >> n >> a >> b;
	for(int i = 0; i < n; ++i) cin >> arr[i];
	addDivs(arr[0]);
	addDivs(arr[n - 1]);
	addDivs(arr[0] + 1);
	addDivs(arr[0] - 1);
	addDivs(arr[n - 1] + 1);
	addDivs(arr[n - 1] - 1);
	sort(divs.begin(), divs.end());
	divs.erase(unique(divs.begin(), divs.end()), divs.end());
	DBG(divs);
	ll answ = LL_INF;
	for(auto& d: divs) answ = min(answ, calc(d));
	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}