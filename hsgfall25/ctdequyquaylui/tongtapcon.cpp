// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define f0(i,a,b) for(int (i)=(a);i<=(b);++i)

int n,k;
const int maxn = 1e3+5;
int a[maxn];
int cnt=0;

void Try(int pos,int64 cursum,int taken){
	if(pos==n){
		if(cursum==k&&taken>0)cnt++;
		return;
	}
	Try(pos+1,cursum+a[pos],taken+1);
	Try(pos+1,cursum,taken);
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    cin>>n>>k;
    f0(i,0,n-1)cin>>a[i];
    Try(0,0,0);
    cout<<cnt;
}


