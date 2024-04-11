#include <bits/stdc++.h>
      
#define FOR(i,a,b) for( ll i = (a); i < (ll)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
#define PW(x) (1LL<<(x))
#define SZ(x) ((ll)(x).size())
#define SHOW(x) cout << #x << " = " << x << endl
#define SHOWA(x,n) for( int yui = 0; yui < n; yui++ ){ cout << x[yui] << " "; } cout << endl

#define pb emplace_back
#define fi first
#define se second

using namespace std;

typedef long double ld;
typedef long long int ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vl> ml;
typedef vector<vd> md;
typedef vector<vi> mi;
     
const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-12;
const ll MOD = 1e9+7;
     
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> inline T sq( T a ){ return a * a; }

ll in(){ long long int x; scanf( "%lld" , &x ); return x; }
char yuyushiki[1000010]; string stin(){ scanf( "%s" , yuyushiki ); return yuyushiki; }

// head

int n;
int sz[100010];

vi G[100010];

double ans[100010];

void dfs2( int x ){
  ld res = 0;
  YYS( w , G[x] ){
    res += sz[w] / 2.0;
  }
  YYS( w , G[x] ){
    ans[w] = ans[x] + ( res - sz[w] / 2.0 ) + 1;
  }
  YYS( w , G[x] ){
    dfs2( w );
  }
}

int dfs( int x ){
  sz[x] = 1;
  YYS( w , G[x] ){
    sz[x] += dfs( w );
  }
  return sz[x];
}

int main(){

  n = in();
  FOR( i , 1 , n ){
    int a = in() - 1;
    G[a].pb( i );
  }

  dfs( 0 );
  
  ans[0] = 1;
  dfs2( 0 );

  REP( i , n ){
    if( i != 0 ){
      printf( " " );
    }
    printf( "%.18lf" , ans[i] );
  }
  printf( "\n" );

  return 0;
}