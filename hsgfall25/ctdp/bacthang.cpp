// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

const int mod = 1e9+7;
int n,k;


int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	unordered_set<int> hong;
	f0(i,0,k-1){
		int x;
		cin>>x;
		hong.insert(x);
	}	
	int64 prev2=0,prev1=1;
	int64 cur =0;
	f0(i,2,n){
		if(hong.count(i))cur=0;
		else cur = (prev1+prev2)%mod;
		prev2 = prev1;
		prev1=cur;
	}
	cout<<((n==1?1:prev1)%mod);
}


