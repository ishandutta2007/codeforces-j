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
#define N 2010

ll a[N];
map<ll, ll> ct;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        ct.clear();
        G(n)
        bool ok = false;
        F(i, 0, 2 * n) { cin >> a[i]; ct[a[i]]++; }
        sort(a, a + 2 * n);
        F(j, 0, 2 * n - 1) {
            map<ll, ll> tmp = ct;
            tmp[a[j]]--;
            tmp[a[2 * n - 1]]--;
            vector<pl> ans = {{a[2 * n - 1], a[j]}};
            ll cur = 2 * n - 2, v = a[2 * n - 1];
            while(1) {
                while(cur >= 0 && !tmp[a[cur]]) cur--;
                if(cur < 0) break;
                if(!tmp[v - a[cur]] || (v == 2 * a[cur] && tmp[a[cur]] < 2)) break;
                tmp[a[cur]]--;
                tmp[v - a[cur]]--;
                ans.emplace_back(a[cur], v - a[cur]);
                v = a[cur];
            }
            if(ans.size() == n) {
                ok = true;
                cout << "YES\n" << ans[0].K + ans[0].V << '\n';
                for(pl p : ans) cout << p.K << ' ' << p.V << '\n';
                break;
            }
        }
        if(!ok) cout << "NO\n";
    }
}