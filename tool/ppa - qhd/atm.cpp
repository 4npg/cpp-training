// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b);++i)
#define fd(i,a,b) for(int i = (a); i >= (b);--i)
#define file "atm"

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 100
#define lg 20
#define inf (int)1e9

int n, s;
int d[maxn];

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	 freopen(file".inp", "r", stdin);
	 freopen(file".out", "w", stdout);

	cin>>n>>s;
	f0(i, 0, n-1)cin>>d[i];

	vector<int> dp(s+1, inf);
	vector<int> tr(s+1, -1);

	dp[0] = 0;
	f0(i, 0, n-1){
		f0(x, d[i], s){
			if(dp[x] > dp[x-d[i]]+1){
				dp[x] = dp[x-d[i]] + 1;
				tr[x] = i;
			}
		}
	}

	cout<<dp[s]<<'\n';

	vector<int> cnt(n, 0);
	int cur = s;
	while(cur>0){
		int i = tr[cur];
		cnt[i]++;
		cur -= d[i];
	}

	f0(i, 0, n-1){
		cout<<cnt[i]<<(i+1<n?' ':'\n');
	}
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
