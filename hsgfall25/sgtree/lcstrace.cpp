// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 1000
#define pb push_back
#define all(a) (a).begin(),(a).end()
int n;

int a[maxn], b[maxn];
int f[maxn][maxn];


int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin>>n;
    f0(i,1,n){
        cin>>a[i];
    }

    f0(i,1,n)cin>>b[i];

    f[0][0] = 0;

    f0(i, 1, n){
        f0(j, 1, n){
            if(a[i]==b[j]){
                f[i][j] = f[i-1][j-1] + 1;
            }else{
                f[i][j] = max(f[i][j-1], f[i-1][j]);
            }
        }
    }


    vector<int> ans;

    cout<<f[n][n]<<'\n';
    int m = n;
    while(n&&m){
        if(a[n] == b[m]){
            ans.pb(a[n]);
            n--;
            m--;
        }
        else
            if(f[n-1][m] > f[n][m-1])n--;
            else m--;
    }

    reverse(all(ans));

    for(auto &x:ans)cout<<x<<" ";

    cerr << "time elapsed: "<<TIME <<"s.\n";
}


