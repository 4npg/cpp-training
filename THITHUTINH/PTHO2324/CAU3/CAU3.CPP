// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file "CAU3"

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn 200005
string s;
int d[26];
int cnt = 1;

youngboiz_nobug(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    //freopen(file".out","w",stdout);

    cin>>s;

    int l = 0;
    int n = s.size();

    f0(r, 0, n-1){
        if(d[s[r]-'a']){
            cnt++;
            l = r;
            memset(d, 0, sizeof d);
            //cout<<'\n';
        }
        d[s[r]-'a'] = 1;
        //cout<<s[r];
    }

    cout<<cnt;
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
