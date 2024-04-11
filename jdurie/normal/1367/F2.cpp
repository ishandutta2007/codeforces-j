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
#define N 200010

pl a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n)
        F(i, 0, n) { G(x) a[i] = {x, -i}; }
        sort(a, a + n);
        ll ans = n, gOps = 0;
        set<pl> inds, nums;
        ll lastNum = M;
        vector<pair<pl, pl>> insts;
        FD(i, n - 1, -1) {
            if(a[i].K != lastNum) {
                for(auto p : insts) { inds.insert(p.K); nums.insert(p.V); }
                insts.clear();
            }
            while(inds.size() && inds.rbegin()->K > a[i].V) {
                pl mx = *nums.rbegin();
                inds.erase({mx.V, mx.K});
                nums.erase(mx);
                gOps++;
            }
            ans = min(ans, i + gOps);
            lastNum = a[i].K;
            insts.push_back({{a[i].V, a[i].K}, a[i]});
        }
        cout << ans << '\n';
    }
}