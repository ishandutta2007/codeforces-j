#include <bits/stdc++.h>

using namespace std;

#define ALL(v) v.begin(),v.end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORR(I, A, B) for (int I = (A); I < (B); ++I)

const double EPS = 1e-4;
const long double PI = acos((long double)-1.0);
const long long int MOD = 1e9 + 7;

typedef long long int lint;
typedef long double ld;
lint powmod(lint a,lint b, lint mod) {lint res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

const int debug = 1;
template <typename T>
void DBG(vector<T> v){if(debug){for(T t:v)cout<<t<<"  ";cout<<endl;}}
template <typename T>
void DBG(T t){if(debug)cout<<t<<endl;}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    lint n, k;
    cin >> n >> k;

    vector<lint> a(n), b(n);
    FOR(i, n) cin >> a[i];
    FOR(i, n) cin >> b[i];

    lint l = 0;
    lint r = 1e9;

    while (l < r - 1)
    {
        lint m = (l + r) / 2;
        
        lint K = k;
        
        FOR(i, n)
        {
            lint t = a[i] * m - b[i];
            if (t > 0)
            {
                K -= t;
            }
            if (K < 0)
                break;
        }

        if (K < 0)
        {
            r = m;
        }
        else
            l = m;
    }

    cout << l;
}