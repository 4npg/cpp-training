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

#define maxn 500005
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int n, m;

struct truyvan{
	int t, u, v;
};

struct tree{

	int n, tot;
	int par[maxn*2], T[maxn*2];

	vector<int> g[maxn*2];
	int up[lg][maxn*2], h[maxn*2];

	int lg2(int v){
		return v?31-__builtin_clz(v):-1;
	}

	int find(int u){
		return u == par[u] ? u : par[u] = find(par[u]);
	}

	void init(int n){
		tot = n;
		f0(i, 1, n*2){
			par[i] = i;
			T[i] = -1;
			g[i].clear();
		}
	}

	void uni(int a, int b, int t){
		a = find(a); b = find(b); if(a == b)return;

		++tot;
		T[tot] = t;
		g[tot].emplace_back(a);
		g[tot].emplace_back(b);
		par[a] = par[b] = tot;
		par[tot] = tot;
	}

	void dfs(int u){
		for(int &v:g[u]){
			up[0][v] = u;
			h[v] = h[u] + 1;
			dfs(v);
		}
	}
	
	void pre(){
		f0(i, 1, tot){
			if(find(i) == i){
				h[i] = 0;
				up[0][i] = i;
				dfs(i);
			}
		}

		f0(j, 1, lg-1){
			f0(i, 1, tot){
				up[j][i] = up[j-1][up[j-1][i]];
			}
		}
	}

	int lca(int u, int v){
		if(h[u]!=h[v]){
			if(h[u] < h[v])swap(u, v);

			int k = h[u] - h[v];

			for(int j = 0; (1<<j)<=k; j++){
				if(k&(1<<j))u = up[j][u];
			}
		}

		if(u == v)return u;

		int k = lg2(h[u]);
		fd(j, k, 0){
			if(up[j][u] != up[j][v]){
				u = up[j][u];
				v = up[j][v];
			}
		}

		return up[0][u];
	}
} krst;

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>m;
	
	vector<truyvan> q(m+1);

	f0(i, 1, m){
		cin>>q[i].t>>q[i].u>>q[i].v;
	}

	krst.init(n);
	f0(i, 1, m){
		if(q[i].t == 1){
			krst.uni(q[i].u, q[i].v, i);
		}
	}

	krst.pre();

	f0(i, 1, m){
		if(q[i].t == 2){
			int u = q[i].u;
			int v = q[i].v;

			if(krst.find(u) != krst.find(v)){
				cout<<-1<<'\n';
			}else{
				cout<<krst.T[krst.lca(u, v)]<<'\n';
			}
		}
	}
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
