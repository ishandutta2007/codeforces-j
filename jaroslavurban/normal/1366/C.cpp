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

int main(){
	int t;cin>>t;
	for(int tc=0;tc<t;++tc){
		int rnum1[70]={};
		int rnum0[70]={};
		int n,m;cin>>n>>m;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j){
				int val;
				cin>>val;
				int len=min(i+j,n-i+m-j-2);
				if(val)rnum1[len]++;
				else rnum0[len]++;
			}
		ll res=0;
		for(int i=0;i<70;++i)if(!((n+m)%2==0&&i==(n+m)/2-1)){
			res+=min(rnum1[i],rnum0[i]);
		}
		cout<<res<<endl;
	}
}