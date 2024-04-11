//Codeforces Template
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
#define N 1010

bool grid[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) F(i, 0, n) fill_n(grid[i], n, 0);
        F(k, 0, 2) F(i, 0, n) { 
            GS(s) F(j, 0, n) if(s[j] == '1') grid[i][j] = !grid[i][j];
        }
        string ans = "YES\n";
        F(j, 0, n - 1) F(i, 1, n) if((grid[i][j] == grid[i][j + 1]) != (grid[0][j] == grid[0][j + 1])) ans = "NO\n";
        F(i, 0, n - 1) F(j, 1, n) if((grid[i][j] == grid[i + 1][j]) != (grid[i][0] == grid[i + 1][0])) ans = "NO\n";
        cout << ans;
    }
}