// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file ""

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 200005
#define lg 18
#define inf (int64)4e18
#define pb push_back
#define fi first 
#define se second 

int n;
int a[maxn];
int64 sum;

int gcd(int a, int b){
	if(b == 0)return a;
	return gcd(b, a%b);
}

int t[lg][maxn];

int lg2(int n){
	return n ? 31 - __builtin_clz(n) : -1;
}

void init(){
	f0(i, 0, n-1)t[0][i] = a[i];

	f0(j, 1, lg){
		for(int i = 0; i + (1<<j) <=n; i++){
			t[j][i] = gcd(t[j-1][i], t[j-1][i + (1<<(j-1))]);
		}
	}
}
	
int get(int l, int r){
	int k = lg2(r-l+1);
	return gcd(t[k][l], t[k][r-(1<<k)+1]);
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n;
	f0(i, 0, n-1)cin>>a[i];

	init();

	f0(r, 0, n-1){
		int l = r;
		while(l >= 0){
			int g = get(l, r);

			int lo = 0, hi = l, res = l;
			while(lo <= hi){
				int mid = (lo+hi)/2;
				if(get(mid, r) == g){
					res = mid;
					hi = mid - 1;
				}else lo =  mid + 1;
			}
			sum += 1ll * g * (l - res + 1);
			l = res - 1;
		}
	}

	cout<<sum;
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
