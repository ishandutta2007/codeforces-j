// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;


const int mod=1e9+7;
vector<long long> p;


int ho,mi,se,ho1,mi1;
void fix_time()
{   if(se>59)mi+=se/60,se=se%60;if(se<0)se+=60,mi--;
    if(mi>59)ho+=mi/60,mi=mi%60;if(mi<0)mi+=60,ho--;
    if(ho<0)ho+=24;if(ho>24)ho-=24;
}
long long my_pow(int x,int y)
{    long long num=1;
    for(long long i=x;y>0;i=(i*i),y>>=1)
        if(y&1)num=(num*i);
    return num;
}

bool prime[1000001],prime2[1000001];
void sieve(){
    for(int i=2;i<=1000000;i+=2)
        prime[i]=false,prime[i-1]=true;
    prime[2]=true;
    for(int i=3;i*i<=1000000;i+=2)
        if(prime[i])
            for(int j=i*i;j<=1000000;j+=2*i)
                prime[j]=false;
}
vector<long long>vv,vv1;int cnt=0;
void pfact(long long x)
{   if(x%2==0){p.push_back(2);while(x%2==0)x/=2,cnt++;vv.push_back(cnt);}
    for(long long i=3;i*i<=x;i+=2)
        if(x%i==0){cnt=0;p.push_back(i);while(x%i==0)x/=i,cnt++;vv.push_back(cnt);}
    if(x>1)p.push_back(x),cnt++,vv.push_back(1);
}
long long gcd(long long a , long long b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
long long m,x,n,y,z,x1,k,one,gd,x2,y2,two,mn=1e9,mid,l,r,pos,a[500003],b[500003],c[500000],c2[500000],dd[100];string s2;vector<int>v,vr,v2[100003];int sum,ans,num;char ch;
//vector<pair<int,char>>r1,r2;
map<string,int> mp1;
set<int>myset;//its not muuultiset
string s1;bool yes,lft,rt;
multiset<string>lfts[100001],rts[100001];
vector<pair<long long,long long> >v1,tmpv;
char movx,movy;
int vx[100001][2];
int post[10000000][2];
int t,sum2,y3,z3,mx2,mx;//))(())))
bool hast[200001];
int prevx,prevy;
map<int,int>mymp,mymp2;
set<long long>myst;
string s,ss;
int cv[502][502],cd[502][502],used[502][502];
vector<int>tmpkhra[502];
int main()
{

ios_base::sync_with_stdio(false);

cin>>n>>m;
for(int i=0;i<n;i++)cin>>a[i];
for(int i=0;i<m;i++)cin>>b[i];
x=a[1]-a[0];
for(int i=2;i<n;i++)x=gcd(x,a[i]-a[i-1]);
for(int i=0;i<m;i++)if(x%b[i]==0)return cout<<"YES"<<endl<<a[0]<<" "<<i+1,0;
cout<<"NO";
return 0;
}