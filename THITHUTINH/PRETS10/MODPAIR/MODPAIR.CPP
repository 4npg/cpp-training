// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 1000006
#define fi first 
#define se second 

int n, m;
int64 cnt;

i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
		
	cin>>n>>m;
	map<int64, int> mp;
	f0(i, 0, n-1){
		int64 x; cin>>x;
		mp[x%m]++;
	}

	for(auto &x:mp){
		if(x.se>=2)cnt += (x.se*(x.se-1))/2;
	}

	cout<<cnt;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}





