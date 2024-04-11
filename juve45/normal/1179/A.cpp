#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, deque <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << p.st << ' ' << p.nd; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long N = 300100;
long long n, a, b, q;
deque <long long> dq;
pair<long long, long long> res[N];

int main() {
	ios_base::sync_with_stdio(false);	
	cin >> n >> q;

	for(long long i = 1; i <= n; i++)
		cin >> a, dq.push_back(a);

	for(long long i = 1; i <= n; i++) {
		long long a = dq.front();
		dq.pop_front();
		long long b = dq.front();
		dq.pop_front();
		res[i] = {a, b};
		dq.push_back(min(a, b));
		dq.push_front(max(a, b));
		// dbg(dq);
	}

	// dbg(dq);
	for(long long i = 1; i <= q; i++) {
		cin >> a;
		if(a <= n) cout << res[a] << '\n';
		else {
			long long b = (a - n) % (n - 1);
			if(b == 0) b = n - 1;
			cout << dq[0] << ' ' << dq[b] << '\n';
		}
	}
}