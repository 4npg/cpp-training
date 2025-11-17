// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

int n;
int64 chan,le,sum,ans;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file("ddelete");
	cin>>n;
	f0(i,0,n-1){
		int x;cin>>x;
		sum+=x;
		if(!(x&1))chan++;
		else le++;
	}

	if(!(sum&1))ans=chan*(chan-1)/2 + le*(le-1)/2;
	else ans = chan*le;
	cout<<ans;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


