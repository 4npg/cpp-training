#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "CAU3"
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll (i)=(a);i<=(b);++i)
#define LOCAL

#ifdef LOCAL
  #define dbg(x) do { cerr << "[" << #x << "] = " << (x) << '\n'; } while(0)
#else
  #define dbg(x) do {} while(0)
#endif

bool d[26];
int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    string s;cin>>s;
    ll res=0;
    for(auto c:s){
        ll idx = c-'a';
        if(d[idx]){
          res++;
          fill(d,d+26,false);
        }
        d[idx] = true;
    }

    for(ll i=0;i<26;i++){
      if(d[i]){
        res++;
        break;
      }
    }
    cout<<res;
}


