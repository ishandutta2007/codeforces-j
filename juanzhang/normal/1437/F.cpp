#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read() {
  #define nc getchar()
  int x=0;char c=nc;
  while(c<48)c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int maxn=5010,P=998244353;
int Inc(int x,int y){return x+y<P?x+y:x+y-P;}
int Dec(int x,int y){return x<y?x-y+P:x-y;}
void Add(int &x,int y){x+=y;if(x>=P)x-=P;}
void Sub(int &x,int y){x-=y;if(x<0)x+=P;}
int qp(int a,int k){int res=1;for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;return res;}

int inv[maxn],fac[maxn],ifac[maxn];
int binom(int n,int m){return n<m?0:1ll*fac[n]*ifac[m]%P*ifac[n-m]%P;}
void init(){
  fac[0]=ifac[0]=inv[1]=fac[1]=ifac[1]=1;
  rep(i,2,maxn-1)inv[i]=1ll*(P-P/i)*inv[P%i]%P,fac[i]=1ll*i*fac[i-1]%P,ifac[i]=1ll*inv[i]*ifac[i-1]%P;
}
int n,A[maxn],pos[maxn],dp[maxn];

void solve() {
  init();
  cin>>n;
  rep(i,1,n)A[i]=read();
  sort(A+1,A+n+1);
  rep(i,1,n)while(A[pos[i]+1]*2<=A[i])pos[i]++;
  if(pos[n]!=n-1)return puts("0"),void();
  dp[n]=1;
  per(i,n-1,0)rep(j,i+1,n)if(A[i]*2<=A[j]){
    int lst=n-pos[j];
    int nxt=i?n-pos[i]:n+1;
    int x=nxt-lst-1;
    dp[i]=(dp[i]+1ll*binom(lst+x-1,x)*fac[x]%P*dp[j])%P;
  }
  cout<<dp[0]<<endl;
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}