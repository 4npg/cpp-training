// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int n;
int64 x;
vector<int64> p,t;

bool check(int64 mid){
	int64 total = 0;
	f0(i,0,n-1){
		if(mid>=p[i]){
			int64 cnt = 1 + (mid-p[i])/t[i];
			if(total>=x-cnt)return true;
			total += cnt;
		}
	}
	return total>=x;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>x;
	p.resize(n);
	t.resize(n);
	f0(i,0,n-1){
		cin>>p[i]>>t[i];
	}
	int64 lo=1,hi=1e18,ans=-1;
	while(lo<=hi){
		int64 mid = lo + (hi-lo)/2;
		if(check(mid)){
			ans = mid;
			hi = mid-1;
		}else{
			lo = mid + 1;
		}
	}
	cout<<ans;
}


