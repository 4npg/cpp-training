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

int n;
int cnt;
bool d[maxn];

void sang(){
	d[0] = d[1] = 1;

	for(int i=2; i*i<maxn; i++){
		if(d[i] == 0){
			for(int j=i*i; j<maxn; j+=i)d[j] = 1;
		}
	}
}

int tcs(int x){
	int res = 0;
	while(x){
		res += x%10;
		x/=10;
	}
	return res;
}

i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	sang();

	cin>>n;

	f0(i, 1, n){
		int x; cin>>x;
		if(!d[x] && !d[tcs(x)])cnt++;
	}

	cout<<cnt;
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
