#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "tenbai"
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll (i)=(a);i<=(b);++i)
#define LOCAL

#ifdef LOCAL
  #define dbg(x) do { cerr << "[" << #x << "] = " << (x) << '\n'; } while(0)
#else
  #define dbg(x) do {} while(0)
#endif

ll prime(ll n){
  if(n<2)return false;
  for(ll i=2;i*i<=n;i++)if(n%i==0)return false;
    return true;
}
int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ll n;cin>>n;
    for(ll i=2;i*i<=n;i++){
      if(n%i==0){
        while(n%i==0){
          cout<<i<<" ";
          n/=i;
        }
      }
    }
    if(n>1)cout<<n;
}


