// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file ""

// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 1000006

int64 s;
int n, m;
int a[maxn];
int ans = -1;

i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>m>>s;
	f0(i, 0, n*m-1)cin>>a[i];

	sort(a, a+(n*m));


	int l = 0, r = n*m-1;

	while(l<r){
		if(a[l] + a[r] > s){
			r--;
		}else{
			ans = max(ans, a[l] + a[r]);
			l++;
		}

	}
	cout<<ans;
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
