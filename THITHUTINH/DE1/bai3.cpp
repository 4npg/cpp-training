// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "bai3"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define maxn 500005
#define pb push_back

int n;
int64 a[maxn];
int64 mxa=LLONG_MIN;
int mxa_index;

void sub1(){
    int cnta = 0;
    f0(i,0,mxa_index-1){
        f0(j,0,mxa_index-1){
            if(a[i]>a[i+1]){
                swap(a[i],a[i+1]);
                i=0;
                cnta++;
            }
        }
    }
    int cntb = 0;
    f0(i,mxa_index,n-1){
        f0(j,mxa_index,n-1){
            if(a[i]<a[i+1]){
                swap(a[i],a[i+1]);
                i = mxa_index;
                cntb++;
            }
        }
    }

    cout<<cnta+cntb;

}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    // freopen(file".out","w",stdout);

    cin>>n;
    f0(i,0,n-1){
        cin>>a[i];
        if(mxa<a[i]){
            mxa = a[i];
            mxa_index = i;
        }
    }

    sub1();
    cout<<'\n';
    sub2();
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
