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
    unsigned long long my_pow(int x,int y)
    {  unsigned  long long num=1;
        for(unsigned long long i=x;y>0;i=(i*i),y>>=1)
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
int m,x,n,y,z,x1,k,one,gd,x2,y2,w,two,mn=1e9,mid,l,r,pos,a[600003],b[500003];vector<int>v,vr,v2[100003];long long sum,ans,num;char ch;
                    //vector<pair<int,char>>r1,r2;
    map<char,vector<int> > mp1;
    set<int>myset;//its not muuultiset
    bool yes,lft,rt;
    multiset<string>lfts[100001],rts[100001];
    vector<pair<long long,long long> >v1,tmpv;
    char movx,movy;
    multiset<int>muls;
    map<int,int>mp;
    int t,sum2,y3,z3,mx2,mx;bool used;//))(())))
    bool hast[200001];
    int prevx,prevy;
    map<int,int>mymp,mymp2;
    vector<int>myst;
    multiset<int>mset; set<int>nset;
    string s,ss;
    int bar[54][54],bar2[54][54];vector<int>tmpre;
    char arr[5][305];
    multiset<int>aa[200001];
    int xx[100100];
    int A,B,C,D,E;



    int main()
    {


        ios_base::sync_with_stdio(false);


        cin>>t;
        while(t--)
        {
            cin>>n>>x;yes=false;vector<int>tmp;mx=0;y=0;mn=1e9;
            for(int i=0;i<n;i++){cin>>a[i]>>b[i];mx=max(mx,a[i]);}
            for(int i=0;i<n;i++){
            if(a[i]>=x)yes=true;
            else if(a[i]>b[i])mn=min(mn,(x-mx+a[i]-b[i]-1)/(a[i]-b[i])+1);

            }
            if(yes)cout<<1;
            else if(mn!=int(1e9))cout<<mn;
            else cout<<-1;
            cout<<endl;

        }










        return 0;
    }