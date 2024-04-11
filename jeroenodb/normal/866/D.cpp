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
    priority_queue<int,vi,greater<int>> pq;
    ll ans=0;
    int n; cin >> n;
    for(int i=0;i<n;++i) {
        int a; cin >> a;
        if(!pq.empty() and a>pq.top()) {
            ans+=a-pq.top();
            pq.pop();
            pq.push(a);
        } 
        pq.push(a);
    }
    cout << ans << '\n';
    
}