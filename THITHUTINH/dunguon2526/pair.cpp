// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file "pair"

// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 200005
#define mod (int64)(1e9+7)
#define lg 17
#define inf (int64)4e18
#define pb push_back 
#define fi first 
#define se second 
#define all(a) (a).begin(), (a).end()
#define pli pair<int64, int>


int64 a[maxn];

struct node{
	int64 mi1, mi2;
	int cnt1, cnt2;
} t[maxn*4];

inline void add(node &res, int64 x, int c){
    if (c == 0) return;

    if (x < res.mi1){
        res.mi2 = res.mi1;
        res.cnt2 = res.cnt1;
        res.mi1 = x;
        res.cnt1 = c;
    }
    else if (x == res.mi1){
        res.cnt1 += c;
    }
    else if (x < res.mi2){
        res.mi2 = x;
        res.cnt2 = c;
    }
    else if (x == res.mi2){
        res.cnt2 += c;
    }
}


node merge(node l, node r){

    if(l.cnt1 == 0)return r;
    if(r.cnt1 == 0)return l;

    node res;
    res.mi1 = res.mi2 = inf;
    res.cnt1 = res.cnt2 = 0;

    add(res, l.mi1, l.cnt1);
    add(res, l.mi2, l.cnt2);
    add(res, r.mi1, r.cnt1);
    add(res, r.mi2, r.cnt2);

    return res;
}

void build(int id, int l, int r){
	if(l == r){
		t[id] = {a[l], inf, 1, 0};
		return;
	}

	int mid = (l+r)/2;

	build(id*2, l, mid);
	build(id*2+1, mid+1, r);

	t[id] = merge(t[id*2], t[id*2+1]);
}

void update(int id, int l, int r, int p, int64 x){
	if(l == r){
		t[id] = {x, inf, 1, 0};
		return;
	}

	int mid = (l+r)/2;

	if(p<=mid)update(id*2, l, mid, p, x);
	else update(id*2+1, mid+1, r, p, x);

	t[id] = merge(t[id*2], t[id*2+1]);
}

node get(int id, int l, int r, int u, int v){
	if(v<l || r<u)return {inf, inf, 0, 0};
	if(u<=l && r<=v)return t[id];

	int mid = (l+r)/2;
	node tl = get(id*2, l, mid, u, v);
	node tr = get(id*2+1, mid+1, r, u, v);

	return merge(tl, tr);
}

int T;
con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	
	cin>>T;
	while(T--){
		int n, q;
		cin>>n>>q;
		f0(i, 1, n)cin>>a[i];

		build(1, 1, n);

		int64 ans = 0;

		while(q--){
			int type; cin>>type;
			if(type == 1){
				int p; int64 x; 
				cin>>p>>x;
				update(1, 1, n, p, x);
			}else{
				int l, r; cin>>l>>r;
				node res = get(1, 1, n, l, r);

				int64 w; 
				if(res.cnt1 >= 2){
					w = 1ll * res.cnt1 * (res.cnt1-1)/2;
				}else{
					w = 1ll * res.cnt1 * res.cnt2;
				}

				ans = (ans + w)%mod;

			}
		}

		cout<<ans<<'\n';

	}
	
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
