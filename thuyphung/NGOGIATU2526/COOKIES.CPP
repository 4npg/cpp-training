// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define maxn 100005
#define inf 4e18

int n;
int64 a[maxn], sufSum[maxn], sufMin[maxn];

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n;
	f0(i, 0, n-1)cin>>a[i];

	sufSum[n] = 0;
    sufMin[n] = inf;

    for(int i=n-1;i>=0;i--){
        sufSum[i] = sufSum[i+1] + a[i];
        sufMin[i] = min(sufMin[i+1], a[i]);
    }

    int64 cur = -inf;
    int64 res = 0;
    f0(k, 0, n-3){
    	cur = max(cur, (sufSum[k+1]-sufMin[k+1])/(n-k-1));
    }


    for(int k=0;k<=n-3;k++){
    	if((sufSum[k+1]-sufMin[k+1])/(n-k-1)==cur){
    		cout<<k+1<<" ";
    	}
    }
	cerr << "time elapsed: "<<TIME <<"s.\n";
}





