// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(int (i)=(a);i<=(b);++i)


int n,m;

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    cin>>n>>m;
    set<set<int>>unq;
    FOR(i,0,n-1){
    	set<int>st;
    	FOR(j,0,m-1){
    		int x;cin>>x;
    		st.insert(x);
    	}
    	unq.insert(st);
    }
    cout<<unq.size();
}


