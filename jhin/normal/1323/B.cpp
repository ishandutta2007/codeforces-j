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

            cin>>n>>m>>k;
            int rec=n*m;
            for(int i=1;i*i<=k;i++)
            {

                if(k%i==0)
                    vr.push_back(i);

            }

            for(int i=0;i<n;i++)cin>>a[i];
            for(int i=0;i<m;i++)cin>>b[i];
            //for(int i=0;i<vr.size();i++)cout<<vr[i]<<" ";cout<<endl;

            for(int i=0;i<vr.size();i++)
            {
                int num=vr[i];int cnt1=0,cnt2=0;
                for(int j=0;j<n;j++)
                {
                if(j==0){sum=a[j],c[0]=sum;
                if(num==1&&sum==1)cnt1=1;}

                else
                {
                    //cout<<a[j]<<" ";
                    if(a[j]==0)sum=0;
                    sum+=a[j];
                    if(sum>=num)
                    {sum=num;
                    c[j]=sum;
                    cnt1++;
                    //cout<<a[j]<<" ";
                    }

                }
                }
                //for(int j=0;j<n;j++)cout<<c[j]<<" ";cout<<endl;
                num=k/vr[i];
                //<<num<<endl;
                for(int j=0;j<m;j++)
                {
                    //cout<<b[j]<<" ";
                if(j==0){sum=b[j],d[0]=sum;
                if(num==1&&sum==1)cnt2=1;}
                else
                {
                    if(b[j]==0)sum=0;
                    sum+=b[j];
                    if(sum>=num)
                    {sum=num;
                    d[j]=sum;
                    cnt2++;
                    }

                }
                }
              // cout<<endl<<cnt1<<" "<<cnt2<<endl;
                ans+=cnt1*cnt2;
                cnt1=0;cnt2=0;
//cout<<ans<<endl;

                for(int j=0;j<n;j++)
                {
                if(j==0){sum=a[j],c[0]=sum;
                if(num==1&&sum==1)cnt1=1;}
                else
                {
                    if(a[j]==0)sum=0;
                    sum+=a[j];
                    if(sum>=num)
                    {sum=num;
                    c[j]=sum;
                    cnt1++;
                    }

                }
                }//cout<<cnt1<<" h"<<num<<endl;
                num=vr[i];
                if(k/vr[i]!=vr[i]){
                for(int j=0;j<m;j++)
                {
                if(j==0){sum=b[j],d[0]=sum;
                if(num==1&&sum==1)cnt2=1;}
                else
                {
                    if(b[j]==0)sum=0;
                    sum+=b[j];
                    if(sum>=num)
                    {sum=num;
                    d[j]=sum;
                    cnt2++;
                    }

                }

                }
                //cout<<cnt1<<" "<<cnt2<<endl;
                ans+=cnt1*cnt2;


            }}
//for(int i=0;i<n;i++)cout<<c[i]<<" ";
           cout<<ans;











                    return 0;

        }