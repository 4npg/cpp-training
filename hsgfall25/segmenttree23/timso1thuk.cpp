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

#define maxn 1000006

int n, m;
int a[maxn], t[maxn*4];

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

void update(int id, int l, int r, int p){
	if(l == r){
		a[l] ^= 1;
		t[id] = a[l];
		return;
	}

	int mid = (l+r)/2;
	if(p<=mid)update(id*2, l, mid, p);
	else update(id*2+1, mid+1, r, p);

	t[id] = t[id*2] + t[id*2+1];
}

int get(int id, int l, int r, int k){
	if(l == r)return l;

	int mid = (l+r)/2;
	int cnt = t[id*2];
	if(k<=cnt)return get(id*2, l, mid, k);
	else return get(id*2+1, mid+1, r, k-cnt);
}

i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	f0(i, 1, n)cin>>a[i];

	build(1, 1, n);

	while(m--){
		int type, i;
		cin>>type>>i;
		if(type == 1)update(1, 1, n, i);
		else cout<<get(1, 1, n, i)<<'\n';
	}
	cerr << "time elapsed: "<<TIME <<"s.\n";
}





