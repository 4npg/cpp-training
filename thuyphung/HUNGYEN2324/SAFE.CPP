#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "SAFE"
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll (i)=(a);i<=(b);++i)
#define LOCAL

#ifdef LOCAL
  #define dbg(x) do { cerr << "[" << #x << "] = " << (x) << '\n'; } while(0)
#else
  #define dbg(x) do {} while(0)
#endif


int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ll n;cin>>n;
    string s;cin>>s;

    ll res = 0;
    ll cntUpper = 0, cntLower = 0, cntDigit = 0;
    ll j = 0;

    for (ll i = 0; i < n; ++i) {
        
        while (j < n && (j - i < 6 || cntUpper == 0 || cntLower == 0 || cntDigit == 0)) {
            if (isupper(s[j])) cntUpper++;
            else if (islower(s[j])) cntLower++;
            else if (isdigit(s[j])) cntDigit++;

            j++;
        }
        if (j - i >= 6 && cntUpper > 0 && cntLower > 0 && cntDigit > 0)res += n - j + 1;

        if (isupper(s[i])) cntUpper--;
        else if (islower(s[i])) cntLower--;
        else if (isdigit(s[i])) cntDigit--;

        //cout<<"res = "<<res<<", i = "<<i<<", j = "<<j<<endl;
    }
    cout<<res;
}


