#include <bits/stdc++.h>
#include <math.h>
#include <chrono>
using namespace std;
#pragma GCC optimize("-O3")
#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int32_t, int32_t>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10), cin.tie(0), cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).size())
#define what(x) cerr << #x << " is " << x << endl;
//typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x
//mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());uniform_int_distribution<int> distr(0, 1e9);auto my_rand = bind(distr, gen); // my_rand() zwraca teraz liczbe z przedzialu [a, b]
//gp_hash_table<long long, int, custom_hash> safe_hash_table; -szybsza hashmapa

ostream &operator<<(ostream &out, string str)
{
    for (char c : str)
        out << c;
    return out;
}
template <class L, class R>
ostream &operator<<(ostream &out, pair<L, R> p)
{
    return out << "(" << p.st << ", " << p.nd << ")";
}
template <class T>
auto operator<<(ostream &out, T a) -> decltype(a.begin(), out)
{
    out << '{';
    for (auto it = a.begin(); it != a.end(); it = next(it))
        out << (it != a.begin() ? ", " : "") << *it;
    return out << '}';
}
void dump() { cerr << "\n"; }
template <class T, class... Ts>
void dump(T a, Ts... x)
{
    cerr << a << ", ";
    dump(x...);
}
#define debug(...) cerr << "[" #__VA_ARGS__ "]: ", dump(__VA_ARGS__)

//#define int long long

const int MAXA = 6;
int n;

bool solve(vector<pii> Q, int s)
{
    int rozmiar = sz(Q);
    vector<pii> R;
    rep(i, rozmiar) R.emplace_back(Q[i].st + s + 1, -Q[i].nd);
    std::vector<pii> dst;
    std::merge(Q.begin(), Q.end(), R.begin(), R.end(), std::back_inserter(dst));

    vector<int> M(n + 22);
    int tmp = 0;

    for (auto &q : dst)
    {
        int r = abs(q.nd);
        if (M[r] == 0)
            tmp++;
        M[r] += (q.nd > 0 ? 1 : -1);
        if (M[r] == 0)
            tmp--;
        if (tmp == n)
            return true;
    }
    return false;
}

int32_t main()
{
    _upgrade;
    map<int, vector<int>> M;
    int n;
    cin >> n;
    vector<int> res(n);

    int idx = 0;
    rep(i, 2 * n)
    {
        char c;
        cin >> c;
        if (c == '+')
            M[0].push_back(idx++);
        else
        {
            int a;
            cin >> a;
            // debug(a, M);

            vector<int> X;
            vector<int> moje;

            for (auto m : M)
            {
                if (m.st > a)
                    break;
                X.push_back(m.st);
                if (sz(m.nd) > sz(moje))
                    m.nd.swap(moje);

                for (int a : m.nd)
                    moje.push_back(a);
            }
            for (auto x : X)
                M.erase(x);
            if (sz(moje) == 0)
            {
                cout << "NO" << endl;
                exit(0);
            }
            res[moje.back()] = a;
            moje.pop_back();
            M[a] = vector<int>();
            M[a].swap(moje);
        }
    }
    cout << "YES\n";
    for (int a : res)
        cout << a << " ";
    cout << endl;
}