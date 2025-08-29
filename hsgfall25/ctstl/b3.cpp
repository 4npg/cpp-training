// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(int (i)=(a);i<=(b);++i)


int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    string s;
    cin>>s;
    map<char,int>freq;
    // for(auto c='a';c<='z'l;c++){
    // 	freq[c]=0;
    // }
    for(auto &c:s){
    	freq[c]++;
    }
    for(auto c='a';c<='z';c++){
    	if(freq[c]>=1){
    		cout<<c<<" "<<freq[c];
    		el;
    	}
    }

}


