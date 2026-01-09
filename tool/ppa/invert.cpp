// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file "invert"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//long long Rand(long long l, long long r){
//	return l+rng()%(r-l+1);
//}

#define maxn 1005
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int n, q;
int a[maxn];

int iv(int l, int r){
	int cnt = 0;
	f0(i, l, r-1){
		f0(j, i+1, r){
			if(a[i] > a[j]){
				cnt++;
				cout<<i<<" "<<j<<'\n';
			}
		}
	}

	return cnt;
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);

	cin>>n>>q;
	f0(i, 1, n)cin>>a[i];

	while(q--){
		int l, r; cin>>l>>r;
		cout<<iv(l, r)<<'\n';
	}
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
