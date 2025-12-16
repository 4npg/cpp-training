// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// void Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 100005
#define pb push_back
#define all(a) (a).begin(), (a).end()

struct edge{
	int u, v;
	int t;
};

int n, m;
int par[maxn], sz[maxn];
vector<edge> a;

void make(int x){
	par[x] = x;
	sz[x] = 1;
}


int find(int v){
	return ((v==par[v])?v:par[v] = find(par[v]));
}

bool cmp(const edge &a, const edge &b){
	return a.t < b.t;
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

	sort(a.begin(), a.end(), cmp);

	int ans = 0, cnt = 0;
	for(const auto &e:a){
		if(uni(e.u, e.v)){
			ans = max(ans, e.t);
			cnt++;
			if(cnt==n-1)break;
		}
	}
	cout<<ans;
}

i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
		
	cin>>n>>m;

	f0(i, 1, n)make(i);

	f0(i, 0, m-1){
		edge e;
		cin>>e.u>>e.v>>e.t;
		a.pb(e);
	}
	kruskal();
	cerr << "time elapsed: "<<TIME <<"s.\n";
}





