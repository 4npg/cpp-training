#include <bits/stdc++.h>
#define ll long long
#define name "WATERFILL"
#define For(i,a,b,c) for(ll i=a;i<=b;i+=c)
#define Fod(i,b,a,c) for(ll i=b;i>=a;i-=c)
#define inf int(1e9+5)
#define Nmax int(1e5+5)
#define faster ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
ll s,a[Nmax];
ll n,k;
ll res;
ll t;
void input()
{
    cin>>n>>k;
    For(i,1,n,1)
    {
        cin>>a[i];
        s+=a[i];
    }
    //t=s/n/k;
    t=max(s/n/k,a[1]/k);
    //if(*max_element(a+1,a+1+n)==a[1]) t=a[1]/k; /// :))
}
bool check(ll t)
{
    ll f[Nmax]={0};
    For(i,1,n,1)
    {
        if(t*k+f[i]>=a[i])
        {
            f[i+1]=t*k+f[i]-a[i];
            f[i]=a[i];
        }
        else return 0;
    }
    return 1;
}
void output()
{
    while(!check(t)) t++;
    cout<<t;
}

int main()
{
    freopen(name".inp","r",stdin);
    freopen(name".ans","w",stdout);
    faster
    input();
    output();
    return 0;
}
