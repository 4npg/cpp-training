// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define maxn 100005
#define pb push_back
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

int n;
int64 a[maxn];
int64 dp[maxn][3];
pair<int,int> trace[maxn][3]; 
vector<int> res;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    f0(i, 1, n)cin>>a[i];

    dp[0][0] = dp[0][1] = dp[0][2]=0;

    for(int i=1;i<=n;i++){
        int64 ma = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        dp[i][0] = ma;

        if(ma == dp[i-1][0])trace[i][0] = {i-1, 0};
        else if(ma == dp[i-1][1])trace[i][0] = {i-1, 1};
        else trace[i][0] = {i-1, 2};

        dp[i][1] = dp[i-1][0] + a[i];
        trace[i][1] = {i-1, 0};

        dp[i][2] = dp[i-1][1] + a[i];
        trace[i][2] = {i-1, 1};

    }

    int64 ans = max({dp[n][0], dp[n][1], dp[n][2]});
    int k;
    if(ans==dp[n][0]) k=0;
    else if(ans==dp[n][1]) k=1;
    else k=2;

    int i=n;
    while(i){
        if(k>0) res.pb(i); 
        int pi = trace[i][k].fi;
        int pk = trace[i][k].se;
        i = pi;
        k = pk;
    }
    reverse(all(res));

    cout<< res.size() << " " << ans << "\n";
    for(int x: res) cout << x << "\n";

    cerr<<"\ntime elapsed: "<<TIME<<"s.\n";
}
