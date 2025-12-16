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

struct node{
	int64 sum, pre, suf, ans;
} t[maxn*4];

int n, m;
int64 a[maxn];
	
node make(int64 x){
	node m;
	m.sum = x;
	int64 v = max(1ll*0, x);
	m.ans = m.pre = m.suf = v;

	return m;
}

node merge(const node &a, const node &b){
	node m;
	m.sum = a.sum + b.sum;
	m.pre = max(a.pre, a.sum + b.pre);
	m.suf = max(b.suf, b.sum + a.suf);
	m.ans = max({a.ans, b.ans, a.suf + b.pre});

	return m;
}

void build(int id, int l, int r){
	if(l == r){
		t[id] = make(a[l]);
		return;
	}

	int mid = (l+r)/2;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);

	t[id] = merge(t[id*2], t[id*2+1]);
}

void update(int id, int l, int r, int p, int64 x){
	if(l == r){
		t[id] = make(x);
		return;
	}

	int mid = (l+r)/2;
	if(p<=mid)update(id*2, l, mid, p, x);
	else update(id*2+1, mid+1, r, p, x);

	t[id] = merge(t[id*2], t[id*2+1]);
}
i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	f0(i, 1, n)cin>>a[i];

	build(1, 1, n);

	while(m--){
		int k; int64 x;
		cin>>k>>x;
		update(1, 1, n, k, x);
		cout<<t[1].ans<<'\n';
	}
	cerr << "time elapsed: "<<TIME <<"s.\n";
}





