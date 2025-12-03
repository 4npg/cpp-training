#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "tenbai"
#define nl cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll (i)=(a);i<=(b);++i)


int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    string s;
    cin >> s;
    unordered_set<string> subs;
    ll n = s.size();
    for (ll i = 0; i < n; ++i) {
        string t = "";
        for (ll j = i; j < n; ++j) {
            t += s[j];
            subs.insert(t);
        }
    }
    cout << subs.size();
}


