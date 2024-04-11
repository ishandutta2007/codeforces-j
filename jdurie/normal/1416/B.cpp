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
#define M 1000000007 //998244353
#define N 100010

ll a[N];
vector<pair<pl, ll>> ops;

void doOp(ll i, ll j, ll x) {
    if(x) {
        a[i] -= (i + 1) * x;
        a[j] += (i + 1) * x;
        ops.push_back({{i + 1, j + 1}, x});
    }
}

void doTC() {
    ops.clear();
    G(n) ll sm = 0;
    F(i, 0, n) cin >> a[i], sm += a[i];
    if(sm % n) { cout << "-1\n"; return; }
    F(i, 1, n) {
        doOp(0, i, (i + 1 - (a[i] % (i + 1))) % (i + 1));
        doOp(i, 0, a[i] / (i + 1));
    }
    F(i, 1, n) doOp(0, i, sm / n);
    cout << ops.size() << '\n';
    for(auto x : ops) cout << x.K.K << ' ' << x.K.V << ' ' << x.V << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) doTC();
}