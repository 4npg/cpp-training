// author : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define f0(i,a,b) for(int (i)=(a);i<=(b);++i)
#define pb insert
#define all(a) (a).begin(),(a).end()
vector < set <int> > a(1001);
int n,m,u,v;

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    cin>>n>>m;
    f0(i,1,m){
    	cin>>u>>v;
    	a[u].pb(v);
    	a[v].pb(u);
    }
   
    f0(i,1,m){	
    	for(auto &x:a[i]){
    		cout<<x<<" ";
    	}
    	el;
    }
}


