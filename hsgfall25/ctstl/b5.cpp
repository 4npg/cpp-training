// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(int (i)=(a);i<=(b);++i)

const int maxn = 1e6+5;
int n,x;
int64 a[maxn];

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    cin>>n>>x;
    unordered_map<int64,int> freq;
    int64 cnt=0;
    FOR(i,0,n-1){
    	cin>>a[i];
    	cnt+=freq[x-a[i]];
    	freq[a[i]]++;
    }
    cout<<cnt;
}


