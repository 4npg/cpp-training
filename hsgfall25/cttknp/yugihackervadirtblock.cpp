// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define all(a) (a).begin(),(a).end()
int n;int64 k;
vector<int64> a;

bool check(int64 x){
	int64 target = 0;
	f0(i,n/2,n-1){
		if(a[i]<x)target+=x-a[i];
		if(target>k)return 0;
	}
	return 1;
}
int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	a.resize(n);
	f0(i,0,n-1)cin>>a[i];
	sort(all(a));
	int64 l = a[n/2],r=a[n/2]+k,ans=l;
	while(l<=r){
		int64 mid = l + ((r-l)>>1ll);
		if(check(mid)){
			ans = mid;
			l = mid+1;
		}else r=mid-1;
	}
	cout<<ans;
}


