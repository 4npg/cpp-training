// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "UCLN"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(int (i)=(a);i<=(b);++i)

int n;
const int maxn = 1e3+5;
int64 a[maxn];

int64 gcd(int64 a,int64 b){
	if(b==0)return a;
	return gcd(b,a%b);
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    cin>>n;
    int64 res = 0;
    int64 tmp;
    FOR(i,0,n-1){
    	cin>>a[i];
    	res = max(res,gcd(tmp,a[i]));
    	tmp = a[i];
    }
    cout<<res;
}


