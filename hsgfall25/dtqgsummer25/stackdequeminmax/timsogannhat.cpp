// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);


mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int Rand(int l, int r){
    return l+rng()%(r-l+1);
}

char db[] = {'!', '@', '#', '$', '%', '&', '*', '?'};

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
    int chonso = Rand(0, 7);
    int so[] = {33, 64, 35, 36, 37, 38, 42, 63};
    char c = (char)so[chonso];

    cout<<c;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


