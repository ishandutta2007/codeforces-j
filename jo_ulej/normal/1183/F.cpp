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

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n);

	for(auto& elem: a)
		cin >> elem;

	sort(a.rbegin(), a.rend());
	a.erase(unique(a.begin(), a.end()), a.end());
	n = len(a);

	int answer = 0;
	const int K = 120;

	for(int i = 0; i < K && i < n; ++i)
	{
		answer = max(answer, a[i]);

		for(int j = i + 1; j < K && j < n; ++j)
		{
			if(a[i] % a[j])
			{
				answer = max(answer, a[i] + a[j]);

				for(int k = j + 1; k < K && k < n; ++k)
				{
					if(a[i] % a[k] && a[j] % a[k])
						answer = max(answer, a[i] + a[j] + a[k]);
				}
			}
		}
	}

	cout << answer << "\n";
}

int main()
{
	fast_io();

	int T;
	cin >> T;

	for(; T; --T)
		solve();

	return 0;
}