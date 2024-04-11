#include <bits/stdc++.h>
using namespace std;

template <int MOD>
class Modular {
public:
    Modular(long long v=0) {
        value = v % MOD;
        if (value < 0)
            value += MOD;
    }

    Modular(long long a, long long b) : value(0) {
        *this += a;
        *this /= b;
    }

    Modular& operator+=(Modular const& b) {
        value += b.value;
        if (value >= MOD)
            value -= MOD;
        return *this;
    }

    Modular& operator-=(Modular const& b) {
        value -= b.value;
        if (value < 0)
            value += MOD;
        return *this;
    }

    Modular& operator*=(Modular const& b) {
        value = (long long)value * b.value % MOD;
        return *this;
    }

    friend Modular power(Modular a, long long e) {
        Modular res = 1;
        while (e) {
            if (e & 1)
                res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }

    friend Modular inverse(Modular a) {
        return power(a, MOD - 2);
    }

    Modular& operator/=(Modular const& b) {
        return *this *= inverse(b);
    }

    friend Modular operator+(Modular a, Modular const b) {
        return a += b;
    }

    friend Modular operator-(Modular a, Modular const b) {
        return a -= b;
    }

    friend Modular operator-(Modular const a) {
        return 0 - a;
    }

    friend Modular operator*(Modular a, Modular const b) {
        return a *= b;
    }

    friend Modular operator/(Modular a, Modular const b) {
        return a /= b;
    }

    friend std::ostream& operator<<(std::ostream &os, Modular const& a) {
        return os << a.value;
    }

    friend bool operator==(Modular const& a, Modular const& b) {
        return a.value == b.value;
    }

    friend bool operator!=(Modular const& a, Modular const& b) {
        return a.value != b.value;
    }

    int value;
    static const int MOD_value = MOD;
};

using ModInt = Modular<998'244'353>;

int main() {
    ios_base::sync_with_stdio(false);


    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(2);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > 0)
            x--;
        a[i & 1].push_back(x);
    }

    vector<ModInt> same(n, 0), diff(n, 1);
    for (int i = 1; i < n; i++) {
        int l = i / 2;
        int r = i - l - 1;
        same[i] = same[l] * same[r] + (k - 1) * diff[l] * diff[r];
        diff[i] = same[l] * diff[r] + same[r] * diff[l] + (k - 2) * diff[l] * diff[r];
    }


    ModInt result(1);
    for (auto v : a) {
        n = v.size();
        if (all_of(v.begin(), v.end(), [](int x){ return x == -1; })) {
            result *= k * power(ModInt(k-1), n-1);
        } else {
            int last = -1;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (v[i] >= 0) {
                    if (last == -1) {
                        result *= power(ModInt(k-1), cnt);
                    } else {
                        if (v[i] != last) {
                            result *= diff[cnt];
                        } else {
                            result *= same[cnt];
                        }
                    }
                    last = v[i];
                    cnt = 0;
                } else {
                    cnt++;
                }
            }
            result *= power(ModInt(k-1), cnt);
        }
    }
    cout << result << '\n';
}