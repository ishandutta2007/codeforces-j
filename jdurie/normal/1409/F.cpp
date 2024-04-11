#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
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
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define FD(i, r, l) for(ll i = r; i > (l); i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000000000007 //998244353
#define N 210

ll dp[N][N][N], n, k;
string s, t;

#define DP dp[i][us][p]
ll r(ll i, ll us, ll p) {
    if(p < 0 || p > i + 1) return -M;
    if(i < 0) return 0;
    if(~DP) return DP;
    DP = -M;
    if(s[i] == t[0]) DP = max(DP, r(i - 1, us, p - 1));
    else if(s[i] == t[1]) DP = max(DP, r(i - 1, us, p) + p);
    else DP = max(DP, r(i - 1, us, p));
    if(us) {
        DP = max(DP, r(i - 1, us - 1, p - 1));
        DP = max(DP, r(i - 1, us - 1, p) + p);
    }
    if(DP < 0) DP = -M;
    return DP;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> k >> s >> t;
    if(t[0] == t[1]) {
        ll ct = 0;
        for(char c : s) if(c == t[0]) ct++;
        ll ans = min(n, ct + k);
        cout << ans * (ans - 1) / 2 << '\n';
    } else {
        ll mx = 0;
        F(i, 0, n + 1) mx = max(mx, r(n - 1, k, i));
        cout << mx << '\n';
    }
}