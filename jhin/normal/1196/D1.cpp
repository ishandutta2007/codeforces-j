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
int m,x,n,y,z,x1,k,one,gd,x2,y2,two,mn=1e9,mid,l,r,pos,a[4][500003],b[500003],c[500000],c2[500000];string s2;vector<int>v,vr,v2[100003];unsigned long long sum,ans,num;char ch;
    //vector<pair<int,char>>r1,r2;
    map<char,vector<int> > mp1;
    set<int>myset;//its not muuultiset
    string s1;bool yes,lft,rt;
    multiset<string>lfts[100001],rts[100001];
    vector<pair<long long,long long> >v1,tmpv;
    char movx,movy;
    vector<int>vx[100001];
    int post[10000000][2];
    int t,sum2,y3,z3,mx2,mx;bool used;//))(())))
    bool hast[200001];
    int prevx,prevy;
    map<int,int>mymp,mymp2;
    vector<int>myst;
    string ss,s3;
    map<int,int>mpt;int nums[11],sums[11];

    int main()
    {

    ios_base::sync_with_stdio(false);

cin>>t;
while(t--){
    cin>>n>>k;
    cin>>ss;string ss1=ss,ss2=ss,ss3=ss;ss1[0]='R';ss2[0]='G',ss3[0]='B';
    for(int i=1;i<ss.size();i++)
    {
        if(ss1[i-1]=='R')ss1[i]='G';
        if(ss1[i-1]=='G')ss1[i]='B';
        if(ss1[i-1]=='B')ss1[i]='R';
        if(ss2[i-1]=='R')ss2[i]='G';
        if(ss2[i-1]=='G')ss2[i]='B';
        if(ss2[i-1]=='B')ss2[i]='R';
        if(ss3[i-1]=='R')ss3[i]='G';
        if(ss3[i-1]=='G')ss3[i]='B';
        if(ss3[i-1]=='B')ss3[i]='R';
    }
    int cnt1=0,cnt2=0,cnt3=0,ans1=1e5,ans2=1e5,ans3=1e5;
    for(int i=0;i<k;i++)
    {
        if(ss[i]!=ss1[i])cnt1++;
        if(ss[i]!=ss2[i])cnt2++;
        if(ss[i]!=ss3[i])cnt3++;

    }
    ans1=cnt1;ans2=cnt2,ans3=cnt3;
    for(int i=k;i<n;i++)
    {
        if(ss[i-k]!=ss1[i-k])cnt1--;
        if(ss[i]!=ss1[i])cnt1++;
        ans1=min(cnt1,ans1);
        if(ss[i-k]!=ss2[i-k])cnt2--;
        if(ss[i]!=ss2[i])cnt2++;
        ans2=min(cnt2,ans2);
        if(ss[i-k]!=ss3[i-k])cnt3--;
        if(ss[i]!=ss3[i])cnt3++;
        ans3=min(cnt3,ans3);

    }
    cout<<min(ans1,min(ans2,ans3))<<'\n';

    }


    return 0;
    }