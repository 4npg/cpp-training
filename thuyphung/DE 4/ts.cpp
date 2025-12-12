// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 100005

int pre[maxn];
int ans = INT_MIN;
int n;

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    

    cin>>n;
    pre[0] = 0;
    f0(i, 1, n){
        int x; cin>>x;
        pre[i] = pre[i-1] + x;
    }

    f0(i, 1, n){
        int s1 = ((pre[i])*(-1) + (pre[n]-pre[i]));
        int s2 = (pre[i] + (pre[n]-pre[i])*(-1));
        ans = max(ans, max(s1, s2));
    }

    cout<<ans;
    cerr << "time elapsed: "<<TIME <<"s.\n";
}


