// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define maxn 200005


int n,q;
int64 a[maxn], t[maxn*4];

void build(int id, int l, int r){	
	if(l == r){
		t[id] = a[l];
		return;
	}

	int mid = (l+r)/2;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);
	t[id] = t[id*2] + t[id*2+1];
}

int64 get(int id, int l, int r, int u, int v){
	if(r<u || v<l)return 0;
	if(l<=u && v<=r)return t[id];

	int mid = (l+r)/2;
	int64 tl = get(id*2, l, mid, u, v);
	int64 tr = get(id*2+1, r, mid+1, u, v);
	return tl + tr;
}

void update(int id, int l, int r, int p, int x){
	if(l==r){
		t[id] = x;
		return;
	}
	int mid = (l+r)/2;
	update(id*2, l, mid, p, x);
	update(id*2+1, mid+1, r, p, x);
	t[id] = t[id*2] + t[id*2+1];
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>q;
	f0(i, 0, n-1)cin>>a[i];

	build(1, 1, n);

	while(q--){
		int t, u, v;
		cin>>t>>u>>v;
		if(t==1)update(1, 1, n, u, v);
		else cout<<get(1, 1, n, u, v)<<'\n';
	}

	cerr << "time elapsed: "<<TIME <<"s.\n";
}





