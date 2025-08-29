// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(int (i)=(a);i<=(b);++i)

int n,t;
const int maxn = 1e6+5;
int64 a[maxn];

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    cin>>n;
   	a[0] = 0;
    FOR(i,1,n){
    	int64 x;cin>>x;
    	a[i] = a[i-1] + x;
    }
    // FOR(i,1,n){
    // 	cout<<a[i]<<" ";
    // }
    // el;
    cin>>t;
    while(t--){
    	int l,r;
    	cin>>l>>r;
    	cout<<a[r]-a[l-1];
    	el;
    }
}


