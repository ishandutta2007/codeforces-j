#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// use merge(all(vec1), all(vec2), vec3.begin()) to merge 2 vectors, use vec3.resize(vec1.size() + vec2.size()) first
// ll pos = partition_point(all(vec), pred) - vec.begin(); bool pred(ll a){return a<3};
// print number in binary -> cout << bitset<20>(n);

const int N=200010;
int a[N];
int main(){
	int t;cin>>t;
	for(int tc=0;tc<t;++tc){
		int n;cin>>n;
		ll sm=0;
		for(int i=0;i<n;++i)cin>>a[i];
		for(int i=0;i<n;++i)if(i%2==0)sm+=a[i];
		ll bsm=0,csm=0;
		for(int i=0;i+1<n;i+=2){
			csm+=-a[i]+a[i+1];
			if(csm>bsm)bsm=csm;
			if(csm<0)csm=0;
		}
		csm=0;
		for(int i=1;i+1<n;i+=2){
			csm+=a[i]-a[i+1];
			if(csm>bsm)bsm=csm;
			if(csm<0)csm=0;
		}
		cout<<sm+bsm<<endl;
	}
}