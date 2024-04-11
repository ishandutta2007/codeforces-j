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

#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e18);

const ll mod = 1e9 + 7;
const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

const int MAX_N = 18;
bool bad[1 << MAX_N];
int prefsum[1 << MAX_N];

void solve()
{
	int n, x;
	cin >> n >> x;

	prefsum[0] = 0;
	bad[x] = true;
	int ptr = 1;

	for(int i = 1; i < (1 << n); ++i)
	{
		if(bad[i])
			continue;

		if((i ^ x) < (1 << n))
			bad[i ^ x] = true;

		prefsum[ptr] = i;
		++ptr;
	}

	cout << ptr - 1 << endl;

	for(int i = 1; i < ptr; ++i)
		cout << (prefsum[i - 1] ^ prefsum[i]) << " ";

	cout << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}