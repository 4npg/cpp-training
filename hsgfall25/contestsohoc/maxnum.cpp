// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define f0(i,a,b) for(int (i)=(a);i<=(b);++i)

int n,p;

int get(int n,int p){
	if(n<p)return 0;
	return n/p + get(n/p,p);
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    cin>>n>>p;
    int res = 1e6;
    for(int i=2;i<=p;i++){
    	int cnt=0;
    	if(p%i==0){
    		while(p%i==0){
    			p/=i;
    			cnt++;
    		}
    		res = min(res,get(n,i)/cnt);
    	}
    }
    cout<<res;
}


