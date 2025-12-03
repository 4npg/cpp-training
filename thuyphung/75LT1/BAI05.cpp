#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
# define ll long long
# define oo 1e18
# define endl "\n"
# define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
void READFILE(){
    freopen("INP.TXT","r",stdin);
    freopen("OUT.TXT","w",stdout);
}

int main(){
    fast;
    ll n;cin>>n;
    vector<ll> prx(n);
    cin>>prx[0];
    for(ll i=1;i<n;i++){
        ll x;cin>>x;
        prx[i] = prx[i-1]+x;
    }
    ll res = oo;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){

            ll sub;
            if(i<=j){
                sub = prx[j]-(i==0?0:prx[i-1]);
            }else{
                sub = prx[n-1]-(i==0?0:prx[i-1])+prx[j];
            }
            res = min(sub,res);
        }

    }
    cout<<res;
}       