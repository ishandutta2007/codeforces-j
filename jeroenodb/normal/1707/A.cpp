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
    int n,q; cin >> n >> q;
    vi a(n);
    for(auto& i : a) {
        cin >> i;
        i = min(i,n+1);
    }
    vector<bool> res(n);
    int bads=q;
    for(int i=n-1;i>=0;--i) {
        if(q-bads>=a[i]) {
            res[i]=true;
        } else if(bads) {
            bads--;
            res[i]=true;
        }
    }
    for(int i=0;i<n;++i) {
        cout << bool(res[i]);
    } cout << '\n';
    
    
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}