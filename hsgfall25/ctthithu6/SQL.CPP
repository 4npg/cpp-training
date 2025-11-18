#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define file "SQL"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

const int maxn = 1005;

int n, m, k;
int a[maxn][maxn];
int pref0[maxn][maxn], pref1[maxn][maxn], pref2[maxn][maxn];

int get_max_len(int ok[], int n){
    int len=0, res=0;
    for(int j=1;j<=n;j++){
        if(ok[j]) len++;
        else len=0;
        if(len>res) res=len;
    }
    return res;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    cin>>m>>n;
    f0(i,1,m){
        f0(j,1,n){
            cin>>a[i][j];
            pref0[i][j] = pref0[i-1][j] + (a[i][j]==0);
            pref1[i][j] = pref1[i-1][j] + (a[i][j]==1);
            pref2[i][j] = pref2[i-1][j] + (a[i][j]==2);
        }
    }
    cin>>k;
    while(k--){
        int p,q;
        cin>>p>>q;
        int hei = q-p+1;
        int ok01[maxn], ok12[maxn];
        for(int j=1;j<=n;j++){
            int cnt0 = pref0[q][j] - pref0[p-1][j];
            int cnt1 = pref1[q][j] - pref1[p-1][j];
            int cnt2 = pref2[q][j] - pref2[p-1][j];
            ok01[j] = (cnt2==0);
            ok12[j] = (cnt0==0);
        }
        int wid01 = get_max_len(ok01,n);
        int wid12 = get_max_len(ok12,n);
        int max_area = max(wid01*hei, wid12*hei);
        cout<<max_area<<"\n";
    }
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
