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

                    bool prime[100000001],prime2[1000001];
                    void sieve(){
                    for(int i=2;i<=100000000;i+=2)
                    prime[i]=false,prime[i-1]=true;
                    prime[2]=true;
                    for(int i=3;i*i<=100000000;i+=2)
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
                   int m,x,n,y,z,x1,k,one,gd,x2,y2,two,mn=3e9,mid,l,r,pos,a[500003],b[500003],c[500003],d[500003];vector<int>vr,v2[100003];long long sum,ans,num;char ch;
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
                    string s;
            int mx;
                    vector<int>vx[200003];
            bool visited[500000];
map<int,multiset<int> >mpr;


            string ss[5000];


                int main()
                {

                    ios_base::sync_with_stdio(false);

                  cin>>x>>y>>z>>k>>m;
                  int tmp=m;
                  if(z<k)swap(z,k),swap(x,y);
                    for(int i=0;i<x;i++)
                    {
                        if(tmp>z-1)
                        tmp-=z-1;
                        else tmp=0;

                    }
                    for(int i=0;i<y;i++)
                    {
                        if(tmp>k-1)
                        tmp-=k-1;
                        else tmp=0;

                    }
                    for(int i=0;i<x;i++)
                        if(tmp)ans++,tmp--;
                    for(int i=0;i<y;i++)
                        if(tmp)ans++,tmp--;
                    tmp=m;
                    for(int i=0;i<y;i++)
                    if(tmp>=k)tmp-=k,cnt++;
                    else tmp=0;
                    //cout<<tmp<<" "<<y<<" "<<cnt<<endl;
                    for(int i=0;i<x;i++)
                    if(tmp>=z)tmp-=z,cnt++;
                    else tmp=0;
                cout<<ans<<" "<<cnt;






                    return 0;
                }