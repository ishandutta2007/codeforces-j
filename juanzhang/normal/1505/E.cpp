#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read(){
  #define nc getchar()
  int x=0;char c=nc;bool f=0;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
int n,m;char str[10][10];

void solve(){
  cin>>n>>m;
  rep(i,1,n)scanf("%s",str[i]+1);
  int x=1,y=1,res=str[n][m]=='*';
  while(x<n||y<m){
    res+=str[x][y]=='*';
    int v1=20,v2=20;
    rep(i,y+1,m)if(str[x][i]=='*')chkmin(v1,i-y);
    rep(i,x+1,n)if(str[i][y]=='*')chkmin(v2,i-x);
//    printf("(%d %d) %d %d\n",x,y,v1,v2);
    if(x==n||(v1<=v2&&y<=m)){
      y++;
    }else{
      x++;
    }
  }
  cout<<res<<endl;
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}