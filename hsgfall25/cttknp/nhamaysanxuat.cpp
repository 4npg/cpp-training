// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define all(a) (a).begin(),(a).end()
int n;
const int maxn = 2e5+5;
int64 m;
vector<int64> a;

bool check(int64 t){
	int64 cnt = 0;
	for(auto &x:a){
		cnt+=t/x;
		if(cnt>=m)return 1;
	}
	return 0;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	a.resize(n);
	int64 mn = 1e15;
	f0(i,0,n-1){
		cin>>a[i];
		mn = min(mn,a[i]);
	}
	int64 l=0,r=mn*m,ans=r;
	while(l<=r){
		int64 mid = l + ((r-l)>>2);
		if(check(mid)){
			ans = mid;
			r = mid -1;
		}else l = mid + 1;
	}
	cout<<ans;
}


