#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n; 

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%d\n", n == 2 ? 2 : 3); 
	}
}