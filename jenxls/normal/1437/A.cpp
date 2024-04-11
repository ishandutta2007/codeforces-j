#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())

int T;
int l, r;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> T;

    while (T--) {
        cin >> l >> r;

        if (2 * l >= r + 1) cout << "YES\n";
        else cout << "NO\n";
    }
}