#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
inline int read()
{
	int s=0,f=1; char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=1e6+20;

int n;

char str[maxn];
int s=0;

int main()
{
	n=read();
	scanf("%s",str+1);
	REP(i,1,n)s+=str[i]=='(',s-=str[i]==')';
	if(s)puts("-1"),exit(0);
	int ans=0,now=0;
	for(int i=1;i<=n;)
	{
		if(str[i]=='(')
		{
			now=1;
			int j;
			for(j=i+1;j<=n && now>0;j++)
			{
				if(str[j]==')')now--;
				else now++;
			}
			i=j;
		}else
		{
			now=-1;
			int j;
			for(j=i+1;j<=n && now<0;j++)
			{
				if(str[j]==')')now--;
				else now++;
			}
			ans+=j-i;
			i=j;
		}
	}
	printf("%d\n",ans);
	return 0;
}