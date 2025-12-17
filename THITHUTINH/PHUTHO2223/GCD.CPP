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

int n;
int d[maxn];
int cnt[maxn];

i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n;
	f0(i, 1, n){
		int x; cin>>x;
		cnt[x]++;
	}

	fd(i, maxn, 1){
		int total = 0;
		for(int j = i; j<=maxn; j+=i){
			total += cnt[j];
			if(total >=2){
				cout<<i;
				return 0;
			}
		}
	}

	cerr << "time elapsed: "<<TIME <<"s.\n";
}




