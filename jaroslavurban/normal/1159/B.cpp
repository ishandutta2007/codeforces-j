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

const int N=300010;
pair<int,int>a[N];
bool vis[N];
int main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int n;cin>>n;
	for(int i=0;i<n;++i){
		int aa;cin>>aa;
		a[i]={aa,i};
	}
	sort(a,a+n);
	int l=0,r=n-1;
	int mnk=1e9;
	for(int i=0;i<n-1;++i){
		while(vis[l])++l;
		while(vis[r])--r;
		if(l!=a[i].second)mnk=min(mnk,a[i].first/abs(a[i].second-l));
		if(r!=a[i].second)mnk=min(mnk,a[i].first/abs(a[i].second-r));
		vis[a[i].second]=true;
	}
	cout<<mnk<<endl;

}