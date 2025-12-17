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

#define maxn 5000
int n;
int64 a[maxn];
int64 dp[maxn];
int64 ans;

i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n;
	f0(i, 1, n)cin>>a[i];
	dp[0] = 1;
	f0(i, 1, n){
		dp[i] = 1;
		f0(j, 1, n){
			if(a[i]>a[j])dp[i] = max(dp[i], dp[j]+1);
		}
		ans = max(ans, dp[i]);
	}

	cout<<ans;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}





