/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */
 
#include <iostream>
#include <fstream>
 
#include <bits/stdc++.h>
 
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define mp make_pair
 
using namespace std;
 
typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> ii;
 
class TaskD {
 public:
  void solveOne(istream &in, ostream &out) {
    int n;
    in >> n;
    vector<int> count(20);
    for (int i = 0; i < n; ++i) {
      int a;
      in >> a;
      for (int b = 0; b < 20; ++b) {
        if (a & (1 << b)) {
          ++count[b];
        }
      }
    }
    int64 res = 0;
    while (true) {
      int cur = 0;
      for (int b = 0; b < 20; ++b) {
        if (count[b]) {
          --count[b];
          cur |= 1 << b;
        }
      }
      if (cur == 0) break;
      res += cur * (int64) cur;
    }
    out << res << "\n";
  }
 
  void solve(std::istream &in, std::ostream &out) {
    int nt = 1;
    for (int it = 0; it < nt; ++it) {
      solveOne(in, out);
    }
  }
};
 
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TaskD solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}