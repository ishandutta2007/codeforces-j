#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <math.h>
using namespace __gnu_pbds;
using namespace std;
#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10), cin.tie(0), cout.tie(0);
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).size())
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x
// mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());uniform_int_distribution<int> distr(0, 1e9);auto my_rand = bind(distr, gen); // my_rand() zwraca teraz liczbe z przedzialu [a, b]
#ifdef LOCAL
ostream &operator<<(ostream &out, string str) {
   for (char c : str)
      out << c;
   return out;
}
template <class L, class R> ostream &operator<<(ostream &out, pair<L, R> p) { return out << "(" << p.st << ", " << p.nd << ")"; }
template <class L, class R, class S> ostream &operator<<(ostream &out, tuple<L, R, S> p) {
   auto &[a, b, c] = p;
   return out << "(" << a << ", " << b << ", " << c << ")";
}
template <class T> auto operator<<(ostream &out, T a) -> decltype(a.begin(), out) {
   out << '{';
   for (auto it = a.begin(); it != a.end(); it = next(it))
      out << (it != a.begin() ? ", " : "") << *it;
   return out << '}';
}
void dump() { cerr << "\n"; }
template <class T, class... Ts> void dump(T a, Ts... x) {
   cerr << a << ", ";
   dump(x...);
}
#define debug(...) cerr << "[" #__VA_ARGS__ "]: ", dump(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define int long long

template <class T> struct SubMatrix {
   vector<vector<T>> p;
   SubMatrix(vector<vector<T>> &v) {
      int R = sz(v), C = sz(v[0]);
      p.assign(R + 1, vector<T>(C + 1));
      rep(r, R) rep(c, C) p[r + 1][c + 1] = v[r][c] + p[r][c + 1] + p[r + 1][c] - p[r][c];
   }
   T sum(int u, int l, int d, int r) { return p[d][r] - p[d][l] - p[u][r] + p[u][l]; }
};

// ull mod_mul(ull a, ull b, ull M) {
//    ll ret = a * b - M * ull(ld(a) * ld(b) / ld(M));
//    return ret + M * (ret < 0) - M * (ret >= (ll)M);
// }

// ull mod_pow(ull b, ull e, ull mod) {
//    ull ans = 1;
//    for (; e; b = mod_mul(b, b, mod), e /= 2)
//       if (e & 1)
//          ans = mod_mul(ans, b, mod);
//    return ans;
// }

// bool isPrime(ull n) {
//    if (n < 2 || n % 6 % 4 != 1)
//       return n - 2 < 2;
//    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022}, s = __builtin_ctzll(n - 1), d = n >> s;
//    for (int a : A) {
//       ull p = mod_pow(a, d, n), i = s;
//       while (p != 1 && p != n - 1 && a % n && i--)
//          p = mod_mul(p, p, n);
//       if (p != n - 1 && i != s)
//          return 0;
//    }
//    return 1;
// }

int32_t main() {
   _upgrade;
   int n, m;

   cin >> n >> m;
   vector<string> S(n);
   rep(i, n) cin >> S[i];

   vector<vector<int>> V(n, vector<int>(m));
   debug(V);
   rep(i, n) rep(j, m) V[i][j] = (i != 0 && j != 0 && S[i - 1][j] == 'X' && S[i][j - 1] == 'X');

   SubMatrix SM(V);
   int q;
   cin >> q;
   rep(i, q) {
      int a, b;
      cin >> a >> b;
      int s = SM.sum(1, a, n, b);
      debug(s);
      cout << (s == 0 ? "YES" : "NO") << endl;
   }
}