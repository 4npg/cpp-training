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

#define maxn 10000006
#define maxp 2000
bool d[maxn];
int pre[maxn];
int t;
void sang(){
	d[0] = d[1] = 1;

	for(int i=2; i*i<maxn; i++){
		if(!d[i]){
			for(int j=i*i; j<maxn; j+=i)d[j] = 1;
		}
	}

	f0(i, 2, maxn)if(!d[i])pre[i] = pre[i-1] + (!d[i]);
}

i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	file("GAME");
	sang();

	cin>>t;
	while(t--){
		int a, b, c, d;
		cin>>a>>b>>c>>d;

		bool tam = false;

		f0(x, a, b){
			int l = x+c;
			int r = x+d;
			if(l>maxp)continue;
			r = min(r, maxp);

			int cnt = pre[r] - pre[l-1];
			if(cnt == 0){
				tam = true;
				break;
			}
		}
		if(tam)cout<<"Tam\n";
		else cout<<"Cam\n";
	}

	cerr << "time elapsed: "<<TIME <<"s.\n";
}
