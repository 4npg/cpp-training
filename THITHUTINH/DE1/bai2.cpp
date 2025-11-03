// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "bai2"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)

int s,a,b,h,m;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    // freopen(file".out","w",stdout);

    cin>>s>>a>>b>>h>>m;

    int bd = h*60+m;
    h = 8;
    m = 0;
    int i = 0;
    int kt=0;
    int tg=0;

    while(i<12){
        i++;

        m+=s;
        if(m>=60){
            m-=60;
            h++;
        }
        kt = h*60+m;
        tg = kt-bd;

        if(i==3||i==9){
            m+=b;
        }else m+=a;

        if(m>=60){
            m-=60;
            h++;
        }

        if(tg>=0){
            if(tg==0){
                cout<<"NOW";
                break;
            }else {
                cout<<tg;
                break;
            }

        }
    }

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
