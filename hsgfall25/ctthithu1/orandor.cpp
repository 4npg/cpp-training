// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define maxn 1000006


int n,k;
int64 ans;
int64 a[maxn];

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>k;
	f0(i,0,n-1)cin>>a[i];

	for(int bit = 60;bit>=0;--bit){
		int64 tmp = ans | (1ll<<bit);
		int cnt = 0;
		int64 cur = 0;
		f0(i,0,n-1){
			cur|=a[i];
			if((cur&tmp)==tmp){
				cnt++;
				cur=0;
			}
		}
		if(cnt>=k)ans=tmp;
	}
	cout<<ans;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


