//Codeforces Round 100
//4 Jan 2012

//start of jonathanirvings' template v1.1.0 (BETA)

#define jonathan using
#define ganteng namespace
#define banget std
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <deque>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <map>
jonathan ganteng banget;

typedef long long LL;
typedef vector <int> vi;
typedef vector <vi> vii;
typedef vector <LL> vl;
typedef vector <vl> vll;
typedef vector <string> vstr;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef pair<string,string> pss;

double EPS = 1e-9;
int INF = 2000000000;
long long INFF = 8000000000000000000LL;
double PI = acos(-1);

#define DEBUG printf("====TESTING====\n")
#define VALUE(x) cout << "The value of " << #x << " is " << x << endl;
#define FOR(a,b,c) for (int (a)=(b);(a)<(c);(a)++)
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);(a)++)
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);(a)--)
#define FORL(a,b,c) for (LL (a)=(b);(a)<=(c);(a)++)
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);(a)++)
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define REPD(i,n) FORD(i,n,1)
#define MAX(a,b) a = max(a,b);
#define MIN(a,b) a = min(a,b);
#define SQR(x) ((x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define ALLA(arr,sz) arr+1,arr+1+sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define PERMUTE(v) next_permutation(ALL(v))
#define PERMUTEA(arr,sz) next_permutation(ALLA(arr,sz))
#define TC(t) while(t--)

inline string IntToString(int a)
{
    char x[100];
    sprintf(x,"%d",a); string s = x;
    return s;
}

inline int StringToInt(string a)
{
    char x[100]; int res;
    strcpy(x,a.c_str()); sscanf(x,"%d",&res);
    return res;
}

inline string GetString(void)
{
	char x[1000005];
	scanf("%s",x); string s = x;
	return s;
}

inline bool angka(char a) { return (a >= '0' && a <= '9'); }
inline bool kecil(char a) { return (a >= 'a' && a <= 'z'); }
inline bool besar(char a) { return (a >= 'A' && a <= 'Z'); }

inline string uppercase(string s){
	int n = SIZE(s); REP(i,n) if (kecil(s[i])) s[i] = s[i] - 'a' + 'A';
	return s;
}

inline string lowercase(string s){
	int n = SIZE(s); REP(i,n) if (besar(s[i])) s[i] = s[i] - 'A' + 'a';
	return s;
}

//end of jonathanirvings' template v1.1.0 (BETA)

int n,a;
map <int,int> pos;
vii ans;
pii data[100005];
priority_queue<pii> pq;

int main()
{
    scanf("%d",&n);
    int m = 0;
    REPN(i,n)
    {
    		scanf("%d",&a);
    		if (pos.count(a) == 0)
    		{
    			m++;
    			pos[a] = m;
    			data[m] = mp(1,a);
    		} else
    		{
    			data[pos[a]].fi++;
    		}
    }
    SORTA(data,m);
    REVERSEA(data,m);
    REPN(i,m) pq.push(data[i]);
    if (m < 3)
    {
    		puts("0");
    		return 0;
    }
    while (1)
    {
    		if (data[3].fi > 0)
    		{
    			vi tmp;
    			tmp.pb(data[1].se);
    			tmp.pb(data[2].se);
    			tmp.pb(data[3].se);
    			pii satu = pq.top();
    			pq.pop();
    			pii dua = pq.top();
    			pq.pop();
    			pii tiga = pq.top();
    			pq.pop();
    			ans.pb(tmp);
    			satu.fi--;
    			dua.fi--;
    			tiga.fi--;
    			pq.push(satu);
    			pq.push(dua);
    			pq.push(tiga);
    			REPN(i,3) 
    			{
    				data[i] = pq.top();
    				pq.pop();
    			}
    			REPN(i,3) pq.push(data[i]);
    		} else break;
    }
    int sz = SIZE(ans);
    printf("%d\n",sz);
    REP(i,sz)
    {
    		SORT(ans[i]);
    		printf("%d %d %d\n",ans[i][2],ans[i][1],ans[i][0]);
    }
	return 0;
}