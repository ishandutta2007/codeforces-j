// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;


const int mod=1e9+7;
vector<long long> p;


int ho,mi,ho1,mi1;

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
bool chck(char d)
{
    if(d=='o'||d=='i'||d=='u'||d=='a'||d=='e')return true;
    return false;
}
int m,x,n,y,z,x1,k,one,gd,x2,y2,two,mn=1e9,mid,l,r,pos,a[500003],b[500003],c[500000],c2[500000],dd[100];string s3;vector<int>v;long long sum,ans,num;
bool yes;int t;
multiset<pair<int,int> > df;
map<char ,multiset<pair<int,string> > > mp;
set<int>myset;//its not muuultiset
string s[1000003],s4;
vector<int>v1,v2;int fi,se,thi,fii,see,thii;
multiset<int>mulset;int mx;
bool nums[200001][6];

int main()
{

ios_base::sync_with_stdio(false);

cin>>n;
for(int i=0;i<n;i++)
{
    cin>>a[i];
}
for(int i=1;i<=5;i++)nums[0][i]=1;
for(int i=1;i<n;i++)
{
    if(a[i]>a[i-1]){
        for(int j=1;j<=5;j++)
        {

        if(nums[i-1][j])
        for(int z=j+1;z<=5;z++)nums[i][z]=1;
        }
        }
    if(a[i]<a[i-1])
    {
        for(int j=1;j<=5;j++)
        {

        if(nums[i-1][j])
        for(int z=j-1;z>0;z--)nums[i][z]=1;
        }
    }
        if(a[i]==a[i-1])
    {
        for(int j=1;j<=5;j++)
        {

        if(nums[i-1][j])
        for(int z=1;z<=5;z++)if(z!=j)nums[i][z]=1;
        }
    }
}
for(int i=1;i<=5;i++)if(nums[n-1][i])b[n-1]=i;
for(int i=n-2;i>=0;i--)
{
    for(int j=1;j<=5;j++)
    {
        if(a[i]<a[i+1]&&j<b[i+1]&&nums[i][j])b[i]=j;
        if(a[i]>a[i+1]&&j>b[i+1]&&nums[i][j])b[i]=j;
        if(a[i]==a[i+1]&&j!=b[i+1]&&nums[i][j])b[i]=j;
    }
    if(!b[i])return cout<<-1,0;
}
for(int i=0;i<n;i++)cout<<b[i]<<" ";
return 0;
}