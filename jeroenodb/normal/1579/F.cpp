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
void solve() {
    int n,d; cin >> n >> d;
    d=n-d;
    vector<short> a(n); for(auto& i : a) cin >> i;
    vi dist(n,oo);
    queue<int> q;
    for(int i=0;i<n;++i) if(!a[i]) q.push(i),dist[i]=0;
    while(!q.empty()) {
        int at = q.front(); q.pop();
        int to = (at+d)%n;
        if(dist[to]==oo) {
            dist[to]=dist[at]+1;
            q.push(to);
        }
    }
    int ans = *max_element(all(dist));
    if(ans==oo) cout << "-1\n";
    else cout << ans << '\n';
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();


}