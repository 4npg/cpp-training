// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 1000006

int n;
int64 cnt0, cnt1;

i_love_Hoang_Ngan(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n;
	f0(i, 0, n-1){
		int64 x; cin>>x;
		cnt0 += (x%2==0?1:0);
		cnt1 += (x%2==1?1:0);
	}

	cout<<cnt0*cnt1;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


