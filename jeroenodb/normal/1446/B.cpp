#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
int main() {
    int n,m; cin >> n >> m;
    string a,b; cin >> a >> b;
    vector<int> dp(m,-oo);
    int ans= 0;
    for(int i=0;i<n;++i) {
        auto c = a[i];
        for(int j=m-1;j>=0;--j) {
            dp[j] = max( max(j?dp[j-1]:-oo, +(j+i))+4*(c==b[j]),dp[j]);
        }
        for(int j=0;j<m;++j) {
            if(j) dp[j] = max(dp[j],dp[j-1]);
            ans = max(ans,-(i+1+j+1)+dp[j]);
        }
    }
    cout << ans << '\n';
}