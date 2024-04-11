#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return x;
  #undef nc
}

const int maxn = 1e5 + 10;
char str[maxn];
string ans;

int main() {
  scanf("%s", str + 1);
  int n = strlen(str + 1);
  int cur = 0;
  rep(i, 1, n) {
    if (cur > 25) {
      ans += str[i];
      continue;
    }
    if (str[i] > cur + 'a') {
      ans += str[i];
    } else {
      ans += ((cur++) + 'a');
    }
  }
  if (cur < 26) {
    puts("-1");
  } else {
    cout << ans;
  }
  return 0;
}