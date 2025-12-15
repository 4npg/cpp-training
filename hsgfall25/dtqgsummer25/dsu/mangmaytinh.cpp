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
#define pb push_back
#define fi first 
#define se second 

int par[maxn], sz[maxn];
int q;

void make(int v){
	par[v] = v;
	sz[v] = 1;
}

int find(int v){
	return ((v==par[v])?v:par[v] = find(par[v]));
}

void uni(int a, int b){
	a = find(a);
	b = find(b);

	if(a!=b){
		if(sz[a] < sz[b])swap(a, b);
		par[b] = a;
		sz[a] += sz[b];
	}
}

i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	f0(i, 1, 10000)make(i);

	cin>>q;
	while(q--){
		int type, u, v;
		cin>>u>>v>>type;
		if(type==1){
			uni(u, v);
		}else{
			if(find(u) == find(v)){
				cout<<1<<'\n';
			}else cout<<0<<'\n';
		}
	}

	cerr << "time elapsed: "<<TIME <<"s.\n";
}




