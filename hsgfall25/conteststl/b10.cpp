// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
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
    n*=3;
    vector<int64> a(n);
    f0(i,0,n-1)cin>>a[i];
    vector<int64> l(n);
    vector<int64> r(n);
    priority_queue<int64,vector<int64>,greater<int64>> pqmin;
    int64 sum = 0;
    f0(i,0,n-1){
    	sum+=a[i];
    	pqmin.push(a[i]);
    	if(pqmin.size()>n/3){
    		sum-=pqmin.top();
    		pqmin.pop();
    	}
    	l[i] = sum;
    }
    priority_queue<int64> pqmax;
    sum = 0;
    for(int i=n-1;i>=0;i--){
    	sum+=a[i];
    	pqmax.push(a[i]);
    	if(pqmax.size()>n/3){
    		sum-=pqmax.top();
    		pqmax.pop();
    	}
    	r[i] = sum;
    }
    int64 ans = LLONG_MIN;
    for(int i=n/3-1;i<2*n/3;i++){
    	ans = max(ans,l[i]-r[i+1]);
    }
    cout<<ans;
}


