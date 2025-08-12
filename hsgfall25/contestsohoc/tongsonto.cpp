// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define f0(i,a,b) for(int (i)=(a);i<=(b);++i)

const int maxn = 1e7+5;
bitset<maxn> d;
int n;
void sang(){
	d[0] = d[1] = 1;
	for(int i=2;i*i<maxn;i++){
		if(d[i]==0){
			for(int j = i*i;j<maxn;j+=i)d[j]=1;
		}
	}
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    sang();
    cin>>n;
    int64 sum=0;
    for(int i=2;i<=n;i++){
    	if(d[i]==0)sum+=i*1ll;
    }
    cout<<sum;
}
