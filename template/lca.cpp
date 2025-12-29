// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file ""

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

// tim to tien chung gan nhat cua 2 dinh a va b 
// lowest common ancestor cua a va b 

#define maxn 200005
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)
#define pb push_back
#define fi first 
#define se second

int par[maxn], sz[maxn];

struct edge{
	int u, v;
	int64 w;
};

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
