// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define pb push_back
int n;
const int maxn = 110;

int sum;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	vector<int> a(n);
	f0(i,0,n-1){
		cin>>a[i];
		sum+=a[i];
	}
	vector<bool> dp(sum+1,0);
	dp[0] = 1;
	for(auto &x:a){
		for(int s=sum;s>=x;--s){
			if(dp[s-x]){
				dp[s]=1;
				cout<<s<<" ";
			}
		}
		cout<<'\n';
	}
	vector<int> ans;
	f0(s,1,sum){
		if(dp[s])ans.pb(s);
	}
	cout<<'\n'<<ans.size()<<'\n';
	for(auto &x:ans){
		cout<<x<<" ";
	}
}


