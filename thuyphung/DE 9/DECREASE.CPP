// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "DECREASE"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define f0(i,a,b) for(int (i)=(a);i<=(b);++i)

int n;

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    cin>>n;
    int nn = n;
    int cnt = 0;
    int mx = 0;
    while(n){
    	while(nn){
    		mx = max(mx,nn%10);
    		nn/=10;
    	}
    	n-=mx;
    	cnt++;
    	nn = n;
    	mx = 0;
    }
    cout<<cnt;
}


