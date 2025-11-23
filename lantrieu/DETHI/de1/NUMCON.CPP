// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "NUMCON"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define pb push_back

vector<string> a;

bool cmp(string a, string b){
    return a+b>=b+a;
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    string s;
    while(cin>>s){
        a.pb(s);
    }

    sort(a.begin(),a.end(),cmp);

    for(auto &x:a)cout<<x;
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
