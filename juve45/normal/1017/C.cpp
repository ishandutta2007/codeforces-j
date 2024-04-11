#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

int n, k;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	// out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	int ans = n + 1, ci = 1;
	for(int i = 1; i <= n; i++) {
		if ((n + i - 1) / i + i < ans) {
			ans = (n + i - 1) / i + i;
			ci = i;
		}
	}

	int nr = n;
	vector <int> v;
	for(int i = 1; i <= n; i+=ci) {
		for(int j = ci - 1; j >= 0; j--)
			if(nr - j > 0)
				v.push_back(nr - j);
		nr -= ci;
	}

	cout << v;
}