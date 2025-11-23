// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 100005
#define pb push_back
#define pof pop_front
#define pob pop_back

int n,k;
int64 a[maxn];

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>k;
	f0(i,1,n){
		cin>>a[i];
	}	


	vector<int64> dp(n+1,LLONG_MIN);
	dp[0] = 0;
	deque<int> dq;
	int64 ans = LLONG_MIN;

	dq.pb(0);

	f0(i,1,n){
		while(!dq.empty() && dq.front() < i-k)dq.pof();

		int64 best = dq.empty() ? 0 : max<int64>(0, dp[dq.front()]);
		dp[i] = a[i] + best;
		while(!dq.empty() && dp[i] >= dp[dq.back()])dq.pob();
		dq.pb(i);
		ans = max(ans,dp[i]);
	}
	cout<<ans;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


