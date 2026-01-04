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

#define maxn 100005
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int n, m;
long long t[maxn*4], lazyA[maxn*4], lazyB[maxn*4];

inline void push(int id, long long l, long long r){
	if(lazyA[id] || lazyB[id]){
		long long len = r-l+1;
		t[id] = (t[id] + ((r+l)*len/2%mod*lazyA[id])%mod + len*lazyB[id]%mod)%mod;

		if(l != r){
			lazyA[id*2] = (lazyA[id*2] + lazyA[id])%mod;
			lazyB[id*2] = (lazyB[id*2] + lazyB[id])%mod;
			lazyA[id*2+1] = (lazyA[id*2+1] + lazyA[id])%mod;
			lazyB[id*2+1] = (lazyB[id*2+1] + lazyB[id])%mod;
		}
		lazyA[id] = 0;
		lazyB[id] = 0;
	}
}

void update(int id, long long l, long long r, long long u, long long v, long long x, long long y){
	push(id, l, r);
	if(v<l || r<u)return;
	if(u <= l && r <= v){
		lazyA[id] = (lazyA[id] + x)%mod;
		lazyB[id] = (lazyB[id] + y)%mod;
		push(id, l, r);
		return ;
	}

	long long mid = l + (r-l)/2;
	update(id*2, l, mid, u, v, x, y);
	update(id*2+1, mid+1, r, u, v, x, y);
	t[id] = (t[id*2] + t[id*2+1])%mod;
}

long long get(int id, long long l, long long r, long long u, long long v){
	push(id, l, r);
	if(v<l || r<u)return 0;
	if(u<=l && r<=v)return t[id];
	
	long long mid = l + (r-l)/2;
	long long tl = get(id*2, l, mid, u, v);
	long long tr = get(id*2+1, mid+1, r, u, v);

	return (tl + tr)%mod;
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>m;

	while(m--){
		long long type, l, r; cin>>type>>l>>r;
		if(type == 1){
			long long a, b; cin>>a>>b;

			long long x = a;
			long long y = ((b - l*a)%mod+mod)%mod;
			update(1, 1, n, l, r, x, y);
		}else{
			cout<<get(1, 1, n, l, r)<<'\n';
		}
	}
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
