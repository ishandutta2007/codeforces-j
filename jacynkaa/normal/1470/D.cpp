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
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).size())
#define SIZE(X) (int)((X).size())
#define ALL(X) (X).begin(), (X).end()
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x

#ifdef LOCAL
ostream &operator<<(ostream &out, string str) {
   for (char c : str)
      out << c;
   return out;
}
template <class L, class R> ostream &operator<<(ostream &out, pair<L, R> p) { return out << "(" << p.st << ", " << p.nd << ")"; }
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
#define debug(...)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     \
   {}
#endif

#define int long long

const int MAXN = 2e6;

int n, m;
vector<int> G[MAXN];
int stan[MAXN];

void pre() {
   rep(i, n + 2) G[i].clear();
   rep(i, n + 2) stan[i] = -1;
}

void dfs(int x) {
   stan[x] = 0;

   for (int y : G[x]) {
      if (stan[y] == 0) {
         stan[x] = 1;
      }
   }
   // if (x == 15)
   //    debug(x, G[x], stan[x]);

   for (int y : G[x])
      if (stan[y] == -1)
         dfs(y);
}

int32_t main() {
   _upgrade;

   int Z;
   cin >> Z;

   while (Z--) {
      cin >> n >> m;
      pre();
      rep(i, m) {
         int a, b;
         cin >> a >> b;
         G[--a].push_back(--b);
         G[b].push_back(a);
      }
      stan[0] = 0;
      dfs(0);

      vector<int> res;
      bool OK = true;
      rep(i, n) if (stan[i] == -1) OK = false;
      else if (stan[i] == 0) res.push_back(i);

      if (OK) {
         cout << "Yes\n";
         cout << sz(res) << endl;
         for (int a : res)
            cout << a + 1 << " ";
         cout << endl;
      } else {
         cout << "No\n";
      }
   }
}