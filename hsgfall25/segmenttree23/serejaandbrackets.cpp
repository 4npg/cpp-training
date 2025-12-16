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



string s;
int m;

struct node{
	int open, close, match;
	node(int o=0, int c=0, int m=0):open(o), close(c), match(m){};
} t[maxn*4];

node merge(const node &a, const node &b){
	int k = min(a.open, b.close);
	return node(
		a.open + b.open - k,
		a.close + b.close -k,
		a.match + b.match +k
		);
}

void build(int id, int l, int r){
	if(l == r){
		if(s[l-1] == '(')t[id] = node(1, 0, 0);
		else t[id] = node(0, 1, 0);
		return;
	}
	int mid = (l+r)/2;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);

	t[id] = merge(t[id*2], t[id*2+1]);
}

node get(int id, int l, int r, int u, int v){
	if(u<=l && r<=v)return t[id];

	int mid = (l+r)/2;

	if(v<=mid)return get(id*2, l, mid, u, v);
	if(u>mid)return get(id*2+1, mid+1, r, u, v);

	return merge(
		get(id*2, l, mid, u, v),
		get(id*2+1, mid+1, r, u, v)
	);
}

i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>s>>m;	
	int n = s.size();
	build(1, 1, n);


	while(m--){
		int l, r;cin>>l>>r;
		node res = get(1, 1, n, l, r);
		cout<<res.match*2<<'\n';
	}
	cerr << "time elapsed: "<<TIME <<"s.\n";
}





