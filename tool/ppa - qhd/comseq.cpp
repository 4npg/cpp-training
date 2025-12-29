// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file "comseq"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 1005
#define pb push_back
#define all(a) (a).begin(), (a).end()

int m, n;
int a[maxn];
int b[maxn];
int dp[maxn][maxn];
vector<int> c;
vector<int> ida;
vector<int> idb;


youngboiz_nobug(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	 freopen(file".inp", "r", stdin);
	 freopen(file".out", "w", stdout);

	cin>>m>>n;

	f0(i, 1, m)cin>>a[i];
	f0(i, 1, n)cin>>b[i];

	f0(i, 0, m)dp[i][0] = 0;
	f0(j, 0, n)dp[0][j] = 0;

	f0(i, 1, m){
		f0(j, 1, n){
			if(a[i] == b[j]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	cout<<dp[m][n];

	int i = m, j = n;
	while(i > 0 && j > 0){
		if(a[i] == b[j]){
			c.pb(a[i]);
			ida.pb(i);
			idb.pb(j);
			i--; j--;
		}else if(dp[i-1][j] >= dp[i][j-1])i--;
		else j--;
	}

	reverse(all(c));
	reverse(all(ida));
	reverse(all(idb));

	cout<<c.size()<<'\n';
	for(auto &x:c)cout<<x<<" "; cout<<'\n';
	for(auto &x:ida)cout<<x<<" "; cout<<'\n';
	for(auto &x:idb)cout<<x<<" "; cout<<'\n';

	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
