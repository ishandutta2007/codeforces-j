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

const int MAX_N = 200010;


ll n, m, p;
ll a[MAX_N];
ll b[MAX_N];

vl ans;

map<ll,ll> ma;
ll icnt, cnt;

int main(){

  scanf( "%lld %lld %lld" , &n , &m , &p );

  REP( i , n ) scanf( "%lld" , &a[i] );
  REP( i , m ) scanf( "%lld" , &b[i] );

  REP( i , m ) ma[ b[i] ]++;
  icnt = ma.size();

  REP( i , p ){
    cnt = icnt;
    ll j;
    for( j = 0; j < m && i+j*p < n; j++ ){
      ma[ a[i+j*p] ]--;
      if( ma[a[i+j*p] ] == 0 ) cnt--;
    }
    for( j = m; true; j++ ){
      if( cnt == 0 ) ans.pb( i+(j-m)*p );
      if( i+j*p >= n ) break;
      ma[ a[i+j*p] ]--;
      if( ma[a[i+j*p] ] == 0 ) cnt--;
      if( ma[a[i+(j-m)*p] ] == 0 ) cnt++;
      ma[a[i+(j-m)*p] ]++;
    }
    for( j = 0; j < m && i+j*p < n; j++ ) ma[ a[i+j*p] ]++;
    for( j = m; true; j++ ){
      if( i+j*p >= n ) break;
      ma[ a[i+j*p] ]++;
      ma[ a[i+(j-m)*p] ]--;
    }
  }

  SORT( ans );
  printf( "%d\n" , (int)ans.size() );
  REP( i , ans.size() ) printf( "%lld%c" , ans[i]+1 , i==ans.size()-1?'\n':' ' );
  
  return 0;
}