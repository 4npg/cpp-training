// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file "BAI2"
#define pb push_back
#define maxa 1000
#define maxs 2000
#define maxn 1000006

int n;
int a[maxn];
int freq[maxa+1];
int64 cntsum[maxs+1];
vector<int> vis;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);
    cin>>n;
    f0(i,0,n-1)cin>>a[i];
    int64 ans = 0;

    f0(i,0,n-1){
        int x = a[i];
        if(x<=maxs)ans+=cntsum[x];

        if(freq[x] == 0)vis.pb(x);

        for(int v:vis){
            cntsum[v+x] += freq[v];
        }
        freq[x]++;
    }
    cout<<ans;
    cerr << "time elapsed: "<<TIME <<"s.\n";
}





