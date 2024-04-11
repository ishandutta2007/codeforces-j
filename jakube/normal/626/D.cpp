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

    int n;
    cin >> n;
    vector<int> numbers(n);
    FOR(i, n)
        cin >> numbers[i];

    //sort(ALL(numbers));

    vector<int> differences(5000, 0);

    for(int i : numbers)
        for (int j : numbers)
            if (i > j)
                differences[i-j]++;

    vector<int> suffix(10000, 0);
    int sum = 0;
    for (int i = 4999; i >= 0; i--)
    {
        sum += differences[i];
        suffix[i] = sum;
    }

    lint total = 0;
    FOR(i, 5000)
    {
        lint c1 = differences[i];
        FOR(j, 5000)
        {
            lint c2 = differences[j];
            total += c1*c2*suffix[i+j+1];
        }
    }

    lint wins = accumulate(ALL(differences), 0LL);

    double result = (double)total / pow((double)wins, 3);
    cout << result;
}