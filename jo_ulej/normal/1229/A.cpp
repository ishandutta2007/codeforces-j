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

inline int dominate(ll lhs, ll rhs)
{
	return (lhs & (~rhs)) > 0;
}

void solve()
{
	int n;
	cin >> n;

	vector<pll> a(n);

	for(int i = 0; i < n; ++i)
		cin >> a[i].first;

	for(int i = 0; i < n; ++i)
		cin >> a[i].second;

	while(!a.empty())
	{
		int ok = 1;
		ll fsum = 0;
		vector<pll> b;
		n = len(a);

		for(int i = 0; i < n; ++i)
		{
			int flag = 0;
			fsum += a[i].second;

			for(int j = 0; j < n; ++j)
			{
				if(i == j)
					continue;

				if(!dominate(a[i].first, a[j].first))
					flag = 1;		
			}

			ok &= flag;

			if(flag)
				b.push_back(a[i]);
		}

		if(ok)
		{
			cout << fsum << endl;
			return;
		}

		a = b;
	}

	cout << "0" << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}