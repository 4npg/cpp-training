s#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
# define ll long long
# define st string
# define endl "\n"
# define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
ll xuli(ll l,ll r,ll x){
	return r/x-((l-1)/x);
}
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int main(){
    fast;
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<b-a+1-(xuli(a,b,c)+xuli(a,b,d)-xuli(a,b,c/gcd(c,d)*d));
}       