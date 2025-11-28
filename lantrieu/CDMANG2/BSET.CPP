// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 100005

int n,m;
int cnt;
set<int> ans;
map<int, int> mpa;
map<int, int> mpb;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>m;	f0(i,0,n-1){
		int a; cin>>a;
		ans.insert(a);
		mpa[a]++;
	}

	f0(i,0,m-1){
		int b; cin>>b;
		ans.insert(b);
		mpb[b]++;
	}

	for(auto &x:ans){
		if(mpa[x]>=1 && mpb[x]>=1){
			cnt++;
		}
	}

	cout<<ans.size()<<" "<<cnt;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


