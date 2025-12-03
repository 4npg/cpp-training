// authur : anphung >> npkly
#include<bits/stdc++.h>
#define TASK ""
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)


int n;
int64 k;
const int maxn = 1e6+5;
int64 a[maxn];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("WATERFILL.inp","r",stdin);
	freopen("WATERFILL.out","w",stdout);
	cin>>n>>k;
	f0(i,0,n-1){
		cin>>a[i];
	}
	int64 tt = n*k;
	long double time = 0.0;
	f0(i,0,n){
		time += (long double)(a[i])/tt;
	}
	cout<<(int)ceil(time);
	cerr << "time elapsed: "<<TIME <<"s.\n";
}