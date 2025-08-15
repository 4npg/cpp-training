// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "SQROOT"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define f0(i,a,b) for(int (i)=(a);i<=(b);++i)

const int mod = 2021;
const int inv6 = 337;
int64 n;

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    cin>>n;
    int64 a = n%mod;
    int64 b = (n+1)%mod;
    int64 c = ((2%mod)*(n%mod)+1)%mod;

    int64 ans = a;
    ans = (ans*b)%mod;
    ans = (ans*c)%mod;
    ans = (ans*inv6*1ll)%mod;
    cout<<ans;

}


