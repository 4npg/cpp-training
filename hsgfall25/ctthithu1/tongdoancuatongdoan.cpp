// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}

const int maxn = 3e5+5;
int n,q;
int64 a[maxn];
int64 pref[maxn];
int64 pref2[maxn];
int64 endblk[maxn],blocksum[maxn],blockpref[maxn];

int64 tong(int64 k){
    if(k<=0)return 0;
    int i = int(lower_bound(endblk+1,endblk+n+1,k)-endblk);
    int64 res = blockpref[i-1];
    int64 rem = k-endblk[i-1];
    if(rem>0)res+=(pref2[i+rem-1]-pref2[i-1]) - rem * pref[i-1];
    return res;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    f0(i,1,n){
        cin>>a[i];
        pref[i] = pref[i-1] + a[i];
        pref2[i] = pref2[i-1] + pref[i];
    }

    f0(i,1,n){
        endblk[i] = endblk[i-1] + (n-i+1);
        blocksum[i] = (pref2[n]-pref2[i-1]) - (int64)(n-i+1)* pref[i-1];
        blockpref[i] = blockpref[i-1] + blocksum[i];
    }

    cin>>q;
    while(q--){
        int64 l,r;
        cin>>l>>r;
        cout<<tong(r)-tong(l-1)<<'\n';
    }
    cerr << "time elapsed: "<<TIME <<"s.\n";
}


