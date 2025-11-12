// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define fi first
#define se second
#define inf 1000000000

int k;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>k;
	vector<int> d(k,inf);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater< pair<int,int>>> pq;

	f0(di,1,9){
		int r = di%k;
		if(di<d[r]){
			d[r] = di;
			pq.push({di,r});
		}
	}

	while(!pq.empty()){
		auto top = pq.top();
		pq.pop();
		auto cost = top.fi;
		auto u = top.se;
		if(cost>d[u])continue;
		f0(di,0,9){
			int v = (1LL*u*10+di)%k;
			int ncost = cost + di;

			if(ncost < d[v]){
				d[v] = ncost;
				pq.push({ncost,v});
			}
		}
	}

	cout<<d[0];

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


