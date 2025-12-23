// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file ""

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 100005
#define pb push_back

int n, q;
vector<int> bit1, bit2;

void updatediem(vector<int> &b, int u, int v){
	int idx = u;
	while(idx <= n){
		b[idx] += v;
		idx += (idx & (-idx));
	}
}

void updatedoan(int l, int r, int v){
	updatediem(bit1, l, (n-l+1) * v);
	updatediem(bit1, r+1, -(n-r) * v);
	updatediem(bit2, l, v);
	updatediem(bit2, r+1, -v);
}

int get(vector<int> &b, int u){
	int idx = u, ans = 0;
	while(idx){
		ans += b[idx];
		idx -= (idx & (-idx));
	}
	return ans;
}

int pre(int u){
	return get(bit1, u) - get(bit2, u) * (n-u);
}

int getpre(int l, int r){
	return pre(r) - pre(l-1);
}
youngboiz_nobug(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>q;
	f0(i, 1, n){
		int x; cin>>x;
		updatedoan(i, i, x);
	}

	while(q--){
		int type, u, v;
		cin>>type>>u>>v;
		if(type == 1){
			int x; cin>>x;
			updatedoan(u, v, x);
		}else cout<<getpre(u, v)<<'\n';
	}
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
