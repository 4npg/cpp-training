// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 200005
#define pb push_back
#define se second
#define all(a) (a).begin(),(a).end()

int n;
int cur,ans;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n;
	vector< pair<int64, int> > thoidiem;
	thoidiem.reserve(n*2);

	f0(i,0,n-1){
		int64 a,b;
		cin>>a>>b;
		thoidiem.pb({a,+1});
		thoidiem.pb({b,-1});
	}	
	sort(all(thoidiem));
	for(auto &x:thoidiem){
		cur += x.se;
		ans = max(ans,cur);
	}

	cout<<ans;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


