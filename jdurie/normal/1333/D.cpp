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

typedef int ll;
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
#define N 3010

vector<ll> ps, ans[N * N], ans2[N * N];
ll a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(k) GS(s)
    F(i, 0, n) a[i] = s[i] == 'R' ? 1 : 0;
    F(i, 0, n - 1) if(a[i] && !a[i + 1]) ps.push_back(i);
    ll idx = 0;
    while(ps.size()) {
        vector<ll> newps;
        for(ll i : ps) {
            ans[idx].push_back(i + 1);
            a[i] = 0; a[i + 1] = 1;
            if(i && a[i - 1]) newps.push_back(i - 1);
            if(i + 2 < n && !a[i + 2]) newps.push_back(i + 1);
        }
        idx++;
        ps = newps;
    }
    if(idx > k) EX(-1)
    ll ext = k - idx, idx2 = 0;
    F(i, 0, idx) {
        ll q = 0;
        while(((ll)ans[i].size()) - q > 1 && ext) {
            ans2[idx2++].push_back(ans[i][q++]);
            ext--;
        }
        F(j, q, ans[i].size()) ans2[idx2].push_back(ans[i][j]);
        idx2++;
    }
    if(idx2 < k) EX(-1)
    F(i, 0, k) {
        cout << ans2[i].size();
        for(ll j : ans2[i]) cout << ' ' << j;
        cout << '\n';
    }
}