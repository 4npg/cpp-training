// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

int n,q;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file("QSUM");
	cin>>n>>q;
	vector<int64> pre(n+1,0);
	f0(i,1,n){
		int x;cin>>x;
		pre[i] = pre[i-1]+x;
	}	

	while(q--){
		int l,r;cin>>l>>r;
		cout<<pre[r] - pre[l-1]<<'\n';
	}

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


