#ifndef __PROGTEST__
#include <bits/stdc++.h>
using namespace std;
#endif // __PROGTEST__

typedef long long ll;
typedef long double ld;
#define pb(x) push_back(x)
#define ff first
#define ss second
#define vec vector
#define all(x) (x).begin(), (x).end()
#define mod 998244353
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use generate(all(vec), nxt) for filling a vector with function calls
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// use merge(all(vec1), all(vec2), vec3.begin()) to merge 2 vectors, use vec3.resize(vec1.size() + vec2.size()) first
// vec to a set -> use "set s(all(vec));"
// is key in a set/map? use s.count(key)
// ll pos = partition_point(all(vec), p) - vec.begin();
// print number in binary -> cout << bitset<20>(n);
// use min({a, b, c})
ll nxt() {ll x; cin >> x; return x;}

int main(){
	ll n = nxt(), k = nxt(), m = n - k;
	cout << (n+1)*n/2 - (m+1)*m/2 << " ";
	bool f = false;
	ll dist = 0;
	ll res = 1;
	for (ll i = 0; i < n; ++i){
		ll val;
		cin >> val;
		if (val > m){
			if (f) res = (res * dist)%mod;
			else f = true;
			dist = 0;
		}
		dist++;
	}
	cout << res << endl;
}