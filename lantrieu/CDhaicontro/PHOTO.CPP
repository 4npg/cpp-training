// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define inf (int64)2e18

int n;
int64 ans = inf;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	vector<int64> a(n);
	vector<int> t(n);
	f0(i,0,n-1){
		cin>>a[i]>>t[i];
	}

	map<int,int> cnt;
	int d = 0;
	int l = 0;
	f0(r,0,n-1){
		if(cnt[t[r]]==0)d++;
		cnt[t[r]]++;

		while(d==3){
			ans = min(ans,a[r]-a[l]);
			cnt[t[l]]--;
			if(cnt[t[l]]==0){
				cnt.erase(t[l]);
				d--;
			}
			l++;
		}
	}

	cout<<((ans==inf)?0:ans);

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


