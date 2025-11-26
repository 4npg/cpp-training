// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define maxn 200005

int n,q;

int64 a[maxn];

void build(int id, int l, int r){
	if(l==r){
		t[id] = a[l];
		return; 
	}
	int mid = l + (r-l)/2;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);
	t[id] = t[id*2] + t[id*2 + 1]; 
}

int get(int id, int l, int r, int u, int v){
	if(l==r){
		td[id] = a[l];
	}
}
void update(int id, int l, int r, int i, int x){
	if(l==r){
		t[id] = x;
		return;
	}
	int mid = l + (r-l)/2;
	if(i<=mid)update(id*2, l, mid, i, x);
	else update(id*2, mid+1, r, i, x);
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
		

	cerr << "time elapsed: "<<TIME <<"s.\n";
}





