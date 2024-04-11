#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

map<int, int> mp;
int main(){
	int n;
	sd(n);
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		int a, x;
		sd(a); sd(x);
		mp[a] = max(mp[a], x);
	}
	sd(n);
	for(int i = 1; i <= n; i++){
		int a, x;
		sd(a); sd(x);
		mp[a] = max(mp[a], x);
	}

	for(auto it : mp) ans += it.S;
	printf("%lld\n", ans);
}