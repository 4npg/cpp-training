// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 100005
#define pb push_back
#define fi first 
#define se second 

struct edge{
	int u, v;
	int w;
	int type;

	friend bool operator < (const edge &a, const edge &b){
		if(a.type != b.type)return a.type < b.type;
		return a.w < b.w;
	}
};

int n, m, d, r;
int par[maxn], sz[maxn];
vector<edge> e;


void build(){	
	f0(i, 1, n){
		par[i] = i;
		sz[i] = 1;
	}
}

int find(int v){
	return ((v == par[v] ? v : par[v] = find(par[v])));
}

bool uni(int a, int b){
	a = find(a);
	b = find(b);

	if(a == b)return false;
	if(sz[a] < sz[b])swap(a, b);
	par[b] = a;
	sz[a] += sz[b];
	return true;
}

void kruskal(){
	sort(e.begin(), e.end());
	int64 ans = 0;
	for(auto &p:e){
		if(uni(p.u, p.v)){
			if(p.type>0)ans+=p.w;
		}
	}

	cout<<ans;
}
i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>m>>d>>r;
	vector<int> u(m+1), v(m+1), c(m+1);

	f0(i, 1, m)cin>>u[i]>>v[i]>>c[i];

	vector<int> state(m+1, 0);

	f0(i, 1, d){
		int x; cin>>x;
		state[x] = 1;
	}

	f0(i, 1, r){
		int x; cin>>x;
		state[x] = 2;
	}

	f0(i, 1, m){
		edge ep;
		ep.u = u[i];
		ep.v = v[i];
		ep.w = c[i];
		ep.type  = state[i];
		e.pb(ep);
	}

	build();

	kruskal();

	cerr << "time elapsed: "<<TIME <<"s.\n";
}
