// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file "SUM"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 100005

int n;

youngboiz_nobug(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);

	cin>>n;

	int64 sum = 0;
	int64 ans = 0;

	map<int64, int64> cnt;

	cnt[0] = 1;

	f0(i, 1, n){
		int64 x; cin>>x;
		sum += x;
		ans += cnt[sum];

		cnt[sum]++;
	}

	cout<<ans;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}
