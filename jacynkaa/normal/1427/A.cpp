#include <bits/stdc++.h>
#include <math.h>
#include <chrono>
using namespace std;
#pragma GCC optimize("-O3")
#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10), cin.tie(0), cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).size())
#define what(x) cerr << #x << " is " << x << endl;

int32_t main()
{
    _upgrade;
    int Z;
    cin >> Z;
    while (Z--)
    {
        int n;
        cin >> n;
        vector<int> A(n);
        rep(i, n) cin >> A[i];
        int sum = accumulate(all(A), 0);
        if (sum == 0)
        {
            cout << "NO" << endl;
            continue;
        }
        sort(all(A));
        cout << "YES" << endl;
        if (sum < 0)
        {
            for (int a : A)
                cout << a << " ";
        }
        else
        {
            reverse(all(A));
            for (int a : A)
                cout << a << " ";
        }
        cout << endl;
    }
}