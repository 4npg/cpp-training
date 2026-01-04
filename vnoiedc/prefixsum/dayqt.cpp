// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b);++i)
#define fd(i,a,b) for(int i = (a); i >= (b);--i)
#define file ""

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 1000006
#define lg 20
#define inf 1000111000111000111LL
#define mod (long long)(1e9+7)

int n;
long long a[maxn], pre[maxn], suf[maxn];

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n;
	f0(i, 1, n)cin>>a[i];

	pre[0] = 0;
	f0(i, 1, n)pre[i] = pre[i-1] + a[i];
	suf[n+1] = 0;
	fd(i, n, 1)suf[i] = suf[i+1] + a[i];
 	
 	long long res = -1, cnt = 0, ln = -inf, nn = inf, c1 = 0, c2 = 0, now;

 	f0(i, 1, n-1){
 		if(pre[i] < nn){
 			nn = pre[i];
 			c1 = 1;
 		}else if(pre[i] == nn){
 			c1++;
 		}

 		if(pre[i] > ln){
 			ln = pre[i];
 			c2 = 1;
 		}else if(pre[i] == ln){
 			c2++;
 		}

 		now = ln - suf[i+1];
 		if(now > res){
 			res = now;
 			cnt = c2;
 		}else if(now == res){
 			cnt += c2;
 		}
 		now = suf[i+1] - nn;
 		if(now > res){
 			res = now;
 			cnt = c1;
 		}else if(now == res)cnt += c1;
 	}

 	if(!res)cnt/=2;
 	cout<<res<<" "<<cnt;
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
