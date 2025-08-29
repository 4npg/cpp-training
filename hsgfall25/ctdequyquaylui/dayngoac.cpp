// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define f0(i,a,b) for(int (i)=(a);i<=(b);++i)
#define pb push_back
#define pob pop_back
int n;
string curst;
vector<string>res;
void Try(int op,int cl){
	if(op==n&&cl==n){
		res.pb(curst);
		el;
		return;
	}
	if(op<n){
		curst.pb('(');
		Try(op+1,cl);
		curst.pob();
	}
	if(cl<op){
		curst.pb(')');
		Try(op,cl+1);
		curst.pob();
	}
}
int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    cin>>n;
    res.clear();
    Try(0,0);
    cout<<res.size();
    el;
    for(auto &x:res){
    	cout<<x;
    	el;
    }
}


