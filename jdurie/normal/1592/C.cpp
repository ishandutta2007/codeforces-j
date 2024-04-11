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

vector<ll> tree[N];
ll a[N], xr;
bool b;

bool dfs(ll i, ll p) {
    ll t = 0;
    for(ll j : tree[i]) if(j - p) {
        if(dfs(j, i)) t++;
        a[i] ^= a[j];
    }
    if(!a[i] && t) b = true;
    if(t >= 2) b = true;
    return (a[i] == xr || t);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(k)
        F(i, 1, n + 1) cin >> a[i];
        F(i, 0, n - 1) {
            G(u) G(v)
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        xr = 0;
        F(i, 1, n + 1) xr ^= a[i];
        if(!xr) cout << "YES\n";
        else if(k == 2) cout << "NO\n";
        else {
            b = false;
            dfs(1, 1);
            cout << (b ? "YES\n" : "NO\n");
        }
        F(i, 1, n + 1) tree[i].clear();
    }
}