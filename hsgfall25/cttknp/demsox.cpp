// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define pb push_back
#define all(a) (a).begin(),(a).end()

int n,q;
const int maxn = 1e6+5;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	map<int64, vector<int>> pos;
	f0(i,0,n-1){
		int64 x;cin>>x;
		pos[x].pb(i+1);
	}
	cin>>q;
	while(q--){
		int l,r;
		int64 x;
		cin>>l>>r>>x;
		if(pos.find(x)==pos.end()){
			cout<<0<<'\n';
			continue;
		}
		auto &vec = pos[x];
		auto itl = lower_bound(all(vec),l);
		auto itr = upper_bound(all(vec),r);
		cout<<(itr-itl)<<'\n';
	}
}


