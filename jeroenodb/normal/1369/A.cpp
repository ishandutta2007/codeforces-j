#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
namespace {
template<class T1, class T2> void prin(const pair<T1,T2>& x);
template<class T> void prin(const vector<T>& x);
template<class T> void prin(const T& x) {cout << x;}
template<class H, class... T> void prin(const H& h, const T&... t) {prin(h); prin(t...); }
template<class T1, class T2> void prin(const pair<T1,T2>& x) {prin(x.first,' ',x.second);}
template<class T> void prin(const vector<T>& x) {for(int i=0;i<(int)x.size();++i) prin(i==0?"":" ",x[i]);}
template<class... T> void print(const T&... t) {prin(t..., "\n"); }
#define debug(x) cout << #x << ": "; print(x)
}
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >>n;
        print(n%4==0?"YES":"NO");
    }
}