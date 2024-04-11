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
#define N 110

ll n, m, a, b, grid[N][N], ct[N];

bool works(ll o) {
    F(i, 0, n) fill_n(grid[i], m, 0);
    fill_n(ct, m, b);
    F(i, 0, n) F(j, 0, a) grid[i][(j + i * o) % m] = 1, ct[(j + i * o) % m]--;
    if(*min_element(ct, ct + m) || *max_element(ct, ct + m)) return false;
    cout << "YES\n";
    F(i, 0, n) {
        F(j, 0, m) cout << grid[i][j];
        cout << '\n';
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n >> m >> a >> b;
        F(i, 0, n) fill_n(grid[i], n, 0);
        bool done = false;
        F(i, 0, m + 1) if(works(i)) { done = true; break; }
        if(!done) cout << "NO\n";
    }
}