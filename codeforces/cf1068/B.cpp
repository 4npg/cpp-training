// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 100005
#define inf (int64)4e18
int t;

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>t;
    while (t--) {
        int n; cin>>n;
         vector<int64> a(n), b(n);
        f0(i, 0, n-1)cin>>a[i];
        f0(i, 0, n-1)cin>>b[i];

        int64 l = 0, r = 0;

        f0(i, 0, n-1) {
            int64 l1 = l - a[i];
            int64 r1 = r - a[i];

            int64 l2 = b[i] - r;
            int64 r2 = b[i] - l;

            int64 nl = min(l1, l2);
            int64 nr = max(r1, r2);

            l = nl;
            r = nr;
        }

        cout << r << "\n";
    }

	cerr << "time elapsed: "<<TIME <<"s.\n";
}

