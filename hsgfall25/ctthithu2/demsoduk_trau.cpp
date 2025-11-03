// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "demsoduk"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)

int n,k;
const int maxn = 300006;
int a[maxn];
int cnt[maxn];
void sub1(){
    f0(i,0,n-1){
        //cout<<"so "<<a[i]<<": ";
        f0(j,0,n-1){
            if(i!=j){
                if(a[i] % a[j] == k){
                    cnt[i]++;
          //          cout<<a[i]<<" "<<a[j]<<" "<<'\n';
                }
            }
        }
    }
    f0(i,0,n-1){
        cout<<cnt[i]<<" ";
    }
}



int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".ans","w",stdout);
    cin>>n>>k;
    f0(i,0,n-1){
        cin>>a[i];
    }
    sub1();
    cerr << "time elapsed: "<<TIME <<"s.\n";
}
