#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "NTMAX"
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll (i)=(a);i<=(b);++i)


const ll maxn = 1e7*1ll;
bitset<maxn> d;

void sang(){
	d[0]=d[1]=1;
	for(ll i=2;i*i<maxn;i++){
		for(ll j=i*i;j<maxn;j+=i){
			d[j]=1;
		}
	}
}


int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    sang();
    string s;
    cin>>s;
    ll cntDigit=0;
    ll maxans = LLONG_MIN;
    FOR(i,0,s.size()-1){
    	if(isdigit(s[i])){
    		ll temp = 0;
			while(isdigit(s[i])){
				temp=temp*10+s[i]-48;

				maxans = max(maxans,((d[temp]==0)?temp:0));
				i++;
				cntDigit++;
			}
			i--;
		}    	
    }
    cout<<cntDigit<<endl<<maxans;
}


