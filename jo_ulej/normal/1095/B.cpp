#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e7 + 9;

void solve()
{
	int n;
	vector<int> arr;

	cin >> n;
	arr.resize(n);

	for(int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	cout << min(arr[n - 1] - arr[1], arr[n - 2] - arr[0]) << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}