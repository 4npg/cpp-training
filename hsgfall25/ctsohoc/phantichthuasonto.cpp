// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define f0(i,a,b) for(int (i)=(a);i<=(b);++i)
#define fi first
#define se second

int64 n;

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    cin>>n;
    map<int64,int> freq;
    if(n==1){ cout<<0<<"\n"; return 0; }
    while(n%2==0){ 
        freq[2]++;
        n/=2; 
    }
    while(n%3==0){ 
        freq[3]++; 
        n/=3; 
    }
    for(int64 i=5;i<=n/i;i+=6){
        while(n%i==0){ 
            freq[i]++; 
            n/=i; 
        }
        while(n%(i+2)==0){ 
            freq[i+2]++; 
            n/=(i+2); 
        }
    }
    if(n>1)freq[n]++;
    cout<<freq.size();
    el;
    for(auto &x:freq){
	    cout<<x.fi<<" "<<x.se;
        el;
    }
}



