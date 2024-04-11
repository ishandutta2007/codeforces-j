#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
template<class T, class S>
ostream& operator << (ostream &o, const pair<T, S> &p) {
    return o << '(' << p.first << ", " << p.second << ')';
}

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef complex<ld> pt;

#define G(x) ll x; cin >> x;
#define GD(x) ld x; cin >> x;
#define GS(s) string s; cin >> s;
#define F(i, l, r) for(ll i = l; i != r; l < r ? i++ : i--)
#define P(a) { cout << #a << ": { "; for(auto _ : a) cout << _ << " "; cout << "}" << endl; }
#define PN(a, n) { cout << #a << ": { "; F(_, 0, n) cout << a[_] << " "; cout << "}" << endl; }
#define CE(a, x) lower_bound(a.begin(), a.end(), x)
#define UP(a, x) upper_bound(a.begin(), a.end(), x)
#define FL(a, x) (x < *a.begin() ? a.end() : --UP(a, x))
#define LO(a, x) (x <= *a.begin() ? a.end() : --CE(a, x))
#define MC(a, x) a.lower_bound(x)
#define MU(a, x) a.upper_bound(x)
#define MF(a, x) (x < (*a.begin()).K ? a.end() : --MU(a, x))
#define ML(a, x) (x <= (*a.begin()).K ? a.end() : --MC(a, x))
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define X real()
#define Y imag()
#define M 1000000007 //998244353
#define N 100010

map<string, ll> cts;
set<string> used;

string rev(string s) {
    string ans = "";
    for(int i = s.size() - 1; i >= 0; i--) ans += s[i];
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(n) G(m)
    F(i, 0, n) { GS(s) cts[s]++; }
    string ans = "";
    for(auto a : cts) if((a.V % 2) && a.K == rev(a.K)) ans = a.K;
    for(auto a : cts) {
        if(a.K == rev(a.K)) { if(a.V >= 2)
            F(i, 0, a.V / 2) ans = a.K + ans + a.K;
        } else if(cts.count(rev(a.K)) && !used.count(a.K) && !used.count(rev(a.K))) {
            used.insert(a.K);
            used.insert(rev(a.K));
            F(i, 0, min(cts[rev(a.K)], a.V)) ans = a.K + ans + rev(a.K);
        }
    }
    cout << ans.size() << endl;
    EX(ans)
}