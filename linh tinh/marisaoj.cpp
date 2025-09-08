// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int n,q;

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    unordered_map<string,int> freq; 
    f0(i,0,n-1){
        string s;cin>>s;
        freq[s]++;
    }
    cin>>q;
    while(q--){
        string x;cin>>x;
        if(freq.count(x)){
            cout<<"YES\n";
        }else cout<<"NO\n";
    }
}


