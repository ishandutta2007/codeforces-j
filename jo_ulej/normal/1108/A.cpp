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

const ll mod = 1e9 + 7;

void solve()
{
	int q;
	cin >> q;

	for(; q > 0; --q)
	{
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;

		if(l1 != l2)
			cout << l1 << " " << l2 << endl;
		else if(r1 != r2)
			cout << r1 << "  " << r2 << endl;
		else 
			cout << l1 << " " << r1 << endl;
	}
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}