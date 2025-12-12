// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file "task"

int y, k, n;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(file".inp", "r", stdin);
    freopen(file".ans", "w", stdout);
    cin>>y>>k>>n;
    int stnum = ((y + k) / k) * k;
    bool ok = false;


    for (int i = stnum; i <= n; i += k) {
        cout <<i - y<<" ";
        ok = true;
    }

    if (!ok)cout<<"-1";
    cerr << "time elapsed: "<<TIME <<"s.\n";
}


