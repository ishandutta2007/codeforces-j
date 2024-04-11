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
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int n = s.size();
        vector<bool> one(n+1);
        for(int i=n-1;i>=0;--i) {
            one[i] = one[i+1] or s[i]=='1';
        }
        bool hasz=0;
        int ans=0;
        for(int i=0;i<n;++i) {
            if(!hasz and !one[i+1]) {
                ans++;
            }
            if(s[i]=='0') hasz=1;
        }
        cout << ans << '\n';
    }
}