        #include <bits/stdc++.h>

        using namespace std;




        const int mod=998244353;
        vector<long long> p;


        int ho,mi,se,ho1,mi1,cnt;
        void fix_time()
        {   if(se>59)mi+=se/60,se=se%60;if(se<0)se+=60,mi--;
            if(mi>59)ho+=mi/60,mi=mi%60;if(mi<0)mi+=60,ho--;
            if(ho<0)ho+=24;if(ho>=24)ho-=24;
        }
        unsigned long long my_pow(int x,int y)
        {  unsigned  long long num=1;
            for(unsigned long long i=x;y>0;i=(i*i),y>>=1)
                if(y&1)num=(num*i);
                    return num;
        }

        bool prime[10000001],prime2[1000001];
        void sieve(){
        for(int i=2;i<=10000000;i+=2)
        prime[i]=false,prime[i-1]=true;
        prime[2]=true;
        for(int i=3;i*i<=10000000;i+=2)
            if(prime[i])
                for(int j=i*i;j<=10000000;j+=2*i)
                    prime[j]=false;
                    }
        vector<long long>vv,vv1;
        void pfact(long long xx)
        {   if(xx%2==0){p.push_back(2);while(xx%2==0)xx/=2,cnt++;vv.push_back(cnt);}
                for(long long i=3;i*i<=xx;i+=2)
                        if(xx%i==0){cnt=0;p.push_back(i);while(xx%i==0)xx/=i,cnt++;vv.push_back(cnt);}
                            if(xx>1)p.push_back(xx),cnt++,vv.push_back(1);
        }
        long long gcd(long long a , long long b)
        {
          if(b==0) return a;
                   a%=b;
            return gcd(b,a);
        }
        long long m,x,n,y,z,k,mn=3e9,mx,ans,a[500001],b[500003];vector<int>v;char ch;

        string s;
        int t;
        bool yes;




        int main()
        {

        ios_base::sync_with_stdio(false);

        cin>>t;
        while(t--)
        {
            cin>>n;yes=false;mx=0;bool ly=true;long long sum=0;
            for(int i=0;i<n;i++){cin>>a[i];if(a[i]>0)yes=true;}



                long long tmpmx=0,tmpmn=-1e9;
                if(a[0]<0)ly=false;
            for(int i=0;i<n;i++)
            {
                if(ly&&a[i]>0)
                {

                    tmpmx=max(a[i],tmpmx);
                    if(i==n-1||a[i+1]<0){sum+=tmpmx;mx=max(mx,sum);
                    ly=false;
                    tmpmn=-1e9;}
                   // cout<<sum<<" f";
                }
                else if(!ly&&a[i]<0)
                {
                    tmpmn=max(tmpmn,a[i]);
                    if(a[i+1]>0||i==n-1)
                    {
                        sum+=tmpmn;
                        //cout<<sum<<" h";
                        ly=true;tmpmx=0;

                    }
                }



            }
            cout<<sum<<endl;



        }






        return 0;
        }