// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 200005
#define pb push_back 
#define fi first 
#define se second

int parent[maxn], rk[maxn], sum[maxn];

void make_set(int v){
	parent[v] = v;
	rk[v] = 0;
	sum[v] = v;
}

int find_set(int v){
	if(v == parent[v]) return v;
	int p = find_set(parent[v]);
	parent[v] = p;
	return p;
}

int find_sum(int v){
	v = find_set(v);
	return sum[v];
}

// int find_set(int v){
// 	return v == parent[v] ? v : parent[v] = find_set(parent[v]);
// }

void union_sets(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a!=b){
		if(rk[a] < rk[b])swap(a, b);
		parent[b] = a;
		if(rk[a] == rk[b]) rk[a]++;
		sum[a] += sum[b];
	}
}

bool vis[maxn];
vector<int> g[maxn];
int n, q;


// toi uu bo sz[], parent[]
// int lab[maxn];
// void make_set(int v){
// 	lab[v] = -1;
// }

// int find_set(int v){
// 	return lab[v] < 0 ? v : lab[v] = find_set(lab[v]);
// }

// void union_sets(int a, int b){
// 	a = find_set(a);
// 	b = find_set(b);

// 	if(a!=b){
// 		if(lab[a] > lab[b])swap(a, b);
// 		lab[a] += lab[b];
// 		lab[b] = a;
// 	}
// }





int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>q;
	f0(i, 1, n){
		make_set(i);
	}

	while(q--){
		int type;
		cin>>type;
		if(type == 1){
			int u, v;
			cin>>u>>v;
			union_sets(u, v);
		}else{
			int u; cin>>u;
			cout<<find_sum(u)<<'\n';
		}
	}


	cerr << "time elapsed: "<<TIME <<"s.\n";
}


