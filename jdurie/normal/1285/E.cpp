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
#define F(i, l, r) for(ll i = l; i - r; i < r ? i++ : i--)
#define P(a) { cout << #a << " "; for(auto _ : a) cout << _ << " "; cout << endl; }
#define PN(a, n) { cout << #a << " "; F(_, 0, n) cout << a[_] << " "; cout << endl; }
#define CE(a, x) lower_bound(a.begin(), a.end(), x)
#define UP(a, x) upper_bound(a.begin(), a.end(), x)
#define FL(a, x) (x < *a.begin() ? a.end() : --UP(a, x))
#define LO(a, x) (x <= *a.begin() ? a.end() : --CE(a, x))
#define K first
#define V second
#define X real()
#define Y imag()
#define M 1000000007 //998244353
#define N 200010

map<ll, vector<pl>> q;
set<ll> cr;
ll cts[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    G(T) while(T--) {
        G(n)
        q.clear();
        cr.clear();
        for(ll i = 0; i < n; i++) {
            G(l) G(r)
            q[l].push_back({0, i});
            q[r].push_back({1, i});
            cts[i] = 0;
        }
        ll segs = 0, upc = -1, lastSz = 0;
        bool olap = false;
        for(auto a : q) {
            ll st = 0;
            vector<ll> erasees;
            for(pl p : a.second)
                if(!p.first) {
                    st++;
                    cr.insert(p.second);
                } else erasees.push_back(p.second);
            if(cr.size() > 1) olap = true;
            if(st && upc != -1) {
                cts[upc]++;
                upc = -1;
            }
            for(ll aaa : erasees) cr.erase(aaa);
            if(cr.size() == 0) segs++;
            upc = cr.size() == 1 && (lastSz || st > 1) ? *cr.begin() : -1;
            lastSz = cr.size();
        }
        ll mx = 0;
        for(ll i = 0; i < n; i++) {
            //cout << i << ": " << cts[i] << endl;
            mx = max(mx, cts[i]);
        }
        if(!olap) segs--;
        cout << segs + mx << endl;
    }
}