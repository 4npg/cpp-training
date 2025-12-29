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

#define maxn 200005
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)

// cho q quy van dang a, b kiem tra xem a va b co cung nam trong 1 thanh phan lien thong khong
// neu la truy van loai 0 thi noi thanh phan lien thong co dinh dai dien la a voi thanh phan lien thong co 
// dinh dai dien la b 
// neu la truy van loai 1 thi kiem tra xem dinh a va dinh b co nam trong cung mot thanh phan lien
// thong hay khong neu co thi in ra YES neu khong thi in ra la NO

int n, q;
int par[maxn], sz[maxn];

struct edge{
	int u, v;
};

vector<edge> a[maxn];

void init(){
	f0(i, 1, n){
		par[i] = i;
		sz[i] = 1;
	}
}

int find(int v){
	return v==par[v]?v:par[v] = find(par[v]);
}

void uni(int a, int b){
	a = find(a);
	b = find(b);

	if(a == b)return;

	if(sz[a] < sz[b])swap(a, b);
	par[b] = a;
	sz[a] += sz[b];
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>q;
	init();

	while(q--){
		int type, a, b; cin>>type>>a>>b;
		if(type == 0){
			uni(a, b);
		}else{
			cout<<(find(a) == find(b)?"YES\n":"NO\n");
		}
	}
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
