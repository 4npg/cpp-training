#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
# define ll long long
# define st string
# define endl "\n"
# define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
int main(){
    fast;
    ll a,b;cin>>a>>b;
    cout<<max(a,b)+(a>b?a-1:b-1);
}       