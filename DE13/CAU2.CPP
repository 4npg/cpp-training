// author : anphung
// github : 4npg  >>tqn
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "CAU2"
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int n,res;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	if(fopen(TASK".inp","r")){
		freopen(TASK".inp","r",stdin);
		freopen(TASK".out","w",stdout);
	}
	cin>>n;
	map<int,int> mp;

	f0(i,0,n-1){
		int x;cin>>x;
		mp[x]++;
		res = max(res,mp[x]);
	}	
	cout<<res;
}


