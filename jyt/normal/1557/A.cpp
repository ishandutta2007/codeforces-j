#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
using std::cin;using std::cerr;
using std::max;using std::min;
#define N 100005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,A[N],Max;ll Sum;db ans;
int main()
{
	for(scanf("%d",&T);T--;Max=Sum=0)
	{
		scanf("%d",&n),Max=-1e9;
		for(int i=1;i<=n;i++) scanf("%d",&A[i]),Max=max(Max,A[i]),Sum+=A[i];
		ans=Max+(Sum-Max)*1./(n-1);
		printf("%.9lf\n",ans);
	}
	return 0;
}