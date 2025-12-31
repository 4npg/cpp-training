// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file "threesum"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 100005
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)
#define pb push_back
#define fi first 
#define se second 

int n;
int64 x;
int64 a[maxn];
vector<pair<int64, int>>b;
int64 cnt = 0;

void sub1(){
	f0(i, 0, n-1){
		f0(j, i+1, n-1){
			f0(k, j+1, n-1){
				if(a[i] + a[j] + a[k] == x){
					cnt++;
					cout<<i+1<<" "<<j+1<<" "<<k+1<<'\n';
				}
			}
		}
	}

	cout<<cnt;
}

bool cmp(pair<int, int> a, pair<int, int> b){
	return a.fi < b.fi;
}
con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>x;
	f0(i, 0, n-1)cin>>a[i];
	f0(i, 0, n-1)b.pb({a[i], i+1});

	sort(b.begin(), b.end(), cmp);

	f0(i, 0, n-4){
		int l = i+1;
		int r = n-1;

		while(l < r){
			int64 s = b[i].fi + b[l].fi + b[r].fi;

			if(s == x){
				cout<<b[i].se<<" "<<b[l].se<<" "<<b[r].se;
				return 0;
			}
			if(s<x){
				l++;
			}else r--;
		}
	}

	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
