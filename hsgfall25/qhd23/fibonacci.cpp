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

#define maxn 93
#define u64 unsigned long long 
int t;
u64 fi[maxn];

i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	
	fi[0] = fi[1] = 1;
	f0(i, 2, maxn)fi[i] = fi[i-1] + fi[i-2];

	cin>>t;
	while(t--){
		int n; cin>>n;
		cout<<fi[n]<<'\n';
	}

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


	


