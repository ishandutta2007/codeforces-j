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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--) {
        string s; cin >> s;
        int n = s.size();
        int pp[3] = {0,0,0};
        vi dp(n+1,oo);
        dp[0]=0;
        for(int i=1;i<=n;++i) {
            if(s[i-1]=='0') {
                pp[0]=i;
            } else {
                pp[1] = i;
            }
            for(int j : {0,1,2}) {
                dp[i] = min(dp[i],dp[pp[j]]+j);
            }
        }
        cout << dp[n] << '\n';
    }
}