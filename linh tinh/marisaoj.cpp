// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

int a[3];
int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    f0(i,0,2){
        cin>>a[i];
    }

    sort(a, a + 3);
    if (a[2] - a[0] >= 10) {
        cout << "check again";
    } else {
        cout << "final " << a[1];
    }


    cerr << "time elapsed: "<<TIME <<"s.\n";
}


