// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b);++i)
#define fd(i,a,b) for(int i = (a); i >= (b);--i)
#define file "cau2"

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 1000006
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

string s;
int cnt = 0;
int res = 0;
char ans;
	
con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>s;

	for(auto &c:s){
		c = tolower(c);
	}


	f0(i, 0, (int)s.size()-1){
		if(s[i] != s[i+1]){
			if(res < cnt+1){
				res = cnt + 1;
				ans = toupper(s[i]);
			}
			cnt = 0;
		}else cnt++;
	}

	cout<<ans<<" "<<res;
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
