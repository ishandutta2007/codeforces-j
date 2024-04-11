#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
template<class T, class S>
ostream& operator << (ostream &o, const pair<T, S> &p) {
    return o << '(' << p.first << ", " << p.second << ')';
}
template<template<class, class...> class T, class... A>
typename enable_if<!is_same<T<A...>, string>(), ostream&>::type
operator << (ostream &o, T<A...> V) {
	o << '[';
	for(auto a : V) o << a << ", ";
	return o << ']';
}

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;

#define G(x) ll x; cin >> x;
#define GD(x) ld x; cin >> x;
#define GS(s) string s; cin >> s;
#define F(i, l, r) for(ll i = l; i < (r); ++i)
#define FD(i, r, l) for(ll i = r; i > (l); --i)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 998244353
#define N 200010

ll n, dp[N][2][2][2][2][2][2];
string s;

#define DP dp[i][ae][be][ce][ga][gb][gc]
ll r(ll i, ll ae, ll be, ll ce, ll ga, ll gb, ll gc) {
    if(~DP) return DP;
    if(i == n) return DP = ga * gb * gc;
    DP = 0;
    for(ll a = 0; a <= (ae ? s[i] - '0' : 1); ++a)
        for(ll b = 0; b <= (be ? s[i] - '0' : 1); ++b)
            for(ll c = 0; c <= (ce ? s[i] - '0' : 1); ++c) {
                ll nga = ga || (b != a && a != c);
                ll ngb = gb || (a != b && b != c);
                ll ngc = gc || (a != c && c != b);
                ll na = ae && a == s[i] - '0';
                ll nb = be && b == s[i] - '0';
                ll nc = ce && c == s[i] - '0';
                DP = (DP + r(i + 1, na, nb, nc, nga, ngb, ngc)) % M;
            }
    return DP;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> s; n = s.size();
    cout << r(0, 1, 1, 1, 0, 0, 0) << '\n';
}