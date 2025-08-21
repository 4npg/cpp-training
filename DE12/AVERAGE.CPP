#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define el cout<<'\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define f0(i,a,b) for(int (i)=(a);i<=(b);++i)
int n,k;
double sum=0,mx=-1e9;
const int maxn = 1e6+5;
double a[maxn];
void trau(){
    f0(i,0,n-1){
        cin>>a[i];
        mx =max(mx,a[i]);
    }
    if(k==1){
        cout<<fixed<<setprecision(3)<<mx;
        exit(0);
    }else{
        mx = -1e9;
    }
    f0(i,0,n-k){
        sum=a[i];
        //cout<<"i = "<<i<<", n-k-1 = "<<n-k-1;;
        // el;
        f0(j,i+1,n-1){
            sum+=a[j];
            if(j-i+1>=k){
                mx = max(mx,sum/(double)(j-i+1));
                // for(int g = i;g<=j;g++){
                //     cout<<a[g]<<" ";
                // }
                // cout<<"j ="<<j<<" max avg = "<<mx<<" "<<"len = "<<j-i+1;
                // el;
            }
        }
    }
    cout<<fixed<<setprecision(3)<<mx;
}

void AC(){
    
}
int main() {
    fast;
    cin>>n>>k;
    trau();
    el;
    AC();
}