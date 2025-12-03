#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "tenbai"
#define nl cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(a,b) for(ll i=(a);i<=(b);++i)

bool namnhuan(ll y){
	return (y%400==0||(y%100!=0&&y%4==0));
}

ll layngay(ll m,ll y){
	if(m==2)return(namnhuan(y)?29:28);
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)return 31;
	return 30;	
}
ll tinhngay(ll d,ll m,ll y){
	ll total = 0;
	for(ll i=1;i<y;i++){
		total += (namnhuan(i)?366:365);
	}
	for(ll mon = 1;mon<m;mon++){
		total += layngay(mon,y);
	}
	return (total +=d);
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ll d,m,y;cin>>d>>m>>y;
    cout<<tinhngay(d,m,y);

}


