// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 350
#define pb push_back
#define all(a) (a).begin(),(a).end()
int64 gcd(int64 a, int64 b){
	if(b==0)return a;
	return gcd(b,a%b);
}

int64 lcm(int64 a, int64 b){
	if(a==0||b==0)return 0;
	return (a/gcd(a,b))*b;
}

int n;
bool d[maxn];
void sang(){
	d[0] = d[1] = 1;
	for(int i =2;i*i<maxn;++i){
		if(d[i] == 0){
			for(int j = i*i;j<maxn;j+=i)d[j] = 1;
		}
	}
}
int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	sang();
	cin>>n;	
	vector<int64> pr;
	for(int i=2;i<=n;i++){
		if(!d[i])pr.pb(i);
	}

	vector<int64> prpw;
	for(auto p:pr){
		int64 tmp = p;
		while(tmp<=n){
			prpw.pb(tmp);
			if((long double)tmp*p>n)break;
			tmp*=p;
		}
	}

	sort(all(prpw));
	vector<int64> dp(n+1,0);
	dp[0] = 1;
	for(auto pp:prpw){
		for(int i=n;i>=pp;--i){
			if(dp[i-pp]>0){
				dp[i] = max(dp[i],lcm(dp[i-pp],pp));
			}
		}
	}

	int64 mxlcm = 0;
	f0(i,1,n){
		mxlcm = max(mxlcm,dp[i]);
	}

	cout<<mxlcm;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


