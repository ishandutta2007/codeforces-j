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
                           int m,x,n,y,z,x1,k,one,gd,x2,y2,two,mn=1e9,mid,l,r,pos,a[500003],b[500003],c[500003],d[500003];vector<int>vr,v2[100003];long long sum,ans,num;char ch;
                                            //vector<pair<int,char>>r1,r2;
                            map<char,vector<int> > mp1;
                            set<int>myset;//its not muuultiset
                            bool yes,lft,rt;
                            multiset<string>lfts[100001],rts[100001];
                            vector<pair<long long,long long> >v1,tmpv;
                            char movx,movy;
                            multiset<int>muls;
                            bool vis[100001];
                            int t,sum2,y3,z3,mx2,mx;bool used;//))(())))
                            bool hast[200001];
                            int prevx,prevy;
                            int grid[14][14];
                            map<int,int>mymp,mymp2;
                            vector<int>myst;
                            multiset<int>mset; set<int>nset;
                            string s,ss;

                              vector<int>vx[100003];
                              vector<long long>v;



                            int main()
                            {

                                ios_base::sync_with_stdio(false);




                                cin>>t;
                                v.push_back(0);
                                while(ans<100000)
                                {
                                    ans++;
                                    v.push_back((ans*(ans+1))/2);

                                }
                                while(t--)
                                {
                                    cin>>x>>y;yes=false;
                                    long long val=abs(x-y);
                                    auto it=lower_bound(v.begin(),v.end(),val);
                                    int ind=it-v.begin();
                                    if(val==v[ind])cout<<ind<<endl;
                                    else
                                    {
                                        long long tmp=v[ind]-val;
                                        if(tmp%2==0)
                                        {
                                            cout<<ind<<endl;yes=true;

                                        }
                                        tmp=v[ind+1]-val;
                                        if(tmp%2==0&&!yes){cout<<ind+1<<endl;yes=true;}
                                        tmp=v[ind+2]-val;
                                        if(tmp%2==0&&!yes){cout<<ind+2<<endl;yes=true;}
                                    }

                                }


                                return 0;
                            }