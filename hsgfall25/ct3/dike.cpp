// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

int64 n;
int64 ans;


bool ok(int64 k, int64 n) {
    int64 x = k, y = k + 1, z = k + 5;

    if(x>6*(n+1)/y)return false;

    if(x*y>6*(n+1)/z)return false;

    return x*y*z<=6*(n+1);
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	


	cin>>n;
	int64 lo = 0, hi = 3e6;

	while (lo <= hi) {
        int64 mid = (lo+hi)/ 2;
        if (ok(mid, n)) {
            ans = mid;
            lo = mid + 1;
        } else hi = mid - 1;
    }

	cout<<ans;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


