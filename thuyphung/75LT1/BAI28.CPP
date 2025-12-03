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

void solve(ll n,ll &d,ll &m,ll &y){
    n--; // Trừ đi 1 để ngày 1 là 1/1/1
    y = 1;
    while(1){
        ll dy = namnhuan(y) ? 366 : 365;
        if(n >= dy){ 
            n -= dy;
            y++;
        } else break;
    }
    m = 1;
    while(1){
        ll dm = layngay(m,y);
        if(n >= dm){ 
            n -= dm;
            m++;
        } else break;
    }
    d = n + 1; 
}




int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ll n;cin>>n;
    
    ll d,m,y;
    solve(n,d,m,y);
    cout<<d<<"/"<<m<<"/"<<y;

}


