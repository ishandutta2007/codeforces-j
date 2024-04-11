#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define PW(x) (1LL<<(x))
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
const ll MOD = 1e9+9;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

struct Unionfind{
  vector<int> size;
  vector<int> par;
  Unionfind(){}
  Unionfind( int n ) :  size(n,1), par(n){
    REP( i , n )
      par[i] = i;
  }
  void init( int n ){
    size.resize( n );
    par.resize( n );
    REP( i , n ){
      size[i] = 1;
      par[i] = i;
    }
  }
  int find( int x ){
    if( par[x] == x ) return x;
    return par[x] = find( par[x] );
  }
  bool unite( int x , int y ){
    x = find(x);
    y = find(y);
    if( x == y ) return false;
    if( size[y] < size[x] ) swap( x , y );
    par[x] = y;
    size[y] += size[x];
    return true;
  }
  bool same( int x , int y ){
    return find(x) == find(y);
  }
};


const int MAX_N = 128;

int n;
int x[MAX_N], y[MAX_N];

int ans;

Unionfind uf;

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d %d" , &x[i] , &y[i] );

  uf.init( n );

  REP( i , n ) REP( j , i ) if( x[i] == x[j] || y[i] == y[j] ) uf.unite( i , j );
  REP( i , n ) if( uf.find( i ) == i ) ans++;

  printf( "%d\n" , ans - 1 );
  
  return 0;
}