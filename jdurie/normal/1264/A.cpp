#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
template<class T, class S>
ostream& operator << (ostream &o, const pair<T, S> &p) {
    return o << '(' << p.first << ", " << p.second << ')';
}

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef complex<ld> pt;

#define G(x) ll x; cin >> x;
#define GD(x) ld x; cin >> x;
#define GS(s) string s; cin >> s;
#define F(i, l, r) for(ll i = l; i - r; i < r ? i++ : i--)
#define P(a) { cout << #a << " "; for(auto _ : a) cout << _ " "; cout << endl; }
#define PN(a, n) { cout << #a << " "; F(_, 0, n) cout << a[_] << " "; cout << endl; }
#define CE(a, x) lower_bound(a.begin(), a.end(), x)
#define UP(a, x) upper_bound(a.begin(), a.end(), x)
#define FL(a, x) (x < *a.begin() ? a.end() : --UP(a, x))
#define LO(a, x) (x <= *a.begin() ? a.end() : --CE(a, x))
#define K first
#define V second
#define X real()
#define Y imag()
#define M 1000000007 //998244353
#define N 400010

ll a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    G(T) while(T--) {
        G(n)
        F(i, 0, n) cin >> a[i];
        ll iG = 0;
        while(a[iG + 1] == a[iG] && iG < n - 1) iG++;
        ll iL = n / 2;
        while(a[iL - 1] == a[iL] && iL > 1) iL--;
        if(a[iG + 1] == a[iL - 1] || iL < 3 * (iG + 1) + 2) {
            cout << "0 0 0" << endl;
            continue;
        }
        ll iS = 2 * (iG + 1);
        while(a[iS + 1] == a[iS] && iS < iL) iS++;
        if(iL - iS - 1 <= iG + 1)
            cout << "0 0 0" << endl;
        else
            cout << iG + 1 << " " << iS - iG << " " << iL - iS - 1 << endl;
    }
}