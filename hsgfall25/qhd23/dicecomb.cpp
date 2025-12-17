// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 1000006
#define mod 1000000007

int n;
int dp[maxn];

i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n;
	dp[0] = 1;
	f0(i, 1, n){
		f0(j, 1, 6){
			if(j<=i){
				dp[i] = (dp[i] + dp[i-j])%mod;
			}else break;
		}
	}

	cout<<dp[n]%mod;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}





