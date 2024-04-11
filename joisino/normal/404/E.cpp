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

const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 1000010;

char s[MAX_N];
ll dx[MAX_N];
ll n;

bool check( ll right ){
  ll x = 0, left = 0;
  REP( i , n-1 ){
    x += dx[i];
    chmin( x , right );
    chmin( left , x );
  }
  return x == left;
}

int main(){

  scanf( "%s" , s );
  n = strlen( s );
  REP( i , n ){
    dx[i] = (s[i]=='L' ? -1 : 1);
    if( s[n-1] == 'R' ) dx[i] *= -1;
  }

  ll lb = -1, ub = INF;
  while( ub - lb > 1 ){
    ll md = ( lb + ub ) / 2;
    if( check(md) ) lb = md;
    else ub = md;
  }

  if( lb > n ) printf( "1\n" );
  else printf( "%lld\n" , lb+1 );
  
  return 0;
}