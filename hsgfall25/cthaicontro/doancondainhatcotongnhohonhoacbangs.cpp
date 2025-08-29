// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int n;
int64 s;
const int maxn = 1e6+5;
int64 a[maxn];

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>s;
	f0(i,0,n-1)cin>>a[i];

	int ans = 0;
	int lo = 0;
	int64 sum = 0;
	f0(hi,0,n-1){
		sum+=a[hi];
		while(sum>s&&lo<=hi){
			sum-=a[lo];
			lo++;
		}
		ans = max(ans,hi-lo+1);
	}
	cout<<ans;
}


