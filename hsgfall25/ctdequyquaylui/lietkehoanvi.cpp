// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define f0(i,a,b) for(int (i)=(a);i<=(b);++i)
#define all(a) (a).begin(),(a).end()

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    int n;cin>>n;
    vector<int> s(n);
    f0(i,0,n-1)s[i] = i+1;
    do{
    	for(auto &x:s)cout<<x;
 		el;
    }while(next_permutation(all(s)));
}


