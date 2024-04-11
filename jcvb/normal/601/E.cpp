#include<cstdio>
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
#define pi ((db)3.14159265358979323846264338327950288L)
#define buli __builtin_popcountll
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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
template<typename T,typename S>inline bool upmin(T&a,const S&b){return a>b?a=b,1:0;}
template<typename T,typename S>inline bool upmax(T&a,const S&b){return a<b?a=b,1:0;}
template<typename N,typename PN>inline N flo(N a,PN b){return a>=0?a/b:-((-a-1)/b)-1;}
template<typename N,typename PN>inline N cei(N a,PN b){return a>0?(a-1)/b+1:-(-a/b);}
template<typename N>N gcd(N a,N b){return b?gcd(b,a%b):a;}
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
#ifdef JCVB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) 
#endif
typedef long long ll;
typedef double db;
inline ll sqr(ll a){return a*a;}
inline db sqrf(db a){return a*a;}
int inf=0x3f3f3f3f;
db eps=1e-6;
int mo=1000000007;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}
int n,k;
struct node{
	int v,w;
	int st,ed;
}a[22222];int ntot;
int q;
int totq=0;

vector<int>seg[66666];
int l1,r1,v;
void upd(int l,int r,int x){
	if(l1<=l && r<=r1)seg[x].pb(v);
	else{
		int mid=l+r>>1;
		if(l1<=mid)upd(l,mid,x<<1);
		if(r1>mid)upd(mid+1,r,x<<1|1);
	}
}

int f[20][1111];
int out[33333];
void work(int l,int r,int x,int dep){
	rep(i,0,siz(seg[x])){
		int d=seg[x][i];
		for (int j=k;j>=a[d].w;j--)upmax(f[dep][j],f[dep][j-a[d].w]+a[d].v);
	}
	if(l==r){
		int su=0;
		per(m,1,k+1)su=(1ll*su*10000019+f[dep][m])%mo;
		out[l]=su;
	}else{
		int mid=l+r>>1;
		rep(i,0,k+1)f[dep+1][i]=f[dep][i];
		work(l,mid,x<<1,dep+1);
		rep(i,0,k+1)f[dep+1][i]=f[dep][i];
		work(mid+1,r,x<<1|1,dep+1);
	}
}
int main()
{
#ifdef JCVB
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(k);
	rep(i,1,21000)a[i].ed=-1;
	rep(i,1,n+1){
		gn(a[i].v),gn(a[i].w);
		a[i].st=1;
	}
	ntot=n;
	gn(q);

	rep(i,1,q+1){
		int opt;
		gn(opt);
		if(opt==1){
			int x,y;
			gn(x);gn(y);
			a[++ntot].v=x;
			a[ntot].w=y;
			a[ntot].st=totq+1;
		}else if(opt==2){
			int t;gn(t);
			a[t].ed=totq;
		}else totq++;
	}
	rep(i,1,ntot+1)if(a[i].ed==-1)a[i].ed=totq;
	rep(i,1,ntot+1){
		l1=a[i].st,r1=a[i].ed,v=i;
		if(l1<=r1)upd(1,totq,1);
	}
	work(1,totq,1,0);
	rep(i,1,totq+1)printf("%d\n",out[i]);
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}