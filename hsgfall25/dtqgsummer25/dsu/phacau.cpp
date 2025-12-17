// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// void Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 200005
#define pb push_back

int n, m;

struct edge{
	int u, v;
};

vector<edge> a;
int par[maxn], sz[maxn];

void make(int x){
	par[x] = x;
	sz[x] = 1;
}

int find(int v){
	return ((v==par[v])?v:par[v]=find(par[v]));
}

bool uni(int a, int b, int64 &edgecase){
	a = find(a); b = find(b);
	if(a==b)return false;

	edgecase -= (int64)sz[a] *sz[b];
	
	if(sz[a] < sz[b])swap(a, b);
	par[b] = a;
	sz[a] += sz[b];
	return true;
}


i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>m;

	f0(i, 0, m-1){
		edge e;
		cin>>e.u>>e.v;
		a.pb(e);
	}

	f0(i, 1, n)make(i);

	vector<int64> ans(m+2);
	int64 edgecase = (int64)n*(n-1)/2;

	fd(i, m, 1){
		ans[i] = edgecase;
		uni(a[i-1].u, a[i-1].v, edgecase);
	}

	f0(i, 1, m)cout<<ans[i]<<'\n';
	cerr << "time elapsed: "<<TIME <<"s.\n";
}





