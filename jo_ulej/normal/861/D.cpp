#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <sstream>
#include <bitset>
#include <cassert>
#include <fstream>

#define len(X) ((int)(X).size())

#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e18);

const ll mod = 1e9 + 7;
const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

const int MAX_N = (int)1e5 + 777;

vector<ll> phone[MAX_N];
map<ll, int> cnt, length;
int n;

void solve()
{
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;

		for(int l = 0; l < len(s); ++l)
		{
			ll cur = 0;

			for(int r = l; r < len(s); ++r)
			{
				cur = 11 * cur + (ll)(s[r] - '0' + 1);

				phone[i].push_back(cur);
				length[cur] = r - l + 1;
			}
		}

		sort(phone[i].begin(), phone[i].end());
		phone[i].erase(unique(phone[i].begin(), phone[i].end()), phone[i].end());

		for(auto h: phone[i])
			++cnt[h];
	}

	for(int i = 0; i < n; ++i)
	{
		ll best = NIL;

		for(auto h: phone[i])
			if(cnt[h] == 1 && (best == NIL || length[h] < length[best]))
				best = h;

		string answ;

		while(best)
		{
			answ.push_back((char)('0' + best % 11 - 1));
			best /= 11;
		}

		reverse(answ.begin(), answ.end());
		cout << answ << "\n";
	}
}

int main()
{
	fast_io();
	solve();

	return 0;
}