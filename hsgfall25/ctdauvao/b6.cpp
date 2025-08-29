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
int d[maxn];
void sanguocntomin(){
    for(int i=1;i<maxn;i++){
        for(int j=i;j<maxn;j+=i){
            d[j]++;
        }
    }
}

int t;
int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    sanguocntomin();
    cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<d[n];
        el;
    }
}


