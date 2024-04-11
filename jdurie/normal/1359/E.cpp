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
#define M 998244353
#define N 500010

ll f[N];

ll pw(ll a, ll p) {
    if(!p) return 1;
    ll t = pw(a, p / 2);
    return t * t % M * (p % 2 ? a : 1) % M;
}

ll inv(ll a) { return pw(a, M - 2); }

ll ch(ll n, ll r) { return f[n] * inv(f[r]) % M * inv(f[n - r]) % M; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    f[0] = 1;
    F(i, 1, N) f[i] = f[i - 1] * i % M;
    G(n) G(k)
    ll x = 1, ans = 0;
    while(k * x <= n) { ans = (ans + ch(n / x - 1, k - 1)) % M; x++; }
    cout << ans << '\n';
}