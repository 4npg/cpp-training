#include <bits/stdc++.h>
using namespace std;
# define ll  long long
# define pb push_back
# define endl "\n"
# define oo 1e18
# define fast ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
const ll maxn = 1e7;
void READFILE(){
	freopen("CAU1.inp","r",stdin);
	freopen("CAU1.out","w",stdout);
}
ll a[maxn];
int main(){
	fast;READFILE;
	ll n;cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	ll res = 1,len = 1 ;
	for(ll i=0;i<n-1;i++){
		if(a[i]<=a[i+1])len++;
		else len = 1;
		res = max(res,len);
	}
	cout<<res;
}