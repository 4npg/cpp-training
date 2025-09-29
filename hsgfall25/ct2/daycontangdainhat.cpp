// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define pb push_back
#define all(a) (a).begin(),(a).end()

int n;
const int maxn = 2e6+10;
int64 a[maxn];


vector<int64>dp;

void sub2(){
	for(auto x:a){
		auto it = lower_bound(all(dp),x);
		if(it==dp.end())dp.pb(x);
		else *it=x;
	}
	cout<<dp.size();
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin>>n;
	f0(i,0,n-1)cin>>a[i];
	sub2();
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


