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

// const long long N = ;
long long n, a;
map<long long, set <long long> > m;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(long long i = 1; i <= n; i++) {
		cin >> a;
		if(m.count(a) == 0) {
			m[a] = set <long long> ();
		}
		m[a].insert(i);
	}

	for(auto &i : m) {
		// dbg(i);
		while(i.nd.size() >= 2) {
			
			long long a = *i.nd.begin();
			i.nd.erase(i.nd.begin());
			long long b = *i.nd.begin();
			i.nd.erase(i.nd.begin());

			a = 2 * i.st;
			if(m.count(a) == 0)
				m[a] = set <long long> ();
			m[a].insert(b);		
		}
		// dbg(i);
	}

	vector <pair<long long, long long> > v;

	for(auto &i : m) {
		// dbg(i);
		for(auto j : i.nd)
			v.push_back({j, i.st});
	}

	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for(auto i : v) cout << i.nd << ' ';
}