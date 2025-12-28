// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b);++i)
#define fd(i,a,b) for(int i = (a); i >= (b);--i)
#define file ""

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 200005
#define lg 20
#define inf (int64)4e18

struct node{
	int64 dp[2][2];
	int64 ld, rd;
};

int n, q;
int64 a[maxn], d[maxn];
node t[maxn*4];

node merge(const node &a, const node &b){
	node c;
	c.ld = a.ld;
	c.rd = b.rd;

	f0(i, 0, 1){
		f0(j, 0, 1){
			c.dp[i][j] = -inf;
		}
	}

	f0(al, 0, 1){
		f0(ar, 0, 1){
			f0(bl, 0, 1){
				f0(br, 0, 1){
					if(a.dp[al][ar] == -inf || b.dp[bl][br] == -inf)
						continue;

					if(ar == 1 && bl == 1 && a.rd * b.ld < 0)
						continue;

					int nl = al;
					int nr = br;

					c.dp[nl][nr] = max(
						c.dp[nl][nr],
						a.dp[al][ar] + b.dp[bl][br]
					);
				}
			}
		}
	}
	return c;
}

node apply(int64 x){
	node res;
	res.ld = res.rd = x;

	f0(i, 0, 1){
		f0(j, 0, 1){
			res.dp[i][j] = 0;
		}
	}

	int64 v = llabs(x);
	res.dp[0][0] = 0;
	res.dp[1][1] = v;

	return res;
}

void build(int id, int l, int r){
	if(l == r){
		t[id] = apply(d[l]);
		return;
	}

	int mid = (l+r)/2;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);

	t[id] = merge(t[id*2], t[id*2+1]);
}

void update(int id, int l, int r, int p){
	if(l == r){
		t[id] = apply(d[l]);
		return;
	}

	int mid = (l + r)/2;
	if(p<=mid)update(id*2, l, mid, p);
	else update(id*2+1, mid+1, r, p);

	t[id] = merge(t[id*2], t[id*2+1]);

}
con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>q;
	f0(i, 1, n)cin>>a[i];

	f0(i, 1, n-1){
		d[i] = a[i+1] - a[i];
	}

	build(1, 1, n-1);

	while(q--){
		int l, r; int64 x;
		cin>>l>>r>>x;

		if(l>1){
			d[l-1] += x;
			update(1, 1, n-1, l-1);
		}

		if(r<n){
			d[r] -= x;
			update(1, 1, n-1, r);
		}

		if(n == 1){
			cout<<0<<'\n';
		}else {
			int64 ans = 0;
			f0(i, 0, 1){
				f0(j, 0, 1){
					ans = max(ans, t[1].dp[i][j]);
				}
			}
			cout<<ans<<'\n';
		}
	}
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
