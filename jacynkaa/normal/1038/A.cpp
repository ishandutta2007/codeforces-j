#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include<math.h>
using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define mp make_pair
#define double long double
#define fi first
#define se second

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x

main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout.setf(ios::fixed);

    int n,k;
    cin>>n>>k;
    string c;
    cin>>c;

    vector <int> X (k,0);

    for (int i=0; i<n; i++)
        X[c[i]-'A']++;

    int mini=123456789;

    for (int i=0; i<k; i++)
        mini=min(mini, X[i]);

    cout <<mini*k<<endl;
}