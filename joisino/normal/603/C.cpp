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

int n, k;

int grandy( int x ){
  if( x == 0 ){
    return 0;
  }
  if( x % 2 == 1 ){
    if( x <= 10 ){
      if( grandy( x - 1 ) == 0 ){
        return 1;
      }
      return 0;
    } else {
      return 0;
    }
  }
  set<int> ss;
  ss.clear();
  ss.insert( grandy( x - 1 ) );
  if( k % 2 == 0 ){
    ss.insert( 0 );
  } else {
    ss.insert( grandy( x / 2 ) );
  }
  REP( i , INF ){
    if( ss.find( i ) == ss.end() ){
      return i;
    }
  }
  assert( false );
}

int main(){

  n = in();
  k = in();

  int g = 0;
  REP( i , n ){
    g ^= grandy( in() );
  }

  if( g == 0 ){
    puts( "Nicky" );
  } else {
    puts( "Kevin" );
  }
  
  return 0;
}