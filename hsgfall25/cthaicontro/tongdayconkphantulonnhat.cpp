// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

const int maxn = 1e6+5;
int64 a[maxn];
int n,k;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	f0(i,0,n-1){
		cin>>a[i];
	}	
	int64 cursum = 0;
	int64 maxs = 0;

	f0(i,0,k-1){
		cursum+=a[i];
	}
	maxs= cursum;
	f0(i,k,n-1){
		cursum+=a[i]-a[i-k];
		maxs = max(maxs,cursum);
	}
	cout<<maxs;
}


