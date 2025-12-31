// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
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
#define inf (int64)4e18
#define mod (int64)(1e9+7)

int n, m;
int par[maxn], sz[maxn];
int64 v[maxn], lazy[maxn];

void init(){
	f0(i, 1, n){
		par[i] = i;
		sz[i] = 1;
		v[i] = 0;
		lazy[i] = 0;
	}
}

int find(int x){
    while(par[x] != x) x = par[x];
    return x;
}



void join(int a, int b){
	a = find(a);
	b = find(b);

	if(a == b)return;
	if(sz[a] < sz[b])swap(a, b);

	v[b] = lazy[b] - lazy[a];
	par[b] = a;
	sz[a] += sz[b];
}

void add(int u, int av){
	u = find(u);
	lazy[u] += av;
}

int64 get(int x){
    int64 res = 0;
    while(par[x] != x){
    	res += v[x];
    	x = par[x];
    }

    return res + lazy[x];
}


con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>m;

	init();

	while(m--){
		string s;
		cin>>s;
		if(s == "join"){
			int x, y; cin>>x>>y;
			join(x, y);
		}else if(s == "add"){
			int x, val; cin>>x>>val;
			add(x, val);
		}else{
			int x; cin>>x;
			cout<<get(x)<<'\n';
		}
	}
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
