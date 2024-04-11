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
    int n; cin >> n;
    vi a(n); for(int& i:a) cin >> i;
    vi order(n); iota(all(order),0);
    sort(all(order), [&](int c, int d){return a[c]>a[d];});
    int k = n;
    vi ans;
    for(int pick:order) {
        if(pick>=k) {
            continue;
        }
        for(int i=pick;i<k;++i) {
            ans.push_back(a[i]);
        }
        k=pick;
    }
    cout << ans << '\n';
}
int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}