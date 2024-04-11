#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

// using namespace __gnu_pbds; 
using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;  // ordered_set <int> s; // order_of_key(value)

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second


// const int N = ;
int n, k, m, a, b, p;
multiset <int> atk, def, me;
vector <int> va, vme;

int try2(int x) {
	int ans = 0;
	// dbg(x);
	// dbg(va);
	// dbg(vme);
	for(int i = 0; i < x; i++) {
		if(vme[vme.size() - x + i] < va[i]) return 0;
		ans += vme[vme.size() - x + i] - va[i];
	}
	// dbg(ans);
	return ans;
}

string s;

int try1() {
	// doar atk
	int ans = 0;
	for(auto i : def) {
		auto it = me.upper_bound(i);
		if(it == me.end()) return 0;
		me.erase(it);
	}

	for(auto i : atk) {
		auto it = me.lower_bound(i);
		if(it == me.end()) return 0;
		// dbg(i, *it);
		ans += *it - i;
		me.erase(it);
	}

	for(auto i : me)
		ans += i;
	// dbg(ans);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for(int i = 1; i <= n; i++) {
		cin >> s >> p;
		if(s == "ATK") atk.insert(p), va.push_back(p);
		else def.insert(p);
	}

	for(int i = 1; i <= m; i++) {
		cin >> p;
		me.insert(p);
		vme.push_back(p);
	}

	sort(va.begin(), va.end());
	sort(vme.begin(), vme.end());

	int ans = try1();
	for(int i = 1; i <= min(vme.size(), va.size()); i++)
		ans = max(ans, try2(i));
	cout << ans << '\n';
}