#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1
#define NMAX 1
#define MMAX 1

using namespace std;

int l, r;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
    cin >> l >> r;
    if(l == r) 
    {
        cout << l;
        return 0;
    }
    if (r/3 - (l+2)/3 > r/2 - (l+1)/2)
        cout << "3";
        else cout << 2;


}