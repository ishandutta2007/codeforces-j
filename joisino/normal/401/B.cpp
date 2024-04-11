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

const int MAX_N = 4010;

ll x, k;

ll a, b, c;

bool used[MAX_N];

ll ansa, ansb;

int main(){

  scanf( "%lld %lld" , &x , &k );

  used[x] = true;
  REP( i , k ){
    scanf( "%lld" , &a );
    if( a == 1 ){
      scanf( "%lld %lld" , &b , &c );
      used[b] = used[c] = true;
    } else if( a == 2 ){
      scanf( "%lld" , &b );
      used[b] = true;
    }
  }

  ll p = 0;
  FOR( i , 1 , x+1 ){
    if( used[i] ){
      ansb += i-p-1;
      ansa += (i-p)/2;
      p = i;
    }
  }

  printf( "%lld %lld\n" , ansa , ansb );
  
  return 0;
}