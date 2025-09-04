// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int n,m;
int64 t;
vector<int64>a,b;

int64 xuli(const vector<int64>&v,int64 t){
	int64 sum=0;
	for(auto &x:v)sum+=t/x;
	return sum;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t>>n;
	a.resize(n);
	f0(i,0,n-1)cin>>a[i];
	cin>>m;
	b.resize(m);
	f0(i,0,m-1)cin>>b[i];

	int64 l=0,r=t,ans=0;
	while(l<=r){
		int64 mid = l + ((r-l)>>1ll);
		ans = max(ans,min(xuli(a,mid),xuli(b,t-mid)));
		if(xuli(a,mid)<xuli(b,t-mid))l=mid+1;
		else r = mid -1;
	}
	cout<<ans;
}


