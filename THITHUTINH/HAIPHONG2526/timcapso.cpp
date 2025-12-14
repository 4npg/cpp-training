// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 1000006

int n, m;
int64 s;
int64 a[maxn];

i_love_Hoang_Ngan(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>m>>n>>s;
	f0(i, 0, n+m)cin>>a[i];
	sort(a, a+n+m);

	int l = 0, r = n+m-1;
	int64 ans = -1;
	while(l<r){
		if(a[l] + a[r] > s){
			r--;
		}else{
			ans = max(ans, a[l] + a[r]);
			l++;
		}
	}

	cout<<ans;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


