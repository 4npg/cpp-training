#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr)
const ll maxn = 1e7;
ll a[maxn];
ll b[maxn];
ll n;
void ac(){
    sort(a,a+n);sort(b,b+n);
    ll res = oo;
    ll i=0,j=n-1;
    while(i<n&&j>=0){
        res=min(res,abs(a[i]+b[j]));
        if(a[i]+b[j]<0)i++;
        else j--;
    }
    cout<<res;
}
void READFILE(){
    freopen("TROCHOI.INP","r",stdin);
    freopen("TROCHOI.OUT","w",stdout);
}
int main() {
	fast;READFILE();
    cin >> n;
    for(ll i=0;i<n;i++)cin>>a[i];
    for(ll i=0;i<n;i++)cin>>b[i];
    ac();
}
