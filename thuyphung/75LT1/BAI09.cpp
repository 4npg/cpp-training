#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
# define ll long long
# define st string
# define endl "\n"
# define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
void READFILE(){
    freopen("INP.TXT","r",stdin);
    freopen("OUT.TXT","w",stdout);
}
int main(){
    fast;
    ll n;cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++)cin>>a[i];
    for(ll i=0;i<n;i++){
    	ll d=0;
    	for(ll j=0;j<i;j++)if(a[j]>a[i])d++;
    	cout<<d<<" ";
    }
}       