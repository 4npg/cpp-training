// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file "bai2"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)

string s;
long long ans = 0;

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>s;
	if(isdigit(s[s.size()-1]))s = s + 'a';

	long long tmp = 0;
	for(char &c:s){
		if(isdigit(c)){
			tmp = tmp * 10 + c-'0';
		}else{
			ans += tmp;
			tmp = 0;
		}
	}

	cout<<ans;
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
