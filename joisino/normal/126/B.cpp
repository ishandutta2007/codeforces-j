#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
#define PW(x) (1LL<<(x))
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
typedef vector<vi> mi;
typedef vector<vl> ml;
typedef vector<vd> md;

const int INF = 1e9+10;
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 1000010;

const int MAX_LHM = 3;
const ll MUL[3] = { 72727 , 51419 , 79393  };
const ll RHMOD[3] = { 1000000007 , 765876961 , 727272727 };
struct RollingHash{
  vl h[MAX_LHM];
  vl e[MAX_LHM];
  int n;
  void init( const string &s ){
    n = s.length();
    
    REP( j , MAX_LHM ){
      h[j] = vl( n+1 , 0 );
      e[j] = vl( n+1 , 1 );
    }

    REP( i , n )
      REP( j , MAX_LHM )
	h[j][i+1] = ( h[j][i] * MUL[j] + s[i] ) % RHMOD[j];

    REP( j , MAX_LHM )
      REP( i , n )
	e[j][i+1] = e[j][i] * MUL[j] % RHMOD[j];
  }
  RollingHash(){}
  RollingHash( const string &s ){
    init( s );
  }
  // [s,t)
  vl get( int s , int t ){
    chmin( s , n ); chmax( s , 0 );
    chmin( t , n ); chmax( t , 0 );
    vl res;
    REP( j , MAX_LHM )
      res.pb( ( h[j][t] - h[j][s] * e[j][t-s] % RHMOD[j] + RHMOD[j] ) % RHMOD[j] );

    return res;
  }
};


char s[MAX_N];

RollingHash rh;
int n;

int t[MAX_N];
int kmp(){
  int res = 0;
  
  int q = 2;
  int p = 0;

  t[0] = -1; t[1] = 0;
  while( q < n ){
    if( s[q-1] == s[p] ){ t[q] = p+1; q++; p++; }
    else if( p > 0 ) p = t[p];
    else{ t[q] = 0; q++; }
  }

  p = 1;
  q = 0;
  while( p + q < n-1 ){
    if( s[q] == s[p+q] ){
      q++;
      chmax( res , q );
    } else {
      p = p+q - t[q];
      if( q > 0 ) q = t[q];
    }
  }

  return res;
}

int main(){

  scanf( "%s" , s );
  n = strlen( s );

  rh.init( s );

  int max_length = min( kmp() , n-1 );

  for( int i = max_length; i >= 1; i-- ){
    if( rh.get( 0 , i ) == rh.get( n - i , n ) ){
      REP( j , i ) printf( "%c" , s[j] );
      printf( "\n" );
      return 0;
    }
  }

  puts( "Just a legend" );
  
  return 0;
}