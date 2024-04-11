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
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        ll k; cin >> k;
        vector<ll> a(n); for(ll& i: a) cin >> i;
        sort(all(a));
        k-=a[0];
        for(int i=1;i<n;++i) {
            a[i]-=a[0];
        }
        ll gcd = a[1];
        for(int i=2;i<n;++i) {
            gcd = __gcd(a[i],gcd);
        }
        if(k%gcd==0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }

}