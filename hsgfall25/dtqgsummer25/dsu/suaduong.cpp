// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 200005
#define fi first
#define se second 
#define pb push_back
int n, m;


struct edge{
	int u, v;
	int64 w;
};

vector< edge > a;
int par[maxn], sz[maxn];

void make(int v){
	par[v] = v;
	sz[v] = 1;
}

int find(int v){
	return ((v==par[v])?v:par[v] = find(par[v]));
}

bool uni(int a, int b){
	a = find(a);
	b = find(b);

	if(a==b)return false;
	if(sz[a] < sz[b])swap(a, b);
	par[b] = a;
	sz[a] += sz[b];
	return true;
}

bool cmp(edge a, edge b){
	return a.w < b.w;
}

void kruskal(){
	vector<edge> mst;

	int64 d = 0;
	sort(a.begin(), a.end(), cmp);

	f0(i, 0, m-1){
		if(mst.size() == n-1)break;
		edge e = a[i];
		if(uni(e.u, e.v)){
			mst.pb(e);
			d += e.w;
		}
	}

	if(mst.size() != n-1){
	    cout << "IMPOSSIBLE";
	    return;
	}
	cout << d;


}

i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>m;
	f0(i, 0, m-1){
		int u, v;
		int64 w;
		cin>>u>>v>>w;
		a.pb({u, v, w});
	}

	f0(i, 1, n)make(i);

	kruskal();

	cerr << "time elapsed: "<<TIME <<"s.\n";
}




