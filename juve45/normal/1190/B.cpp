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

const int N = 100100;
int n, a[N], ans, nr;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 2; i <= n; i++)
		if(a[i] == a[i - 1])
			nr++;
	if(nr > 1)
		return cout << "cslnb\n", 0;

	if(nr == 1) {
		for(int i = 2; i <= n; i++)
			if(a[i] == a[i - 1])
				if(a[i] == 0 || (i > 2 && a[i - 2] + 1 == a[i - 1]))
					return cout << "cslnb\n", 0;
	}

	for(int i = 1; i <= n; i++)
		ans += a[i] - (i - 1);
	if(ans % 2 == 0)
		cout << "cslnb\n";
	else 
		cout << "sjfnb\n";

}