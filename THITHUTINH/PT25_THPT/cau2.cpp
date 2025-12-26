// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file "cau2"

// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 1000006

int n; 
int64 a[maxn];
int64 cntfi[10];

int64 ans;

int gcd(int a, int b){
	if(b == 0)return a;
	return gcd(b, a%b);
}

int fi(int64 x){
	while(x>=10)x/=10;
	return x;
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n;

	f0(i, 0, n-1){
		cin>>a[i];
		f0(d, 1, 9){
			if(gcd(d, a[i]%10) == 1){
				ans += cntfi[d];
			}
		}
		cntfi[fi(a[i])]++;
	}

	cout<<ans;

	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
