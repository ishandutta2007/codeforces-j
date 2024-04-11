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

int n, m, a, b, c, dp[300100], ans;
vector <pair<int, pair<int, int> > > e;

int main() {
	ios_base::sync_with_stdio(false);	
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		e.push_back({c, {a, b}});
	}
	sort(e.begin(), e.end());
	
	int last = -1e9;
	vector <pair<int, int> > update;

	for(auto p : e) {
		// dbg(p);
		// dbg(update);
		if(p.st > last) {
			// dbg_ok;
			last = p.st;
			for(auto i : update)
				dp[i.st] = max(i.nd, dp[i.st]),
				ans = max(ans, dp[i.st]);
			update.clear();
		}

		update.push_back({p.nd.nd, dp[p.nd.st] + 1});
	}

	for(auto i : update)
		dp[i.st] = max(i.nd, dp[i.st]),
		ans = max(ans, dp[i.st]);
	cout << ans << '\n';
}