// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file "cau4"

// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 1
#define inf (int64)4e18
#define pb push_back
#define pob pop_back
#define pof pop_front

int64 ans;
int s, n;


con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>s>>n;

	vector<int64> dp(s+1, -inf), ndp;

	dp[0] = 0;

	f0(i, 0, n-1){
		int64 v, w, k;
		cin>>v>>w>>k;

		if(w>s)continue;

		if(k*w >=s){
			f0(j, w, s){
				dp[j] = max(dp[j], dp[j-w] + v);
			}
			continue;
		}
		
		ndp = dp;

		f0(r, 0, w-1){
			deque<int> dq;

			for(int t=0, j=r; j<=s; t++, j+=w){
				int64 val = dp[j] - t*v;

				while(!dq.empty()){
					int u = dq.back();
					int ju = r+u*w;
					if(dp[ju] - u*v <=val)dq.pop_back();
					else break;
				}
				dq.pb(t);

				while(!dq.empty() && dq.front()<t-k)dq.pof();

				int u = dq.front();
				int ju = r+u*w;
				ndp[j] = max(ndp[j], dp[ju] + (t-u)*v);
			}
		}
		dp.swap(ndp);
	}

	for(auto &x:dp)ans = max(ans, x);

	cout<<ans;
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
