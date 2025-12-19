// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 unsigned long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn (int64)1e18
#define pb push_back

vector<int64> a;
int q;

void sinh(){
    for(int i=0;i<=60;i++){
        int64 p2 = 1;
        for(int x=0;x<i;x++) p2 *= 2;

        for(int j=0;j<=38;j++){
            int64 p23 = p2;
            for(int x=0;x<j;x++) p23 *= 3;

            for(int k=0;k<=26;k++){
                int64 val = p23;
                for(int x=0;x<k;x++) val *= 5;

                if(val <= 1e18*1ULL)
                    a.pb(val);
            }
        }
    }
}
i_love_Hoang_Ngan(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sinh();
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()),a.end());
    cin>>q;
    while(q--){
        int64 m;
        cin>>m;

        auto pos = lower_bound(a.begin(), a.end(), m);
        if(pos != a.end() && *pos == m){
            cout<<(pos-a.begin()+1)<<'\n';
        }else cout<<-1<<'\n';
    }

    cerr << "time elapsed: "<<TIME <<"s.\n";
}




