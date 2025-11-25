// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 3000006
#define pb push_back
#define all(a) (a).begin(),(a).end()
int n;
int a[maxn];
bool check(int k){
	int64 x = (int64)a[k] + n;
	vector<int> caps;
	caps.reserve(n-1);

	f0(j,0,n-1){
		if(j==k)continue;
		int64 cap = x - a[j];
		if(cap<=0)return false;
		if(cap>n-1)cap = n-1;
		caps.pb((int)cap);
	}
	sort(all(caps));
	f0(t,1,n-1){
		if(caps[t-1]<t)return false;
	}
	return true;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n;
	f0(i,0,n-1)cin>>a[i];

	sort(a,a+n, greater<int>());

	int lo = 0, hi = n, ans = 0;

	while(lo<=hi){
		int mid = lo + ((hi-lo)>>1);
		if(mid==0){
			if(0>ans) ans = 0;
			lo = mid + 1;
			continue;
		}
		int idx = mid - 1;
		if(idx < n && check(idx)){
			ans = mid;
			lo = mid +1;
		}else hi = mid -1;
	}

	cout<<ans;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


