#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define file "BAI3"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);
    string s;
    cin >> s;
    vector<char> lis;

    for(char x : s){
        auto it = upper_bound(lis.begin(), lis.end(), x);
        if(it == lis.end()) lis.push_back(x);
        else *it = x;
    }

    cout << lis.size();
}
