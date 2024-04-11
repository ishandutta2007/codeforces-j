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
	int t,n;
	cin>>t;
	for(int i=0;i<t;++i){
		cin>>n;
		vector<int>gr(n);
		for(int i=0;i<n;++i)cin>>gr[i];
		sort(gr.begin(),gr.end());
		int res=1;
		for(int i=0;i<n;++i)
			if(i+1>=gr[i])
				res=i+2;
		cout<<res<<endl;
	}
}