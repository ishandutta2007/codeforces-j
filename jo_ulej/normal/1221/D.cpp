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
	#define DBG(X) cout << #X << "=" << (X) << endl;
#else
	#define DBG(X)
	#define endl '\n'
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
template<typename T> inline void goodbye(const T& val) { cout << val << endl; exit(0); }

const int MAX_N = (int)3e5 + 77;
const int MAX_CH = 17;

int n, arr[MAX_N];
ll cost[MAX_N];
ll dp[MAX_N][MAX_CH];

void solve()
{
	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> arr[i] >> cost[i];

	for(int j = 0; j < MAX_CH; ++j)
		dp[0][j] = cost[0] * 1LL * j;

	for(int i = 1; i < n; ++i)
	{
		for(int j = 0; j < MAX_CH; ++j)
		{
			dp[i][j] = LL_INF;

			for(int p = 0; p < MAX_CH; ++p)
			{
				if(arr[i - 1] + p == arr[i] + j)
					continue;

				ll local = j * 1LL * cost[i] + dp[i - 1][p];
				dp[i][j] = (local > dp[i][j] ? dp[i][j] : local);
			}
		}
	}

	ll answ = LL_INF;

	for(int j = 0; j < MAX_CH; ++j)
		answ = min(answ, dp[n - 1][j]);

	cout << answ << endl;
}

int main()
{
	fast_io();

	int q;
	cin >> q;
	while(q--)
		solve();

	return 0;
}