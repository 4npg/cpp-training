// author : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "AVERAGE"
#define el cout << "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define f0(i,a,b) for (int (i) = (a); i <= (b); ++i)
#define ld long double
const int64 oo = 1e18;
const int maxn = 1e6+5;
int64 a[maxn];
int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    int n, k;
    cin >> n >> k;
    f0(i,0,n-1)cin>>a[i];

    int l = 0;
    int64 sum = 0;
    int64 bestSum = -oo;
    int bestLen = 0;

    f0(r,0,n-1) {
        sum += a[r];
        while((ld)(sum-a[l])/(r-l)>(ld)sum/(r-l+1)){
            sum -= a[l];
            l++;
        }
        if(r-l+1>=k){
            if(bestSum==-oo||(ld)sum/(r-l+1)>(ld)bestSum/bestLen){
                bestSum = sum;
                bestLen = r - l + 1;
            }
        }
    }

    cout<<fixed<<setprecision(3)<<(ld)bestSum/bestLen;
}
