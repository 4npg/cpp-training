#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr)

bool xuli(ll n) {
    if (n <= 1) return false;
    ll brk = n;        
    ll sum = 1;        
    for (ll i=2;i*i<=n; ++i) {
        if (n % i == 0) {
            sum += i;
            if (n/i!=i) sum+=n/i;
            if (sum >= brk) 
                return true;
        }
    }
    return sum >= brk;
}
void READFILE(){
    freopen("GHH.INP","r",stdin);
    freopen("GHH.OUT","w",stdout);
}
int main(){
	fast;
	ll t;cin>>t;
	while(t--){
		ll n;cin>>n;
		cout<<(xuli(n)?"1":"0")<<endl;
	}
}