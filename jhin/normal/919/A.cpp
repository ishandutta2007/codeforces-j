// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;


#define ll long long
const int mod=1e9+7;
vector<int> p;
string s,s2;
ll n,x,y,sum,cnt1,cnt2,m;
int ho,se,mi;
void fix_time()
{   if(se>59)se-=60,mi++;if(se<0)se+=60,mi--;
    if(mi>59)mi-=60,ho++;if(mi<0)mi+=60,ho--;
    if(ho<0)ho+=24;if(ho>23)ho-=24;
}
ll my_pow(int x,int y)
{    ll num=1;
    for(ll i=x;y>0;i=(i*i)%mod,y>>=1)
        if(y&1)num=((num%mod)*i)%mod;
    return num%mod;
}
void pfact(int x)
{   if(x%2==0){p.push_back(2);while(x%2==0)x/=2;}
    for(int i=3;i*i<=x;i+=2)
        if(x%i==0){p.push_back(i);while(x%i==0)x/=i;}
    if(x>1)p.push_back(x);
}



float d=mod,t=mod;
int main()
{
   ios_base::sync_with_stdio(false);
   cin>>n>>m;
  for(int i=0;i<n;i++)
  {
      cin>>x>>y;t=float(x)/y;d=min(d,t);
  }
  int nums=(d>1)?log10(int(d)):0+1;
 cout<<setprecision(nums+10)<<m*d;
    return 0;
}