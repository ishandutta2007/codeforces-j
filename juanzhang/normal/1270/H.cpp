#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}

#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define mem(x) memset((x),0,sizeof(x))

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;

typedef unsigned u32;
typedef unsigned uint;
typedef unsigned long long u64;

namespace orzjk{
  const int SZ=1e6;
  char buf[SZ],*p1=buf,*p2=buf;
  char nc(){
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,SZ,stdin),p1==p2)?EOF:*p1++;
  }
  char fub[SZ],*p3=fub,*p4=fub+SZ;
  void pc(char c){
    p3==p4&&(fwrite(fub,1,SZ,stdout),p3=fub);
    *p3++=c;
  }
  void flush(){
    fwrite(fub,1,p3-fub,stdout),p3=fub;
  }
}
using orzjk::nc;
using orzjk::pc;

//#define nc getchar
//#define pc putchar

int read(){
  int x=0,f=1;char c=nc();
  while(c<48)c=='-'&&(f=-1),c=nc();
  while(c>47)x=x*10+(c^48),c=nc();
  return x*f;
}
void write(int x){
  static char st[21];
  if(!x)return pc(48),void();
  char*p=st;
  if(x<0)x=-x,pc('-');
  for(;x;x/=10)*p++=x%10|48;
  do{
    pc(*--p);
  }while(p!=st);
}

const int inf=1e9+1;

//const int P=1e9+7;
//const int P=998244353;
//int qp(int a,int k){
//  int res=1;for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;return res;
//}

const int maxn=1e6+10;
int n,q;

struct node{
  int x,y;
  void rd(){
    x=read(),y=read();
  }
  bool operator<(const node&o)const{
    return x<o.x;
  }
}A[maxn];

vi dat;int vsz;

struct Querys{
  int id;node u;
}Q[maxn];

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

int val[maxn<<2],cnt[maxn<<2],tag[maxn<<2];
void pushtag(int k,int x){
  tag[k]+=x,val[k]+=x;
}
void pushdown(int k){
  int&x=tag[k];
  if(x)pushtag(k<<1,x),pushtag(k<<1|1,x),x=0;
}
void maintain(int k){
  if(val[k<<1]<val[k<<1|1]){
    val[k]=val[k<<1],cnt[k]=cnt[k<<1];
  }else if(val[k<<1]>val[k<<1|1]){
    val[k]=val[k<<1|1],cnt[k]=cnt[k<<1|1];
  }else{
    val[k]=val[k<<1],cnt[k]=cnt[k<<1]+cnt[k<<1|1];
  }
}
void add(int k,int l,int r,int ql,int qr,int x){
  if(ql<=l&&r<=qr)return pushtag(k,x);
  pushdown(k);
  if(ql<=mid)add(lson,ql,qr,x);
  if(qr>mid)add(rson,ql,qr,x);
  maintain(k);
}
void flip(int k,int l,int r,int x){
  if(l==r){
    if(!cnt[k]){
      val[k]=tag[k],cnt[k]=1;
    }else{
      val[k]=1e9,cnt[k]=0;
    }
  }else{
    pushdown(k);
    x<=mid?flip(lson,x):flip(rson,x);
    maintain(k);
  }
}

#undef mid

set<node>S;

#define iter set<node>::iterator

void upd(iter l,iter r,int v){
  if(l->y>r->y)add(1,1,vsz,r->y,l->y-1,v);
}

void ins(node o){
  flip(1,1,vsz,o.y);
  auto nx=S.lower_bound(o);
  auto pr=nx;--pr;
  upd(pr,nx,-1);
  auto it=S.insert(o).first;
  upd(pr,it,1);
  upd(it,nx,1);
}

void del(node o){
  flip(1,1,vsz,o.y);
  auto it=S.find(o);
  auto pr=it,nx=it;--pr,++nx;
  upd(pr,it,-1);
  upd(it,nx,-1);
  upd(pr,nx,1);
  S.erase(it);
}
void out(){
//  assert(val[1]==1);
  write(cnt[1]),pc(10);
}

void solve(){
  n=read(),q=read();
  rep(i,1,n)A[i].x=i,A[i].y=read(),dat.pb(A[i].y);
  rep(i,1,q)Q[i].id=read(),Q[i].u.x=Q[i].id,Q[i].u.y=read(),dat.pb(Q[i].u.y);
  dat.pb(0),dat.pb(inf);
  sort(ALL(dat));
  dat.erase(unique(ALL(dat)),dat.end());
  rep(i,1,n)A[i].y=lower_bound(ALL(dat),A[i].y)-dat.begin()+1;
  rep(i,1,q)Q[i].u.y=lower_bound(ALL(dat),Q[i].u.y)-dat.begin()+1;
  vsz=dat.size();
  S.insert({0,vsz});
  S.insert({inf,1});
  memset(val,0x3f,sizeof val);
  rep(i,1,n)ins(A[i]);
//  out();
  rep(i,1,q){
    auto e=Q[i];
    del(A[e.id]);
    ins(A[e.id]=e.u);
    out();
  }
}

signed main(){
//  freopen("hikari.in","r",stdin);
//  freopen("hikari.out","w",stdout);
//  int T;cin>>T;while(T--)solve();
  solve();
  orzjk::flush();
  return 0;
}