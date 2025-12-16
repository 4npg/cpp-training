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

#define maxn 200005

int n, q;
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

void update(int id, int l, int r, int p, int64 x){
	if(l == r){
		t[id] = x;
		return;
	}

	int mid = (l+r)/2;
	if(p<=mid)update(id*2, l, mid, p, x);
	else update(id*2+1, mid+1, r, p, x);
	t[id] = t[id*2] + t[id*2+1];
}

int64 get(int id, int l, int r, int u, int v){
	if(v<l || r<u)return 0;
	if(u<=l && r<=v){
		return t[id];
	}

	int mid = (l+r)/2;
	int64 tl = get(id*2, l, mid, u, v);
	int64 tr = get(id*2+1, mid+1, r, u, v);
	return tl + tr;
}

i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>q;

	f0(i, 1, n)cin>>a[i];
	build(1, 1, n);
	while(q--){
		int ty; cin>>ty;
		if(ty == 1){
			int p; int64 x;
			cin>>p>>x;
			update(1, 1, n, p, x);
		}else{
			int l, r; cin>>l>>r;
			cout<<get(1, 1, n, l, r)<<'\n';
		}
	}
	cerr << "time elapsed: "<<TIME <<"s.\n";
}





