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
        int n,w; cin >> n >> w;
        int freq[20]={};
        for(int i=0;i<n;++i) {
            int j = 0;
            int cur; cin >> cur;
            while((1<<j) < cur) ++j;
            freq[j]++;
        }
        int used= 0;
        int need = 1;
        int cur = w;
        while(used!=n) {
            for(int i=19;i>=0;--i) {
                while(freq[i] and 1<<i <= cur) {
                    freq[i]--;
                    used++;
                    cur-=1<<i;
                }
            }
            if(used!=n) {
                need++;
                cur=w;
            }
        }
        cout << need << '\n';
    }
}