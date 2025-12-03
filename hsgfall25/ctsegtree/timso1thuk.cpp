// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define maxn 1000006

int n, m;
int a[maxn], t[maxn*4], lazy[maxn*4];

void build(int id, int l, int r){
	if(l == r){
		t[id] = a[l];
		return ;
	}

	int mid = (l+r)/2;
	build(id*2, l, mid);
	build(id*2, mid+1, r);
	t[id] = 
}


void push(int id){
	lazy[id*2] += lazy[id];
	t[id*2] += lazy[id];

	lazy[id*2+1] += lazy[id];
	t[id*2+1] += lazy[id];

	lazy[id] = 0;
}


void update(int id, int l, int r, int p, int x){
	if(l == r){
		t[id] = x;
		return ;
	}

	int mid = (l+r)/2;
	push(id);

	if(p<=mid)update(id*2, l, mid, p, x);
	else update(id*2+1, mid+1, r, p, x);

	t[id] = 
}

int64 get(int id, int l, int r, int k, int x){
	
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	f0(i, 1, n)cin>>a[i];

	build(1, 1, n);	

	while(q--){
		int type;
		cin>>type;
		if(type == 1){
			int i;
			int x = ((t[i]==1)?0:1);
			update(1, 1, n, i, x);
		}else cout<<get(1, 1, n, k, 1);
	}
	cerr << "time elapsed: "<<TIME <<"s.\n";
}





