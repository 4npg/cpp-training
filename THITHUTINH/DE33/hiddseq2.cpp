// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file ""

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//long long Rand(long long l, long long r){
//	return l+rng()%(r-l+1);
//}

#define maxn 200005
#define lg 18
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int n, q;
int l[maxn], r[maxn];
int R[maxn], up[lg][maxn];

inline bool get(int i, int j){
	return max(l[i], l[j]) <= min(r[i], r[j]);
}

void init(){
	f0(i, 1, n){
		up[0][i] = R[i] + 1;
		if(up[0][i] > n)up[0][i] = n+1;
	}

	f0(k, 1, lg-1){
		f0(i, 1, n){
			if(up[k-1][i] <= n)up[k][i] = up[k-1][up[k-1][i]];
			else up[k][i] = n+1;
		}
	}
}

void sub3(int a, int b){
	int cur = a, ans = 0;

	fd(k, lg-1, 0){
		if(cur<=n && up[k][cur]<=b){
			cur = up[k][cur];
			ans += (1LL<<k);
		}
	}
	if(cur<=b)ans++;
	cout<<ans<<'\n';
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n;
	f0(i, 1, n)cin>>l[i]>>r[i];

	f0(i, 1, n){
		R[i] = i;
		f0(j, i+1, n){
			bool f = 1;
			f0(k, i, j-1){
				if(get(k, j)){
					f = 0; break;
				}
			}
			if(!f)break;
			R[i] = j;
		}
	}
	
	init();

	cin>>q;
	while(q--){
		int a, b; cin>>a>>b;
		sub3(a, b);
	}
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
