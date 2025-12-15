// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define file "DL"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int ans = -1;
string s;

bool valid(string str){

    int cntv = 0;
    int cntd = 0;

    for(auto&x:str){
        if(x=='V')cntv++;
        else cntd++;
    }

    return cntv == cntd*2;
}

void sub1(){
    
    int n = s.size()-1;

    for(int i=0; i<n; i++){
        for(int l=0; l<n; l++){
            for(int r=l; r<n; r++){
                if(valid(s.substr(l, r-l+1))){
                    //cout<<s.substr(l, r-l+1)<<'\n';
                    ans = max(ans, r-l+1);
                }
            }
        }
    }

    cout<<ans;    
}

i_love_Hoang_Ngan(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>s;
    sub1();
    
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
