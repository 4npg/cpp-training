// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(int (i)=(a);i<=(b);++i)

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    int t;cin>>t;
    cin.ignore();
    while(t--){
    	string s;
    	getline(cin,s);
    	stringstream ss(s);
    	string tu;
    	int cnt=0;
    	while(ss>>tu){
    		cnt++;
    	}
    	cout<<cnt;
    	el;
    }

}


