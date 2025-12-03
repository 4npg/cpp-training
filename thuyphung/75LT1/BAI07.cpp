#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
# define ll long long
# define pb push_back
# define endl "\n"
# define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
int main(){
    fast;
    ll n;cin>>n;
    vector<ll> a(n);
    ll tcm = 0;
    for(ll i=0;i<n;i++){
    	cin>>a[i];
    	tcm+=a[i];
    }
    if(tcm==0){
    	cout<<n<<"\n";
    	for(ll i=1;i<=n;i++)cout<<i<<" ";
    }else{
	    for(ll k=n;k>=1;k--){
	    	if(tcm%k!=0)continue;
	    	ll tdc = tcm/k;
	    	ll tmp = 0,dem=0;
	    	vector<ll> pos;
	    	for(ll i=0;i<n;i++){
	    		tmp+=a[i];
	    		if(tmp==tdc){
	    			if(i==n-1||a[i+1]!=0){
	    				dem++;
	    				pos.pb(i+1);tmp=0;
	    			}
	    		}else if(tmp>tdc)break;
	    	}
	    	if(dem==k){
	    		cout<<dem<<"\n";
	    		for(auto x:pos)cout<<x<<" ";
	    			return 0;
	    	}
	    }
	}
}       