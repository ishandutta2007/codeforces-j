#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }

void solve()
{
	int n;
	cin >> n;

	vector<ll> arr(n);

	for(auto& el: arr)
		cin >> el;

	sort(arr.begin(), arr.end());

	ll sum = 0;
	ll ans = 0;

	for(auto el: arr)
		sum += el;

	ans = sum;

	for(int i = 1; i < n; ++i)
	{
		vector<ll> divs;

		for(ll j = 1; j * j <= arr[i]; ++j)
		{
			if(arr[i] % j == 0)
			{
				divs.push_back(j);

				if(j * j < arr[i])
					divs.push_back(arr[i] / j);
			}
		}

		for(auto d: divs)
		{
			ll sm = sum - arr[0] - arr[i] + d * arr[0] + arr[i] / d;
			ans = min(ans, sm);
		}
	}

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}