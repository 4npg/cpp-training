// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(int (i)=(a);i<=(b);++i)
#define pb push_back

int n;
const int maxn = 1e6+5;
int64 a[maxn];


int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    cin>>n;
    map<int64,vector<int>> xuathien;
    FOR(i,1,n){
    	cin>>a[i];
    	xuathien[a[i]].pb(i);
    }
    for(auto v:xuathien){
    	cout<<v.first;
    	el;
    	for(auto x:v.second){
    		cout<<x<<" ";
    	}
    	el;
    }
}


