// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define f0(i,a,b) for(int (i)=(a);i<=(b);++i)

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    int n; 
    string s;
    cin >> n >> s;
    f0(len,1,n) {
        unordered_set<string> seen;
        bool found = true;
        for (int i = 0; i + len <= n; i++) {
            string sub = s.substr(i, len);
            if (seen.count(sub)) {
                found = false;
                break;
            }
            seen.insert(sub);
        }
        if (found) {
            cout << len;
            return 0;
        }
    }
}
