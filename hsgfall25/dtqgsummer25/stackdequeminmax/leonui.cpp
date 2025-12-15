// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 1000006
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
int n, m, c;

int64 a[maxn];

i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>m>>c;
	f0(i, 1, n)cin>>a[i];

	deque<int> midq;
	deque<int> madq;
	vector<int> ans;

	f0(i, 1, n){
		while(!midq.empty() && a[midq.back()] >= a[i])midq.pob();
		midq.pb(i);

		while(!madq.empty() && a[madq.back()] <= a[i])madq.pob();
		madq.pb(i);

		int l = i-m+1;

		if(midq.front() < l)midq.pof();
		if(madq.front() < l)madq.pof();

		if(i>=m){
			int ma = a[madq.front()];
			int mi = a[midq.front()];

			if(ma-mi<=c)ans.pb(l);
		}
	}


	if(ans.empty()){
		cout<<-1;
	}else{
		for(auto &x:ans)cout<<x<<" ";
	}
	cerr << "time elapsed: "<<TIME <<"s.\n";
}




