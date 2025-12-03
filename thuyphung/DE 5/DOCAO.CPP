#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr)

const ll maxn = 1e7;
ll d[maxn];

void sang(){
	d[0]=d[1]=1;
	for(ll i=2;i*i<maxn;i++){
		if(d[i]==0){
			for(ll j=i*i;j<maxn;j+=i)d[j]=1;
		}
	}
}

ll sumcs(ll n){
	ll t=0;
	t+=n%10;
	while(n/=10){
		t+=n%10;
	}
	return t;
}
void READFILE(){
    freopen("DOCAO.INP","r",stdin);
    freopen("DOCAO.OUT","w",stdout);
}
int main(){
	fast;READFILE();
	sang();
	ll n,h;cin>>n>>h;
	ll cnt=0;
	for(ll i=2;i<=n;i++){
		if(sumcs(i)==h&&d[i]==0){
			cout<<i<<"\n";cnt++;
		}
	}
	cout<<cnt;
}