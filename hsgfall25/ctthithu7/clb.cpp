// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file "STEM"
#define maxn 2000000

int n;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen(file".inp","r",stdin);
	freopen(file".out","w",stdout);
	cin>>n;
	vector<int> cnt(maxn+1,0);

	int x,mx = 0;
	f0(i,0,n-1){
		cin>>x;
		cnt[x]++;
		mx = max(mx,x);
	}	

	int64 ans = 0;
	f0(k,1,mx){
		int64 clb = 0;

		for(int m = k; m<=mx; m+=k){
			clb += cnt[m];
		}
		ans = max(ans, clb*k);
	}

	cout<<ans;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}





