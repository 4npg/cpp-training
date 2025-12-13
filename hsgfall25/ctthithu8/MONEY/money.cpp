// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "money"
#define int64 long long
#define f0(i, a, b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define fi first
#define se second
#define maxn 100
#define inf (int)1e9
#define ifs (int64)4e18
#define maxs 2000000

int n, s;
int a[maxn];
int dp[maxs+5];

void sub1(){
    sort(a+1, a+n+1, greater<int>());

    int cnt = 0;
    int i = 1;
    while(s>0){
        if(s>=a[i]){
            while(s>=a[i]){
                s-=a[i];
                cnt++;
            }
        }else i++;
    }

    cout<<cnt;
}

void sub2(){
    f0(i, 0, s)dp[i] = inf;
    dp[0] = 0;
    f0(i, 1, s){
        f0(j, 1, n){
            if(i>=a[j]) dp[i] = min(dp[i], dp[i-a[j]]+1);
        }
    }
    cout<<dp[s];
}

int64 d[105];
bool used[105];

void sub3(){
    int mx = 0;
    f0(i,1,n) mx = max(mx, a[i]);

    f0(i,0,mx-1) d[i] = ifs;
    d[0] = 0;

    priority_queue<pair<int64,int>, vector<pair<int64,int>>, greater<pair<int64,int>>> pq;
    pq.push({0,0});

    while(!pq.empty()){
        auto top = pq.top();
        auto du = top.fi;
        auto u = top.se;
        pq.pop();
        if(du != d[u]) continue;
        f0(i,1,n){
            int v = (u + a[i]) % mx;
            int64 w = du + 1;
            if(w < d[v]){
                d[v] = w;
                pq.push({w,v});
            }
        }
    }

    int r = s % mx;
    int64 res = d[r] + (s - r) / mx;
    cout << res;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    cin>>n>>s;
    f0(i, 1, n)cin>>a[i];

    if(s<=10000)sub2();
    else sub3();

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
