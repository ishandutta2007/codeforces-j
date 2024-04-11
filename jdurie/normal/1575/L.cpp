#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef priority_queue<pl, vector<pl>, greater<pl> > pq;
 
template<class T, class S>
ostream& operator<<(ostream &o, pair<T, S> p) {
    return o<<'('<<p.first<<", "<<p.second<<')';
}
 
template<template<class, class...> class T, class... A>
typename enable_if<!is_same<T<A...>, string>(), ostream&>::type
operator<<(ostream &o, T<A...> V) {
	o<<'[';
	for(auto a:V) o<<a<<", ";
	return o<<']';
}
 
// This is tuples, _p is helper
template<ll i, class... T>
typename enable_if<i==sizeof...(T)>::type _p(ostream& o, tuple<T...> t) {}
 
template<ll i, class... T>
typename enable_if<i<sizeof...(T)>::type _p(ostream& o, tuple<T...> t) {
    _p<i+1>(o << get<i>(t)<< ", ", t);
}
 
template<class... T>
ostream& operator<<(ostream& o, tuple<T...> t) {
    _p<0>(o<<'(', t);
    return o<<')';
}
 
 
#define G(x) ll x; cin >> x;
#define Gs(s) string s; cin >> s;
#define Gd(x) ld x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define F1(i, l, r) for(ll i = l; i >= (r); i--)
#define Fi(i, s) for(auto i = (s).begin(); i != (s).end(); i++)
#define L G(_t) F(_t1, 0, _t)
#define H(ar, n) vector<ll> ar(n); F(_i, 0, n) cin >> ar[_i];
#define A first
#define B second
#define PA(ar, n) F(_i, 0, n) cout << (ar)[_i] << " "; cout << endl; 
#define PB push_back
#define V vector
#define CASE cout << "Case #" << _t1 + 1 << ": " 
#define CC << " " <<
#define BE(ar) ar.begin(), ar.end()
#define CO(x) cout << (x) << endl;
#define D(x) ((x) - '0')
#define EX(x) {cout << (x) << endl; return 0;}
#define S(ar, val) memset(ar, val, sizeof(ar));
ll M = 1000000007; //998244353;
ll inv(ll a, ll b){return 1<a ? b - inv(b%a,a)*b/a : 1;}
ll gcd(ll x, ll y){if(y == 0) return x; return gcd(y, x % y); }
pl neigh[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
 
#define NN 400010

namespace seg {
typedef ll T;
T id = 0;
T f(T a, T b) { return max(a,b); }

T t[2 * NN];
ll n = NN; // array size

void modify(ll p, T value) { // set value at position p
  for (p += n, t[p] = value; p /= 2;)
    t[p] = f(t[2 * p], t[2 * p + 1]);
}

T query(ll l, ll r) { // fold f on interval [l, r)
  T resl = id, resr = id;
  for (l += n, r += n; l < r; l /= 2, r /= 2) {
    if (l & 1)
      resl = f(resl, t[l++]);
    if (r & 1)
      resr = f(t[--r], resr);
  }
  return f(resl, resr);
}
} // namespace seg

int main() {
    G(n)
    H(a, n)
    V<pl> nex;
    F(i, 0, n){
        if(a[i] <= i+1){
            nex.PB({(i+1)-a[i], i});
        }
    }
    sort(BE(nex));
    F(i, 0, nex.size()){
      ll q = 200000-(nex[i].A - nex[i].B); 
      seg::modify(q, seg::query(0, q)+1);
    }
    cout << seg::query(0, NN) << endl;
}