#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int i=(a); i<=(b); ++i)
#define maxn 10
#define inf 1e9

int n;
int a[maxn][maxn];
int64 ans = -inf;
bool vis[maxn]; 

int maR[maxn];

void Try(int r, int64 cur) {
    if (r == n) {
        if (cur > ans) {
            ans = cur;
        }
        return;
    }

    int64 rmain = 0;
    f0(i,r,n-1) rmain += maR[i];
    if (cur + rmain <= ans) return; 

    f0(c,0,n-1){
        if(!vis[c]){
            vis[c] = 1; 
            Try(r+1, cur + a[r][c]);
            vis[c] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    f0(i,0,n-1){
        f0(j,0,n-1) 
            cin>>a[i][j];
    }

    f0(i,0,n-1){
        maR[i] = *max_element(a[i], a[i]+n);
    }

    // f0(i, 0, n-1){
    //     cout<<maR[i]<<" ";
    // }
    // cout<<'\n';
    Try(0, 0);

    cout<<ans;
}
