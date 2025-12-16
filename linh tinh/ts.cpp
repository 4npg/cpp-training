// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn 100005
#define fi first 
#define se second
int n;

bool cmp(pair<string, int> a, pair<string, int> b){
    return a.se < b.se;
}

i_love_Hoang_Ngan(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n;
    map<string,int> mp;
    vector<string> bo = {"Bessie","Elsie","Daisy","Gertie","Annabelle","Maggie","Henrietta"};
    
    for(int i = 0; i < n; i++){
        string s; int v;
        cin >> s >> v;
        mp[s] += v;
    }

    int minval = INT_MAX;    
    for(auto &c : bo) {
        minval = min(minval, mp[c]);
    }
    int minval2 = INT_MAX;
    string ans = "!";
    for(auto &c : bo) {
        if(minval2 > mp[c] && mp[c] > minval){
            minval2 = mp[c];
            ans = c;
        }
    }
    if(ans == "!")cout<<"Tie";
    else cout<<ans;
    
    
    cerr << "time elapsed: "<<TIME <<"s.\n";
}




