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
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long N = 100100;
long long n, dp[N][3], h[2][N], ans;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;

	for(long long i = 1; i <= n; i++)
		cin >> h[0][i];
	for(long long i = 1; i <= n; i++)
		cin >> h[1][i];

	dp[1][0] = h[0][1];
	dp[1][1] = h[1][1];
	ans = max(h[0][1], h[1][1]);

	for(long long i = 2; i<= n; i++) {
		dp[i][0] = max({dp[i - 1][1], dp[i - 2][1]}) + h[0][i];
		dp[i][1] = max({dp[i - 1][0], dp[i - 2][0]}) + h[1][i];

		ans = max(ans, dp[i][0]);
		ans = max(ans, dp[i][1]);
		// dbg(i, dp[i][0], dp[i][1]);
	}
	cout << ans << '\n';
}