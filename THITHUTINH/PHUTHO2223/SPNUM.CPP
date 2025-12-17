// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 1000006

bool d[maxn];
int n, k;
int cnt;

void sang(){
	d[0] = d[1] = 1;

	for(int i=2; i*i<maxn; i++){
		if(d[i] == 0){
			for(int j=i*i; j<maxn; j+=i)d[j] = 1;
		}
	}
}

i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>k;
	
	sang();

	f0(i, 2, n){
		if(!d[i] && __builtin_popcount(i) == k){
			cnt++;
			//cout<<i<<'\n';
		}
	}

	cout<<cnt;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}




