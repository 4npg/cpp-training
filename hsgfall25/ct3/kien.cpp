// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 100005;

int n;
int64 m;


int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	long double ans = 0.0;
	f0(i,0,n-1){
		int64 a,v;
		char d;
		cin>>a>>v>>d;
		if(d=='L'){
			ans +=(long double)a/v;
		}else ans += (long double)(m-a)/v;
	}

	cout<<(int64)ceil(ans);

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


