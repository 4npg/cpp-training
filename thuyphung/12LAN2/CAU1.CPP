// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}

string s;

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>s;
    int pos = s.size()-1;
    while(s[pos]=='0'){
        pos--;
    }
    for(; ~pos; pos--){
        cout<<s[pos];
    }

    cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}





