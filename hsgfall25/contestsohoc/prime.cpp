// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "PRIME"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define f0(i,a,b) for(int (i)=(a);i<=(b);++i)

const int maxn = 1e6+5;
bitset<maxn> d;
unsigned char cnt[maxn];


int n;
int main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    cin>>n;
    vector<int> a(n);
    int mx=0;
    for(int &x:a){
        cin>>x;
        mx=max(mx,x);
    }
    for (int i=2;i<=mx;++i)
        if(!d[i])
           for(int j=i;j<=mx;j+=i){
                d[j]=1;
                cnt[j]++;
           }
    int res = a[0], cntmx = cnt[a[0]];
    for (int x : a)
        if(cnt[x]>cntmx) {
            cntmx = cnt[x];
            res = x;
        }
    cout<<res;
}



