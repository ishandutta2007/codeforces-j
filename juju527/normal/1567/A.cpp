#include <bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
	int T;
	T=read();
	while(T--){
		int n;
		n=read();
		for(int i=1;i<=n;i++){
			char c;
			cin>>c;
			if(c=='L'||c=='R')cout<<c;
			else if(c=='U')cout<<"D";
			else cout<<"U";
		}
		puts("");
	}
    return 0;
}