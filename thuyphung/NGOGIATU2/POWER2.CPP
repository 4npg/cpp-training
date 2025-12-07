// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 10004
#define pb push_back

int n;
int64 a[maxn];

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	

	map<int64, int> cnt;
	vector<int64> pw;
	f0(i, 0, 31){
		pw.pb(1LL<<i);
	}

	cin>>n;
	f0(i, 0, n-1)cin>>a[i];
	int64 res = 0;
	f0(i, 0, n-1){
		for(auto &p:pw){
			if(cnt.count(p-a[i]))res+=cnt[p-a[i]];
		}
		cnt[a[i]]++;
	}

	cout<<res;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


