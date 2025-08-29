// author : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout << "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i, a, b) for (int (i) = (a); i <= (b); ++i)
#define pb push_back
#define pob pop_back

int n;

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    cin >> n;
    vector<int> a;
    while (n--) {
        string s;
        cin >> s;
        if (s=="push") {
            int num;
            cin>>num;
            a.pb(num);
        } else if(s=="index"){
            int num;
            cin>>num;
            if (num>a.size()||num<=0){
                cout<<"-1";el;
            } else {
                cout<<a[num-1];el;
            }
        }else if(s=="size"){
            cout<<a.size();el;
        } else if(s=="pop"){
            if(!a.empty())a.pob();
        }
    }
}
