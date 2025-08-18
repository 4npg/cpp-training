// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define f0(i,a,b) for(int (i)=(a);i<=(b);++i)

const int maxn = 1e4;
int n,x;
int64 a[maxn];
int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    cin>>n>>x;
    map<int64,int> mp;
    f0(i,0,n-1){
    	cin>>a[i];
    }
    f0(i,0,n-1){
    	f0(j,i+1,n-1){
    		if(mp.count(x-a[i]-a[j])){
    			cout<<mp[x-a[i]-a[j]]+1<<" "<<i+1<<" "<<j+1;
    			return 0;
    		}
    	}
    	mp[a[i]] = i;
    }
    cout<<"IMPOSSIBLE";
}


