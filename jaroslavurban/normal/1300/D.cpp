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
#define inf 9223372036854775807
#define mod 998244353
// #define endl '\n'
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// use merge(all(vec1), all(vec2), vec3.begin()) to merge 2 vectors, use vec3.resize(vec1.size() + vec2.size()) first
// ll pos = partition_point(all(vec), pred) - vec.begin(); bool pred(ll a){return a<3};
// print number in binary -> cout << bitset<20>(n);
ll nxt() {ll x; cin >> x; return x;}

void solve(ll test_number){
	ll n=nxt();
	if(n%2){
		cout<<"NO\n";
		return;
	}
	vec<pair<ll,ll>>vecs(n);
	ll prevx=nxt(),prevy=nxt();
	ll firstx=prevx,firsty=prevy;
	ll x,y;
	for(ll i=0;i<n-1;++i){
		x=nxt(),y=nxt();
		vecs[i]={x-prevx,y-prevy};
		prevx=x;prevy=y;
	}
	vecs[n-1]={firstx-x,firsty-y};
	for(ll i=0;i<n/2;++i){
		// cout<<vecs[i].ff<<" "<<vecs[i].ss<<endl;
		// cout<<vecs[i+n/2].ff<<" "<<vecs[i+n/2].ss<<endl;
		if((vecs[i].ff!=-vecs[n/2+i].ff||
			vecs[i].ss!=-vecs[n/2+i].ss)){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	ll t = 1;
	// cin >> t;
	for (ll i = 0; i < t; ++i){ 
		solve(i);
	}
}