// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(int (i)=(a);i<=(b);++i)

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    /*
    inp
    869357495356872 9
    out
    335672
    */
    string s;
    int k;
    cin >> s >> k;
    string res;

    for (char c : s) {
        while (!res.empty() && res.back() > c && k > 0) {
            res.pop_back();
            --k;
        }
        res.push_back(c);
    }

    while (k--) res.pop_back();

    int pos = 0;
    while (pos < res.size() && res[pos] == '0') ++pos;
    res = res.substr(pos);

    if (res.empty()) cout << "0";
    else cout << res;
}
