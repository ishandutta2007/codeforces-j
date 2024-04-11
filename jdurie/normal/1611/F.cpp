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
#define N 200010

namespace sgtree {
    typedef ll T;
    T id = 0, t[2 * N];

    T f(T a, T b) { return min(a, b); }

    void modify(ll p, T v) { //set value v at position p
        for(t[p += N] = v; p /= 2;) t[p] = f(t[2 * p], t[2 * p + 1]);
    }

    T query(ll l, ll r) { //query on interval [l, r)
        T resl = id, resr = id;
        for(l += N, r += N; l < r; l /= 2, r /= 2) {
            if(l & 1) resl = f(resl, t[l++]);
            if(r & 1) resr = f(t[--r], resr);
        }
        return f(resl, resr);
    }
}

ll s, a[N];

ll bsch(ll l, ll r, ll i) {
    if(l == r) return l;
    ll m = (l + r + 1) / 2;
    return s + (sgtree::query(i, m + 1) - a[i - 1]) >= 0 ? bsch(m, r, i) : bsch(l, m - 1, i);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) cin >> s;
        F(i, 1, n + 1) {
            cin >> a[i];
            a[i] += a[i - 1];
            sgtree::modify(i, a[i]);
        }
        pl bp = {-1, -1};
        F(i, 1, n + 1) if(s + (a[i] - a[i - 1]) >= 0) {
            ll j = bsch(i, n, i);
            if(j - i >= bp.V - bp.K) bp = {i, j};
        }
        if(!~bp.K) cout << "-1\n";
        else cout << bp.K << ' ' << bp.V << '\n';
    }
}