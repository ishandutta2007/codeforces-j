           #include <bits/stdc++.h>

            using namespace std;




            const int mod=1e9+7;
            vector<long long> p;


            int ho,mi,se,ho1,mi1;
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
            vector<long long>vv,vv1;int cnt=0;
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
           int m,x,n,y,z,x1,k,one,gd,x2,y2,two,mn=1e9,mid,l,r,pos,a[50000003],b[500003],c[500003],d[500003];vector<int>vr,v2[100003];long long sum,ans,num;char ch;
                            //vector<pair<int,char>>r1,r2;
            map<char,vector<int> > mp1;
            set<int>myset;//its not muuultiset
            bool yes,lft,rt;
            multiset<string>lfts[100001],rts[100001];
            vector<pair<long long,long long> >v1,tmpv;
            char movx,movy;
            multiset<int>muls;
            bool vis[100001];
            long long t,sum2,y3,z3,mx2;bool used;//))(())))
            bool hast[200001];
            int prevx,prevy;
            int grid[14][14];
            map<int,int>mymp,mymp2;
            vector<int>myst;
            multiset<int>mset; set<int>nset;
            string s,ss;
    int mx;
            vector<int>vx[100003];
    bool visited[500000];


    map<int,int>mymap;
        int main()
        {

            ios_base::sync_with_stdio(false);

            cin>>t;
            while(t--)
            {


            cin>>n;
            set<int>eve,odd;
sum=0;
            for(int i=0;i<n;i++)
            {
                cin>>a[i];if(a[i]%2==0)eve.insert(i+1);
                else odd.insert(i+1);
            }
if(odd.size()==1&&eve.size()==0)cout<<-1<<endl;
else
    if(eve.size()>0)cout<<1<<endl<<*eve.begin()<<endl;
else if(odd.size()>1)
{
    cout<<2<<endl;
    for(auto it=odd.begin();it!=odd.end();it++)
    {
        int ind=*it;
        sum+=a[ind-1];
        cout<<ind<<" ";
        if(sum%2==0){cout<<endl;break;}
    }
}



            }






                    return 0;

        }