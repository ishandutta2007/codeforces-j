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
const long long MD = 998244353;
template<long long MOD=MD> struct mdint {
    int d=0;
    mdint () {d=0;}
    mdint (long long _d) : d(_d%MOD){
        if(d<0) d+=MOD;
    };
    friend mdint& operator+=(mdint& a, const mdint& o) {
        a.d+=o.d; if(a.d>=MOD) a.d-=MOD;
        return a;
    }
    friend mdint& operator-=(mdint& a, const mdint& o) {
        a.d-=o.d; if(a.d<0) a.d+=MOD;
        return a;
    }
    friend mdint& operator*=(mdint& a, const mdint& o) {
        return a = mdint((ll)a.d*o.d);
    }
    mdint operator*(const mdint& o) const {
        mdint res = *this;
        res*=o;
        return res;
    }
    mdint operator+(const mdint& o) const {
        mdint res = *this;
        res+=o;
        return res;
    }
    mdint operator-(const mdint& o) const {
        mdint res = *this;
        res-=o;
        return res;
    }
    mdint operator^(long long b) const {
        mdint tmp = 1;
        mdint power = *this;
        while(b) {
            if(b&1) {
                tmp = tmp*power;
            }
            power = power*power;
            b/=2;
        }
        return tmp;
    }
    friend mdint operator/=(mdint& a, const mdint& o) {
        a *= (o^(MOD-2));
        return a;
    }
    mdint operator/(const mdint& o) {
        mdint res = *this;
        res/=o;
        return res;
    }
    bool operator==(const mdint& o) { return d==o.d;}
    bool operator!=(const mdint& o) { return d!=o.d;}
    friend istream& operator>>(istream& c, mdint& a) {return c >> a.d;}
    friend ostream& operator<<(ostream& c, const mdint& a) {return c << a.d;}
};
using  mint = mdint<MD>;
mint solve(vector<pi> vp) {
    mint sum=0,sqsum=0;
    ll total=0;
    for(auto& [i,j] : vp) {
        total+=j;
        sum+=mint(i)*j;
        sqsum+=mint(i)*i*j;
    }
    if(total<=1) return 0;
    mint coefD=mint(2)^(total-2);
    if(total>2) coefD+=(mint(2)^(total-3))*(total-2);
    mint coefS=(mint(2)^(total-2))*(total-1);
    return sqsum*coefS+(sum*sum-sqsum)*coefD;
}
int main() {
    vi cnt;
    int m; cin >> m;
    while(m--) {
        int a,f;
        cin >> a >> f;
        while(cnt.size()<=a) cnt.push_back(0);
        cnt[a]=f;
    }
    int n = cnt.size();
    vi mu(n,1);

    vector<bool> sieve(n);
    vector<pi> got;
    mint ans=0;
    for(int i=1;i<n;++i) if(mu[i]!=0) {
        if(i!=1 and !sieve[i]) {
            mu[i]=-1;
            for(int j=i*2;j<n;j+=i) {
                sieve[j]=true;
                if(j%((ll)i*i)==0) {
                    mu[j]=0;
                } else mu[j]=mu[i]*mu[j/i];
            }
        }
        got.clear();
        for(int j=i;j<n;j+=i) {
            if(cnt[j]) got.push_back({j,cnt[j]});
        }
        ans+=solve(got)*mu[i];

    }
    cout << ans << '\n';
}