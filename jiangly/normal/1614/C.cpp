#include <bits/stdc++.h>

constexpr int P = 1000000007;
using i64 = long long;
// assume -P <= x < 2P
int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}
template<class T>
T power(T a, int b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(P - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    Z res = 0;
    
    std::vector<int> l(m), r(m), x(m);
    for (int i = 0; i < m; i++) {
        std::cin >> l[i] >> r[i] >> x[i];
        l[i]--;
    }
    
    for (int j = 0; j < 30; j++) {
        std::vector<int> a(n);
        for (int i = 0; i < m; i++) {
            if (x[i] >> j & 1) {
                continue;
            }
            a[l[i]]++;
            if (r[i] < n) {
                a[r[i]]--;
            }
        }
        for (int i = 1; i < n; i++) {
            a[i] += a[i - 1];
        }
        if (std::count(a.begin(), a.end(), 0) > 0) {
            res += 1 << j;
        }
    }
    res *= power(Z(2), n - 1);
    std::cout << res.val() << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}