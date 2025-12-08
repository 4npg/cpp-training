// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 1001
#define pb push_back

struct canh{
	int u, v;
	int w;
};

int n, m;
int parent[maxn], sz[maxn];
vector<canh> a;

void make(){
	f0(i, 1, n){
		parent[i] = i;
		sz[i] = 1;
	}
}

int find(int v){
	if(v = parent[v])return v;
	return parent[v] = find(parent[v]);
}

bool Union(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b)return false;
	if(sz[a] < sz[b])swap(a, b);
	parent[b] = a;
	sz[a] += sz[b];
	return true;
}

bool cmp(canh a, canh b){
	return a.w < b.w;
}

void print(){
	f0(i, 0, m-1){
		cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<'\n';
	}
}

void kruskal(){
	// Tao cay khung cuc tieu rong
	vector<canh> mst;
	int d = 0;
	// Sort ds canh theo chieu dai tang dan
	sort(a.begin(), a.end(), cmp);
	// Lap

	print();

	f0(i, 0, m-1){
		if(mst.size() == n-1)break;
		canh e = a[i]; // chon canh e la canh nho nhat
		if(Union(e.u, e.v)){
			mst.pb(e);
			d += e.w;
		}
	}
	if(mst.size() != n-1){
		cout<<"Do thi khong lien thong!\n";
	}else{
		cout<<"MST :"<<d<<'\n';
		for(auto it:mst){
			cout<<it.u<<" "<<it.v<<" "<<it.w<<'\n';
		}
	}
	//cout<<d;
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	f0(i, 0, m-1){
		int x, y, w;
		cin>>x>>y>>w;
		a.pb({x, y, w});
	}
	make();
	kruskal();
	cerr << "time elapsed: "<<TIME <<"s.\n";
}

