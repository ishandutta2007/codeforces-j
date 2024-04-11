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
//#define N 100010

map<pl, ll> qs;

ll query(ll l, ll r) {
    if(l == r) return -1;
    if(!qs.count({l, r})) { 
        cout << "? " << l << ' ' << r << endl;
        cin >> qs[{l, r}];
    }
    return qs[{l, r}];
}

ll solve(ll l, ll r) {
    if(l == r) return l;
    ll m = (l + r) / 2;
    ll i = query(l, r);
    if(i <= m) return query(l, m) == i ? solve(l, m) : solve(m + 1, r);
    else return query(m + 1, r) == i ? solve(m + 1, r) : solve(l, m);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) ll i = solve(1, n);
    cout << "! " << i << endl;
}