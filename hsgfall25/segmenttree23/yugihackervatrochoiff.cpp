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

#define maxn 100005
#define all(a) (a).begin(), (a).end()
#define inf (int64)-1

int n, q;
int64 a[maxn];

struct node{
	int64 ma1, ma2;
} t[maxn*4];

node merge(node a, node b){
	vector<int64> v = {a.ma1, a.ma2, b.ma1, b.ma2};

	sort(all(v), greater<int64>());

	return {v[0], v[1]};
}

void build(int id, int l, int r){
	if(l == r){
		t[id] = {a[l], inf};
		return;
	}

	int mid = (l+r)/2;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);

	t[id] = merge(t[id*2], t[id*2+1]);
}

int64 mul(int64 a, int64 b, int64 mod){
	int64 ans = 0;
	while(b){
		if(b&1)ans = (ans + a)%mod;
		a = (a+a)%mod;
		b>>=1;
	}
	return ans;
}

void update(int id, int l, int r, int p, int64 x){
	if(l == r){
		t[id] = {x, inf};
		return;
	}

	int mid = (l+r)/2;
	if(p<=mid)update(id*2, l, mid, p, x);
	else update(id*2+1, mid+1, r, p , x);

	t[id] = merge(t[id*2], t[id*2+1]);
}

node get(int id, int l, int r, int u, int v){
	if(v<l || r<u){
		return {inf, inf};
	}
	if(u<=l && r<=v){
		return t[id];
	}

	int mid = (l+r)/2;
	node tl = get(id*2, l, mid, u, v);
	node tr = get(id*2+1, mid+1, r, u, v);

	return merge(tl, tr);
}

i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n;
	f0(i, 1, n)cin>>a[i];
	build(1, 1, n);

	cin>>q;
	while(q--){
		int type; cin>>type;

		if(type == 0){
			int p; int64 x;
			cin>>p>>x;
			update(1, 1, n, p, x);
		}else{
			int l, r; int64 mod;
			cin>>l>>r>>mod;

			node res = get(1, 1, n, l, r);

			if(res.ma2<1){
				if(res.ma1<1){
					cout<<0<<'\n';
				}else cout<<res.ma1%mod<<'\n';
			}else{
				cout<<mul(res.ma1, res.ma2, mod)<<'\n';
			}
		}
	}
	cerr << "time elapsed: "<<TIME <<"s.\n";
}





