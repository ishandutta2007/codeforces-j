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

ll sz( ll a ){
  ll cur = 7;
  ll cnt = 1;
  while( a > cur ){
    cur *= 7;
    cnt++;
  }
  return cnt;
}

vl yu( ll a , int len ){
  vl res(0);
  REP( i , len ){
    res.pb( a % 7 );
    a /= 7;
  }
  assert( a == 0 );
  return res;
}

int main(){

  ll n = in();
  ll m = in();

  ll a = sz( n );
  ll b = sz( m );

  if( a + b > 7 ){
    puts( "0" );
    return 0;
  }

  ll ans = 0;
  REP( i , n ){
    vl x = yu( i , a );
    REP( j , m ){
      vl y = yu( j , b );
      y.insert( y.end() , ALL(x) );
      vi cnt(7,0);
      bool ok = true;
      YYS( w , y ){
        cnt[w]++;
        if( cnt[w] >= 2 ){
          ok = false;
          break;
        }
      }
      if( ok ){
        ans++;
      }
    }
  }

  cout << ans << endl;
  
  return 0;
}