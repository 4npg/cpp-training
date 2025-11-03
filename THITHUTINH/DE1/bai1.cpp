// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "bai1"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)

int x1,yz,x2,y2,x3,y3,x4,y4;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    // freopen(file".out","w",stdout);
    cin>>x1>>yz;
    cin>>x2>>y2;
    cin>>x3>>y3;


    if(x1==x2){
        x4 = x3;
    }else if(x1==x3){
        x4 = x2;
    }else x4 = x1;

    if(yz==y2){
        y4 = y3;
    }else if(yz==y3){
        y4 = y2;
    }else y4 = yz;

    cout<<x4<<" "<<y4;

    cerr << "time elapsed: "<<TIME <<"s.\n";
}
