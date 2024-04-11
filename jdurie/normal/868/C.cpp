//ICPC Template
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
typedef pair<ll, ll> pl;

#define G(x) ll x; cin >> x;
#define GS(s) string s; cin >> s;
#define F(i, l, r) for(ll i = l; i < (r); ++i)
#define A(x) (x).begin(), (x).end()
#define K first
#define V second
#define N 1000010

vector<ll> pos[256];

string encode(string s) {
    string t;
    for(char c : s) if((c - '0') & 1) t.push_back('1'); else t.push_back('0');
    while(t.size() < 70) t = "0" + t;
    return t;
}

ll a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    G(n) G(k)
    set<ll> m;
    while(n--) {
        ll z = 0;
        F(i, 0, k) { G(x) z = 2 * z + x; }
        if(!z) { cout << "YES\n"; exit(0); }
        F(i, 0, 16) if(m.count(i) && !(i & z)) { cout << "YES\n"; exit(0); }
        m.insert(z);
    }
    cout << "NO\n";
}