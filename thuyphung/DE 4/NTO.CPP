#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define ll long long
ll t;
ll cnt(ll x){
	ll d=0;
	for(ll i=1;i*i<=x;i++){
		if(x%i==0){
			d++;
			if(x/i!=i)d++;
		}
	}
	return d;
}
void ptich(ll n){
	ll check=0;
	for(ll i=2;i*i<=n;i++){
		while(n%i==0){
			if(n/i==1)cout<<i<<" ";
			else cout<<i<<"*";
			n/=i;
		}
	}
	if(n>1)cout<<n<<" ";
}
void READFILE(){
	freopen("NTO.INP","r",stdin);
	freopen("NTO.OUT","w",stdout);
}
int main(){
	fast;
	cin>>t;
	for(ll i=0;i<t;i++){
		ll x;cin>>x;
		cout<<cnt(x)<<" ";
		ptich(x);
		cout<<'\n';
	}
}
