#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

const int mod=1e9+7; // (119<<23)+1
template<int M,int R>
struct modnum{
	int v;
	static int minv(int a,int m){return (a%=m)==1?1:m-ll(minv(m,a))*m/a;}
	static constexpr modnum root(){return R;}
	static constexpr int mod(){return M;}
	modnum():v(0){}
	modnum(ll v_):v(int(v_%M)){if(v<0)v+=M;}
	explicit operator int()const{return v;}
	explicit operator bool()const{return v;}
	friend ostream&operator<<(ostream&out,const modnum&a){return out<<int(a);}
	friend istream&operator>>(istream&in,modnum&a){ll v;in>>v;a=modnum(v);return in;}
	friend bool operator==(const modnum&a,const modnum&b){return a.v==b.v;}
	friend bool operator!=(const modnum&a,const modnum&b){return a.v!=b.v;}
	modnum inv()const{return modnum(minv(v,M));}
	friend modnum inv(const modnum&a){return a.inv();}
	modnum neg()const{return modnum(v?M-v:0);}
	friend modnum neg(const modnum&a){return a.neg();}
	modnum operator-()const{return neg();}
	modnum operator+()const{return *this;}
	modnum&operator++(){if(++v==M)v=0;return*this;}
	modnum&operator--(){if(!v--)v=M-1;return*this;}
	modnum&operator+=(const modnum&a){if((v+=a.v)>=M)v-=M;return*this;}
	modnum&operator-=(const modnum&a){if((v-=a.v)<0)v+=M;return*this;}
	modnum&operator*=(const modnum&a){v=ll(v)*a.v%M;return*this;}
	modnum&operator/=(const modnum&a){return*this*=a.inv();}
	friend modnum operator++(modnum&a,int){modnum r=a;++a;return r;}
	friend modnum operator--(modnum&a,int){modnum r=a;--a;return r;}
	friend modnum operator+(const modnum&a,const modnum&b){return modnum(a)+=b;}
	friend modnum operator-(const modnum&a,const modnum&b){return modnum(a)-=b;}
	friend modnum operator*(const modnum&a,const modnum&b){return modnum(a)*=b;}
	friend modnum operator/(const modnum&a,const modnum&b){return modnum(a)/=b;}
	friend modnum mpow(modnum a,ll b){ // change this to pow and you'll never debug your code
		modnum res=1;
		for(;b;b>>=1,a*=a)if(b&1)res*=a;
		return res;
	}
};
using mint=modnum<mod,5>;

const int N = 40010;

bool ispal(int x) {
	auto sx = to_string(x);
	auto rsx = sx;
	reverse(rsx.begin(), rsx.end());
	return sx == rsx;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	vector<mint> res(N);
	vector<mint> dp(N);
	for (int i = 1; i < N; ++i) {
		if (ispal(i)) {
			++dp[i];
			for (int s = 0; s < i; ++s) {
				mint sm = 0, nsm;
				for (int j = s; j < N; j += i) {
					nsm = sm + dp[j];
					dp[j] += sm;
					sm = nsm;
				}
			}
		}
		res[i] = dp[i];
	}
	int tc = 1;
	cin >> tc;
	while (tc--) {
		int n; cin >> n;
		cout << res[n] << '\n';
	}
}