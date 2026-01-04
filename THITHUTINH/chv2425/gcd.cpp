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

#define maxn 10000007
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int n ,m;
int d[maxn];
int cnta[maxn];
int cntb[maxn];

void sang(){
	for(int i=2; i<maxn; i++){
		if(!d[i]){
			for(int j=i; j<maxn; j+=i){
				if(!d[j])d[j] = i;
			}
		}
	}
}

long long mul(long long a, long long b){
	long long ans = 0;
	while(b){
		if(b&1)ans = (ans+a)%mod;
		a = (a+a)%mod;
		b>>=1;
	}
	return ans;
}

long long opw(long long a, long long b){
	long long ans = 1;
	while(b){
		if(b&1)ans = mul(ans, a);
		a = mul(a, a);
		b>>=1;
	}
	return ans;
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	sang();
	cin>>n>>m;
	while(n--){
		int x; cin>>x;
		while(x>1){
			int p = d[x];
			while(x%p==0){
				cnta[p]++;
				x/=p;
			}
		}
		if(x>1)cnta[x]++;
	}

	while(m--){
		int x; cin>>x;
		while(x>1){
			int p = d[x];
			while(x%p==0){
				cntb[p]++;
				x/=p;
			}
		}
		if(x>1)cntb[x]++;
	}

	long long ans = 1;
	f0(i, 2, maxn-1){
		if(cnta[i]>=1 && cntb[i]>=1){
			ans = mul(ans, opw(i, min(cnta[i], cntb[i])));
		}
	}

	cout<<ans;
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
