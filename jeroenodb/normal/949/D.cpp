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
    ll d,b;
    int n; cin >> n >> d >> b;
    vector<ll> pref(n+1);
    for(int i=1;i<=n;++i) {
        cin >> pref[i];
        pref[i]+=pref[i-1];
    }
    int x[2] = {};
    ll needl=0, needr=0;
    for(int i=1;i<=(n-1)/2;++i) {
        needl+=b,needr+=b;
        int j = n-i+1;
        if(pref[min(ll(n),i+d*i)]<needl) {
            x[0]++;
            needl-=b;
        }
        if(pref[n]-pref[max(0LL, j-i*d-1)]<needr) {
            x[1]++;
            needr-=b;
        }
    }
    cout << max(x[0],x[1]);
}