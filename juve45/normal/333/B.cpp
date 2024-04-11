#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 2005;
int n, use[N], m, a, b;

int main() {
	ios_base::sync_with_stdio(false);


	cin >> n;
	// BipartiteMatcher bm(2 * (n - 2), 2 * (n - 2));
	cin >> m;
	
	use[1] = use[n] = use[n + 1] = use[n + n] = 1;

	for(int i = 1; i <= m; i++) {
		cin >> a >> b;
		use[a] = 1;
		use[b + n] = 1;
	}

	int x = 0, y = 0, xx = 0, yy = 0;

	for(int i = 1; i <= n; i++)
		x += (use[i] == 0);

	for(int i = n + 1; i <= 2 * n; i++)
		y += (use[i] == 0);

	int bit = 0;
	if(n % 2 == 1 && use[n / 2 + 1] == use[n/ 2 + n + 1] && use[n / 2 + 1] == 0) bit++;

	cout << x + y - bit << '\n';
}