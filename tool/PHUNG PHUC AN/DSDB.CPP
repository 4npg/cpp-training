// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file "DSDB"

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int Rand(int l, int r){
	return l+rng()%(r-l+1);
}

#define maxn 1003
#define all(a) (a).begin(),(a).end()

int n;
int a[maxn];
int b[maxn];
int f[maxn][maxn];

youngboiz_nobug(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);

	cin>>n;
	f0(i, 1, n)cin>>a[i];
	
	f0(i, 1, n)b[i] = a[n-i+1];

	f[0][0] = 0;

	f0(i, 1, n){
		f0(j, 1, n){
			if(a[i] == b[j]){
				f[i][j] = f[i-1][j-1] + 1;
			}else{
				f[i][j] = max(f[i][j-1], f[i-1][j]);
			}
		}
	}

	cout<<n - f[n][n];
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
