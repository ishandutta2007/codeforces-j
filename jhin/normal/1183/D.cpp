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
int m,n,z,x1,k,one,gd,x2,y2,two,mn=1e9,mid,l,r,pos,a[500003],b[2003];string s3;vector<int>v;int sum,ans,num;
bool yes;int t;long long x,y;
multiset<pair<int,int> > df;

set<int>myset;//its not muuultiset
string s[1000003],s4;
vector<int>v1,v2;int fi,se,thi,fii,see,thii;
multiset<int>mulset;int mx;
bool nums[200001][6];

int main()
{

ios_base::sync_with_stdio(false);

cin>>t;
while(t--)
{
cin>>n;map<int,int>mp;set<int>sset;y=0;
for(int i=0;i<n;i++){cin>>x;mp[x]++;}
for(auto it=mp.begin();it!=mp.end();it++)
{   int tmp=it->second;
    while(1)
    {
        auto it2=sset.lower_bound(tmp);


        if(tmp==0)break;
        if((*it2)==tmp)tmp--;
        else {sset.insert(tmp);break;}
    }
    //cout<<tmp<<endl;
}
for(auto it=sset.begin();it!=sset.end();it++)y+=*it;
cout<<y<<endl;



}



return 0;
}