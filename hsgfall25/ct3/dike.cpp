// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

int64 n;
int64 ans;

bool safe_mul(int64 a,int64 b,int64 limit){
	if(a==0)return 1;
	return b<=limit/a;
}

bool ok(int64 k, int64 n) {
    int64 x = k, y = k + 1, z = k + 2;

    if (x % 2 == 0) x /= 2;
    else if (y % 2 == 0) y /= 2;
    else z /= 2;

    if (x % 3 == 0) x /= 3;
    else if (y % 3 == 0) y /= 3;
    else z /= 3;

    if (!safe_mul(x, y, n)) return false;
    int64 xy = x * y;
    if (!safe_mul(xy, z, n)) return false;

    return xy * z <= n;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	


	cin>>n;
	int64 lo = 0, hi = 2000000;

	while (lo <= hi) {
        int64 mid = lo + (hi - lo) / 2;
        if (ok(mid, n)) {
            ans = mid;
            lo = mid + 1;
        } else hi = mid - 1;
    }

	cout<<ans;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


