// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "CAU2"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define fi first
#define se second
#define pb push_back

string s;
 map<string,int> a = {
        {"I",1},{"V",5},{"X",10},{"L",50},
        {"C",100},{"D",500},{"M",1000}
};

int ans;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    cin>>s;

    for(int i = 0;i<s.size();++i){
        string tmp = "";
        tmp += s[i];
        string nx = "";
        if (i + 1 < s.size()) nx += s[i + 1];
        if (!nx.empty() && a[tmp] < a[nx]) ans -= a[tmp];
        else ans += a[tmp];
    }

    cout<<ans;

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
