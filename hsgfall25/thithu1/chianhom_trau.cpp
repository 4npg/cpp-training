#include<bits/stdc++.h>
using namespace std;
#define file "chianhom"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define maxn (int)1e5+10
int n;
int a[maxn];
void sub1() {
    int64_t ans = LLONG_MAX;
    int S = 0;
    for (int i = 0; i < n; ++i) S += a[i];

    int total = 1;
    f0(i,0,n-1)total *= 3;

    f0(mask,0,total-1){
        int x = 0, y = 0, z = 0, tmp = mask;
        f0(i,0,n-1){
            int group = tmp % 3;
            tmp /= 3;
            if (group == 0) x += a[i];
            else if (group == 1) y += a[i];
            else z += a[i];
        }
        if (x == y) ans = min(ans, (int64_t)(S - x));
    }

    cout << ans;
}

void sub2() {
    int S = accumulate(a, a + n, 0);
    int ans = 0;
    vector<vector<int>> masks(1005);

    int limit = 1 << n;
    for (int mask = 1; mask < limit; ++mask) {
        int sum = 0;
        for (int i = 0; i < n; ++i)
            if (mask >> i & 1) sum += a[i];
        if (sum <= 1000) masks[sum].push_back(mask);
    }

    for (int t = 1; t <= 1000; ++t) {
        auto &v = masks[t];
        for (int i = 0; i < (int)v.size(); ++i)
            for (int j = i + 1; j < (int)v.size(); ++j)
                if ((v[i] & v[j]) == 0)
                    ans = max(ans, t);
    }

    cout << S - ans;
}


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".ans","w",stdout);
    cin>>n;
    f0(i,0,n-1){
        cin>>a[i];
    }
    sub1();
    cerr<<'\n'<<"time elapsed: "<<TIME <<"s.\n";
}
