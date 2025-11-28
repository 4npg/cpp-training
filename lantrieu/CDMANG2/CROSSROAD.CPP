// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 100005

int n;
map<int, int> mp;
int cnt;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n;
	f0(i,0,n-1){
		int id, pos;
		cin>>id>>pos;
		if(mp.count(id) && mp[id] != pos){
			cnt++;
		}
		mp[id] = pos;
	}

	cout<<cnt;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


