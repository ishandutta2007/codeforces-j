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
#define F(i, l, r) for(ll i = l; i < r; i++)
#define FD(i, r, l) for(ll i = r; i > l; i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}" << endl; }
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define M 1000000007 //998244353
#define N 100010

ll v[N], c[N], dp[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(n) G(q)
    F(i, 0, n) cin >> v[i];
    F(i, 0, n) cin >> c[i];
    while(q--) {
        G(a) G(b)
        F(i, 1, n + 1) dp[i] = LLONG_MAX;
        ll maxC = n + 1, sMaxC = n + 1, maxAns = 0;
        F(i, 0, n) {
            ll value = dp[c[i] == maxC ? sMaxC : maxC] + b * v[i];
            if(dp[c[i]] != LLONG_MAX) value = max(value, dp[c[i]] + a * v[i]);
            if(value >= dp[maxC] && c[i] != maxC) {
                sMaxC = maxC;
                maxC = c[i];
            } else if(value > dp[sMaxC] && c[i] != maxC) sMaxC = c[i];
            dp[c[i]] = dp[c[i]] == LLONG_MAX ? value : max(dp[c[i]], value);
            maxAns = max(maxAns, value);
        }
        cout << maxAns << '\n';
    }
}