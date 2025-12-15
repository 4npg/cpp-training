// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

#define maxn 100005

int n;
int64 s;
int64 a[maxn];
int64 mx;

bool check(int64 mid){
    int64 sum = 0;

    f0(i, 0, n-1){
        if(a[i] > mid){
            sum += (a[i] - mid);
            if(sum>=s)return true;
        }
    }
    return false;
}

i_love_Hoang_Ngan(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>n>>s;
    f0(i, 0, n-1){
        cin>>a[i];
        mx = max(mx, a[i]);
    }

    int64 l = 0, r = mx, ans = 0;

    while(l <= r){
        int64 mid = l + (r-l)/2;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
    }

    cout<<ans;
    cerr << "time elapsed: "<<TIME <<"s.\n";
}

