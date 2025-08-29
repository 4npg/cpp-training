// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(int (i)=(a);i<=(b);++i)
#define all(a) (a).begin(),(a).end()

int n;
bool cmp(string &a,string &b){
	return a+b>b+a;
}
int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    cin>>n;
    vector<string> num(n);
    FOR(i,0,n-1)cin>>num[i];
    sort(all(num),cmp);
    for(auto &s:num)cout<<s;
}


