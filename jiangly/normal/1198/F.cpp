// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,s;
pair<int,int> a[N];
int belong[N];
int main(){
    int start=clock();
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i].first);
        a[i].second=i;
        s=__gcd(s,a[i].first);
    }
    if(s>1){
        puts("NO");
        return 0;
    }
    mt19937 rnd(time(0));
    while(1.0*(clock()-start)/CLOCKS_PER_SEC<0.45){
        memset(belong,0,sizeof(belong));
        shuffle(a+1,a+n+1,rnd);
        int x=a[1].first,y=0;
        belong[a[1].second]=1;
        for(int i=2;i<=n;++i){
            if(a[i].first%x==0){
                y=gcd(y,a[i].first);
                belong[a[i].second]=2;
            }else{
                x=gcd(x,a[i].first);
                belong[a[i].second]=1;
            }
        }
        if(x==1&&y==1){
            puts("YES");
            for(int i=1;i<=n;++i){
                printf("%d ",belong[i]);
            }
            puts("");
            return 0;
        }
    }
    puts("NO");
    return 0;
}