// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}


int64 n;
bool pds(int64 n){
	int64 tong=0,tich=1;
	while(n){
		if(n%10==0)return 1;
		tong+=(n%10);
		tich*=(n%10);
		n/=10;
	}
	if(tong==0)return 0;
	return(tich%tong==0);
}

int64 cnt(int64 x){
	int64 d = 0;
	for(int64 i=1;i<=x;i++){
		if(pds(i))d++;
	}
	return d;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	//file("SOPDS");
	cin>>n;	
	int64 lo=1,hi=1e7;
	int64 ans = -1;
	while(lo<=hi){
		int64 mid = lo + ((hi-lo)>>1LL);
		if(cnt(mid)>=n){
			ans = mid;
			hi = mid-1;
		}else{
			lo = mid+1;
		}
	}
	cout<<ans;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


