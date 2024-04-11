#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);
const int N=50010;

int a[N];
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		string s;cin>>s;
		vector<int>lens;
		int cur=0;
		for(int i=0;i<s.size();++i)
			if(s[i]=='0'){lens.push_back(cur);cur=0;}
			else ++cur;
		lens.push_back(cur);
		int res=0;
		sort(lens.rbegin(),lens.rend());
		for(int i=0;i<lens.size();i+=2)res+=lens[i];
		cout<<res<<endl;
	}
}