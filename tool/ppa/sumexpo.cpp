// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file "sumexpo"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//long long Rand(long long l, long long r){
//	return l+rng()%(r-l+1);
//}

#define maxn 1000006
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int d[maxn];
long long n;
long long sle = 0, schan = 0;

void sang(){
	for(int i=2; i<maxn; i++){
		if(!d[i]){
			for(int j=i; j<maxn; j+=i){
				if(!d[j])d[j] = i;
			}
		}
	}
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);

	sang();

	cin>>n;

	while(n>1){
		int p = d[n];
		int cnt = 0;
		while(n%p == 0){
			n/=p;
			cnt++;
		}
		if(cnt&1)sle += cnt;
		else schan += cnt;
	}

	if(n>1)if(n&1)sle++;
	else schan++;
	
	cout<<schan<<'\n'<<sle;

	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
