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

const ll mod = 1e9 + 7;
const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

const int MAX_N = 3007;

int t[MAX_N][MAX_N], vmin[MAX_N][MAX_N];
int n, m, a, b;

ll x, y, z;

struct SlidingMinimum
{
	deque<int> q;

	SlidingMinimum()
	{
	}

	inline void append(int x, int old)
	{
		while(!q.empty() && q.back() > x)
			q.pop_back();

		q.push_back(x);
	
		if(q.front() == old)
			q.pop_front();
	}

	inline int get()
	{
		return q.front();
	}
};

void solve()
{
	ll g;

	cin >> n >> m >> a >> b;
	cin >> g >> x >> y >> z;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			t[i][j] = g;

			g = (x * g + y) % z;
		}
	}

#ifdef __LOCAL

	cout << "---- t ---- " << endl;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
			cout << t[i][j] << " ";

		cout << endl;
	}

#endif

	for(int col = 0; col < m; ++col)
	{
		SlidingMinimum st;

		for(int i = 0; i < n; ++i)
		{
			st.append(t[i][col], i - a >= 0 ? t[i - a][col] : NIL);
			vmin[i][col] = st.get();
		}
	}

#ifdef __LOCAL

	cout << "---- vmin ---- " << endl;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
			cout << vmin[i][j] << " ";

		cout << endl;
	};

#endif

	ll answ = 0;

	for(int row = a - 1; row < n; ++row)
	{
		SlidingMinimum st;

		for(int j = 0; j < m; ++j)
		{
			st.append(vmin[row][j], j - b >= 0 ? vmin[row][j - b] : NIL);

			if(j >= b - 1)
			{
				answ += (ll)st.get();

				DBG(st.get());
				DBG(row);
				DBG(j);
			}
		}
	}

	cout << answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}