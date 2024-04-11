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

ll pZs[N], pOs[N], sZs[N], sOs[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(tc) while(tc--) {
        GS(s)
        ll n = s.size();
        F(i, 0, n) {
            if(i) {
                pZs[i] = pZs[i - 1];
                pOs[i] = pOs[i - 1];
            } else pZs[i] = pOs[i] = 0;
            if(s[i] == '0') pZs[i]++; else pOs[i]++;
        }
        FD(i, n - 1, -1) {
            if(i != n - 1) {
                sZs[i] = sZs[i + 1];
                sOs[i] = sOs[i + 1];
            } else sZs[i] = sOs[i] = 0;
            if(s[i] == '0') sZs[i]++; else sOs[i]++;
        }
        sZs[n] = sOs[n] = 0;
        ll ans = n;
        F(i, 0, n) ans = min(ans, min(pZs[i] + sOs[i + 1], pOs[i] + sZs[i + 1]));
        cout << ans << '\n';
    }
}