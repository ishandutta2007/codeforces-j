#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<utility>
#include<functional>
#include<iomanip>
#include<sstream>
#include<ctime>
#include<cassert>
using namespace std;
#define y0 y0z
#define y1 y1z
#define yn ynz
#define j0 j0z
#define j1 j1z
#define jn jnz
#define tm tmz
#define buli(x) (__builtin_popcountll(x))
#define bur0(x) (__builtin_ctzll(x))
#define bul2(x) (63-__builtin_clzll(x))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fil(a,b) memset((a),(b),sizeof(a))
#define cl(a) fil(a,0)
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)
#define pw(x) ((ll(1))<<(x))
#define upmo(a,b) (((a)=((a)+(b))%mo)<0?(a)+=mo:(a))
#define mmo(a,b) (((a)=1ll*(a)*(b)%mo)<0?(a)+=mo:(a))
void getre(){int x=0;printf("%d\n",1/x);}
void gettle(){int res=1;while(1)res<<=1;printf("%d\n",res);}
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
template<typename T,typename S>inline bool upmin(T&a,const S&b){return a>b?a=b,1:0;}
template<typename T,typename S>inline bool upmax(T&a,const S&b){return a<b?a=b,1:0;}
template<typename N,typename PN>inline N flo(N a,PN b){return a>=0?a/b:-((-a-1)/b)-1;}
template<typename N,typename PN>inline N cei(N a,PN b){return a>0?(a-1)/b+1:-(-a/b);}
template<typename N>N gcd(N a,N b){return b?gcd(b,a%b):a;}
template<typename N>inline int sgn(N a){return a>0?1:(a<0?-1:0);}
#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif
inline void gn(long long&x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sg=-1,x=0):(x=c-'0');
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sg;
}
inline void gn(int&x){long long t;gn(t);x=t;}
inline void gn(unsigned long long&x){long long t;gn(t);x=t;}
inline void gn(double&x){double t;scanf("%lf",&t);x=t;}
inline void gn(long double&x){double t;scanf("%lf",&t);x=t;}
inline void gs(char *s){scanf("%s",s);}
inline void gc(char &c){while((c=getchar())>126 || c<33);}
inline void pc(char c){putchar(c);}
#ifdef JCVB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) 
#endif
typedef long long ll;
typedef double db;
inline ll sqr(ll a){return a*a;}
inline db sqrf(db a){return a*a;}
const int inf=0x3f3f3f3f;
const db pi=3.14159265358979323846264338327950288L;
const db eps=1e-6;
//const int mo=0;
//int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}
int n,k;
struct pkt{
	int x,y;
	void read(){
	}
}a[111111];
set<int> se;
int num[222222],sum[222222];
int totnum;
map<int,int>id;
int back[222222];
int xtot=0;

int le[222222],ri[222222];

void add(int x,int sumdel,int numdel){
	int ii=id[x];

	sum[ii]+=sumdel;
	num[ii]+=numdel;
	totnum+=numdel;

	if(num[ii]==0 && numdel==-1){
		se.erase(x);
		le[ri[ii]]=le[ii];
		ri[le[ii]]=ri[ii];
	}else if(num[ii]==1 && numdel==1){
		set<int>::iterator it=se.lower_bound(x);
		int rig=*it;
		it--;
		int lef=*it;
		se.insert(x);
		ri[id[lef]]=ii;le[ii]=id[lef];
		le[id[rig]]=ii;ri[ii]=id[rig];
	}
}
struct seg{
	int l,r;
	int y;
	int del;
}ss[222222];int sstot=0;
int cmpy(const seg&a,const seg&b){
	return a.y<b.y;
}

ll ans[111111];

void tongji(){

	int u=ri[1];
	int su=sum[u];

	while(u!=xtot){
		int v=ri[u];

		ans[su]+=back[v]-back[u];
		su+=sum[v];
		u=v;
	}
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(k);
	rep(i,1,n+1){
		int x,y;
		gn(x);gn(y);
		ss[++sstot]=(seg){x-k,x,y-k,+1};
		ss[++sstot]=(seg){x-k,x,y,-1};
		id[x-k],id[x];
	}
	id[-inf];id[inf];
	se.insert(-inf);se.insert(inf);
	foreach(it,id)back[it->se=++xtot]=it->fi;
	ri[1]=xtot;le[xtot]=1;
	sort(ss+1,ss+1+sstot,cmpy);


	int cur=1;
	for (int y=-inf;cur<=sstot;y++){
		while(cur<=sstot && ss[cur].y==y){
			if(ss[cur].del==1){
				add(ss[cur].l,1,1);
				add(ss[cur].r,-1,1);
			}else {
				add(ss[cur].l,-1,-1);
				add(ss[cur].r,1,-1);
			}
			cur++;
		}
		tongji();
		if(cur>sstot)break;
		if(totnum==0){
			y=ss[cur].y-1;
		}
	}
	rep(i,1,n+1)printf("%I64d ",ans[i]);
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}