// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 500000

int n;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file("BEAU");
	cin>>n;
	vector<int> a(n);
	f0(i,0,n-1){
		cin>>a[i];
	}

	vector<int> cnt(maxn+1,0);
	int64 ans = 0;

	int l = 0;
	f0(r,0,n-1){
		cnt[a[r]]++;
		while(cnt[a[r]]>2){
			cnt[a[l]]--;
			l++;
		}
		ans += (r-l+1);
	}

	cout<<ans; 

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


