// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i=(a); i<=(b);++i)
#define fd(i,a,b) for(int i=(a); i>=(b);--i)
#define file "daybian"

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn 200005

int n; int64 s;
int64 a[maxn];
int64 pre[maxn];

int64 cnt;

void sub1(){
    f0(i, 0, n-1){
        cin>>a[i];
        pre[i+1] = pre[i] + a[i];
    }

    f0(i, 0, n-1){
        f0(j, i, n-1){
            if(pre[j+1] - pre[i] == s){
                cnt++;
//                cout<<i+1<<" "<<j+1<<'\n';
            }
        }
    }

    cout<<cnt;
}

void sub2(){

    map<int64, int> mp;
    mp[0] = 1;

    f0(i, 1, n){
        cin>>a[i];
        pre[i] = pre[i-1] + a[i];

        if(mp.count(pre[i] - s)){
            cnt += mp[pre[i] - s];
        }
        mp[pre[i]]++;
    }
    cout<<cnt;
}
con_meo_dua_leo(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    cin>>n>>s;
    if(n<=1000)sub1();
    else sub2();

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
