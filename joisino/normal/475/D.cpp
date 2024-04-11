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

const int MAX_N = 100010;

int n, q;
ll a[MAX_N];

vpl v, ne;

unordered_map<ll,ll> cnt;

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%lld" , &a[i] );

  REP( i , n ){
    YYS( w , v ) w.fi = __gcd( w.fi , a[i] );
    v.pb( a[i] , 1 );
    int p = 0;
    ne.clear();
    while( p < v.size() ){
      int cur = v[p].fi;
      ne.pb( cur , 0 );
      while( p < v.size() && v[p].fi == cur ){
	ne.back().se += v[p].se;
	p++;
      }
    }
    YYS( w , ne ) cnt[ w.fi ] += w.se;
    v = ne;
  }

  scanf( "%d" , &q );
  REP( i , q ){
    int x;
    scanf( "%d" , &x );
    printf( "%lld\n" , cnt[x] );
  }

  return 0;
}