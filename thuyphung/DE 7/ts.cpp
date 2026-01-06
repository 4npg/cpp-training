// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file ""

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//    return l+rng()%(r-l+1);
//}

#define maxn 1000006
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)

int n, p, a, b, r;
int cnt = 0;
bool vis[maxn];
queue<int> q;

con_meo_dua_leo(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    cin>>n>>p;
    cin>>a>>b>>r;
    if(n<p)vis[n] = 1;

    n%=p;
    q.push(n);

    while(q.size()){
        int sz = q.size();
        while(sz--){
            int u = q.front(); q.pop();
            if(u == r && cnt){
                return cout<<cnt, 0;
            }
            int x = (u + a)%p;
            int y = (u + b)%p;
            int z = (u + a + b)%p;
            if(!vis[x]){
                vis[x] = 1;
                q.push(x);
            }

            if(!vis[y]){
                vis[y] = 1;
                q.push(y);
            }

            if(!vis[z]){
                vis[z] = 1;
                q.push(z);
            }
        }
        cnt++;
    }

    cout<<-1;
    cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
