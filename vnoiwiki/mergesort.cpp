// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file ""
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)

int n,m;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    f0(i,0,n-1){
        cin>>a[i];
    }

    f0(i,0,m-1){
        cin>>b[i];
    }

    int i = 0;
    int j = 0;

    while(i<n&&j<m){
        if(a[i]<=b[j]){
            cout<<a[i]<<" ";
            i++;
        }else {
            cout<<b[j]<<" ";
            j++;
        }
    }

    while(i<n){
        cout<<a[i]<<" ";
        i++;
    }

    while(j<m){
        cout<<b[j]<<" ";
        j++;
    }

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
