// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int x, y;
int64 n;
int64 sum;


i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>x>>y>>n;

	int64 k = n / 7;
    int64 r = n % 7;
    sum += k * (5LL * x + 2LL * y);

    if(r >= 1){
        sum += y;
        sum += (r - 1) * x;
    }

    cout << sum;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


