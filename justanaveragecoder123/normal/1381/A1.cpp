#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<cassert>
#include<cassert>
#include<unordered_map>
#include<unordered_set>
#include<functional>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<sstream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<numeric>
#include<random>
#include<chrono>
#include<bitset>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define xx first
#define yy second
#define sz(x) (int)(x).size()
#define gc getchar
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mp make_pair

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr << #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double PI=acos(-1);
const ll INF = 1LL<<62;
const ll MINF = -(1LL<<62);

template<typename T> T getint() {
	T val=0;
	char c;
	
	bool neg=false;
	while((c=gc()) && !(c>='0' && c<='9')) {
		neg|=c=='-';
	}

	do {
		val=(val*10)+c-'0';
	} while((c=gc()) && (c>='0' && c<='9'));

	return val*(neg?-1:1);
}

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); uniform_int_distribution<int>(0, n-1)(rng)


int main() {
	IO;
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		vector<int> A,B;
		string a,b;
		cin>>a>>b;
		
		for(auto i:a) A.pb(i-'0');
		for(auto i:b) B.pb(i-'0');
		
		vector<int> ans;
		for(int i=sz(B)-1;i>=0;i--) {
			if(B[i]==1-A[0]) {
				ans.pb(i+1);
				reverse(A.begin(), A.begin()+i+1);
				for(int j=0;j<=i;++j) A[j]=1-A[j];
			}else {
				ans.pb(1);
				ans.pb(i+1);
				A[0]=1-A[0];
				reverse(A.begin(), A.begin()+i+1);
				for(int j=0;j<=i;++j) A[j]=1-A[j];
			}
		}
		cout<<sz(ans);
		for(auto i:ans) {
			cout<<" "<<i;
		}cout<<"\n";
		
	}
	return 0;
}