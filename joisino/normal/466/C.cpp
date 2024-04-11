#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define pb emplace_back
#define mp make_pair
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
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 500010;

ll cnt[MAX_N];

ll n;
ll a[MAX_N];

ll sum;
ll ans;

int main(){

  scanf( "%lld" , &n );
  REP( i , n ) scanf( "%lld" , &a[i] );
  REP( i , n ) sum += a[i];
  if( sum % 3 != 0 ) return puts( "0" );

  ll p = 0;
  REP( i , n ){
    p += a[i];
    cnt[i+1] = cnt[i];
    if( p == sum/3 ) cnt[i+1]++;
  }

  p = 0;
  REP( i , n-1 ){
    p += a[n-1-i];
    if( p == sum/3 ) ans += cnt[n-2-i];
  }

  cout << ans << endl;
  
  return 0;
}