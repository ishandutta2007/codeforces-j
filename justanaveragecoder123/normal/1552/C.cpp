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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
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

using ll = long long;
using ull = unsigned long long ;
using ld = long double ;
using str = string;
using ordered_set=tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update>;

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
		int n,k;
		cin>>n>>k;
		vector<pair<int,int>> edgs(k);
		vector<int> taken(2*n+1);
		for(int i=0;i<k;++i) {
			int a,b;
			cin>>a>>b;
			taken[a]=1;
			taken[b]=1;
			edgs[i]={a,b};
		}
		
		auto inter=[&](int a, int b, int c, int d) -> bool {
			if(a>b) swap(a,b);	
			int cnt=(a<=c && c<=b)+(a<=d && d<=b);
			return cnt==1;
		};
		
		//~ LOG(inter(2,20,15,12));
		
		int ans=0;
		for(int i=0;i<k;++i) {
			for(int j=i+1;j<k;++j) {
				if(inter(edgs[i].xx, edgs[i].yy, edgs[j].xx, edgs[j].yy)) {
					//~ cerr<<i<<" "<<j<<" "<<edgs[i].xx<<" "<<edgs[i].yy<<" "<<edgs[j].xx<<" "<<edgs[j].yy<<"\n";
					ans++;
				}
			}
		}
		//~ LOG(ans);
		
		vector<int> rem;
		for(int i=1;i<=2*n;++i) {
			if(!taken[i]) {
				rem.pb(i);
				//~ LOG(i);
			}
		}
		
		ans+=sz(rem)/2*(sz(rem)/2-1)/2;
		
		for(int i=0;i<sz(rem)/2;++i) {
			for(int j=0;j<k;++j) {
				if(inter(edgs[j].xx, edgs[j].yy,rem[i],rem[i+sz(rem)/2])) ans++;
			}
		}
	
		cout<<ans<<"\n";
		
	
	}
	return 0;
}