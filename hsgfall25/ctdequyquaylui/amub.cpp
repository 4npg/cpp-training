// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define f0(i,a,b) for(int (i)=(a);i<=(b);++i)

const int64 mod = 1e9+7;

int64 mul(int64 a,int64 b,int64 mod){
	int64 ans = 0;
	while(b){
		if(b&1)ans=(ans+a)%mod;
		a=(a+a)%mod;
		b>>=1;
	}
	return ans;
}

int64 ipow(int64 a,int64 b,int64 mod){
	int64 ans = 1;
	while(b){
		if(b&1)ans=mul(ans,a,mod);
		a=mul(a,a,mod);
		b>>=1;
	}
	return ans;
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    int q;cin>>q;
    while(q--){
    	int64 a,b;
    	cin>>a>>b;
    	cout<<ipow(a,b,mod);el;
    }

}


