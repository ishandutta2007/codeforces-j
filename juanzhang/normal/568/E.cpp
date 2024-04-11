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

//const int P=1e9+7;
const int P=998244353;
int qp(int a,int k){
  int res=1;for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;return res;
}

const int maxn=1e5+10;
int n,m,A[maxn],B[maxn];

int len,dp[maxn];

int ans[maxn];
int U[maxn],V[maxn];
int k,mp[maxn],pos[1010];
bitset<maxn*2>bit[1010];

bool vis[maxn];int ed[maxn],rabi[maxn];
void outp(int i,int j){
  if(!i)return;
//  printf("(%d %d)\n",i,j);
  if(~A[i]){
    if(U[i]==j){
      outp(i-1,j-1);
    }else{
      outp(i-1,j);
    }
  }else{
    auto&O=bit[mp[i]];
    int x=rabi[i],cur=ed[i];
    per(t,m,2){
      if(x==j){
        ans[i]=B[t];
        vis[t]=1;
        outp(i-1,j-1);
        return;
      }
      --cur;
      while(O.test(cur)){
        cur--,x++;
      }
    }
    if(U[i]==j){
      ans[i]=B[1];
      vis[1]=1;
      outp(i-1,j-1);
    }else{
      outp(i-1,j);
    }
  }
}

void solve(){
  n=read();rep(i,1,n)ans[i]=A[i]=read();
  m=read();rep(i,1,m)B[i]=read();
  sort(B+1,B+m+1,greater<>());
  rep(_,1,n){
    int v=~A[_]?A[_]:B[1];
    int x=lower_bound(dp+1,dp+len+1,v)-dp;
    U[_]=x,V[_]=dp[x];
    dp[x]=v,chkmax(len,x);
    if(~A[_])continue;
    mp[_]=++k,pos[k]=_;int cur=0;
    rep(i,2,m){
      while(dp[x-1]>=B[i])x--,bit[k].set(++cur);
      cur++;
      dp[x]=B[i];
    }
    rabi[_]=x;
    ed[_]=cur;
  }
  outp(n,len);
  int cur=1;
  rep(i,1,n){
    int v=ans[i];
    if(v==-1){
      while(vis[cur])cur++;
      vis[cur]=1,v=B[cur];
    }
    write(v),pc(32);
  }
}

signed main(){
//  int T;cin>>T;while(T--)solve();
  solve();
  orzjk::flush();
  return 0;
}