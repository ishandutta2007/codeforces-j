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

const int MAX_N = 1010;

int n;
int a[MAX_N];

int sum;
int ans[MAX_N][MAX_N];

int x, y;
int width, height;
int minv = 0, maxv = 0;

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d" , &a[i] );

  REP( i , n ){
    x += a[i];
    if( i % 2 == 0 ) y += a[i];
    else y -= a[i];
    chmin( minv , y );
    chmax( maxv , y );
  }
  width = x;
  height = maxv - minv;

  x = y = 0;
  REP( i , n ){
    REP( j , a[i] ){
      if( i % 2 == 0 ) ans[y-minv][x] = 1;
      else ans[y-1-minv][x] = 2;
      
      x++;
      if( i % 2 == 0 ) y++;
      else y--;
    }
  }

  REP( i , height ){
    REP( j , width ){
      if( ans[height-1-i][j] == 0 ) printf( " " );
      else if( ans[height-1-i][j] == 1 ) printf( "/" );
      else if( ans[height-1-i][j] == 2 ) printf( "\\" );
    }
    printf( "\n" );
  }
  
  return 0;
}