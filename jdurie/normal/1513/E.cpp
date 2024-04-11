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
#define M 1000000007 //998244353
#define N 100010

ll f[N], fi[N], a[N];

ll inv(ll a, ll b = M) { return 1 < a ? b - inv(b % a, a) * b / a : 1; } //inv a mod b

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    f[0] = fi[0] = 1;
    F(i, 1, N) f[i] = i * f[i - 1] % M, fi[i] = inv(f[i]);
    G(n) ll sm = 0;
    map<ll, ll> ct;
    F(i, 0, n) { cin >> a[i]; ct[a[i]]++; sm += a[i]; }
    if(sm % n) EX(0)
    ll b = 0, s = 0;
    F(i, 0, n) if(a[i] > sm / n) b++; else if(a[i] < sm / n) s++;
    if(min(b, s) < 2) {
        ll ans = f[n];
        for(pl p : ct) ans = ans * fi[p.V] % M;
        EX(ans)
    }
    ll ans = f[n] * fi[n - ct[sm / n]] % M % M;
    for(pl p : ct) ans = ans * fi[p.V] % M;
    ans = ans * f[b] % M * f[s] % M;
    cout << 2 * ans % M << '\n';
}