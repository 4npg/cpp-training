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
string cur_string;

void Try(int pos){
	if(cur_string.size()==n){
		cout<<cur_string;
		el;
		return;
	}
	for(char i='0';i<='2';++i){
		cur_string.pb(i);
		Try(i+1);
		cur_string.pob();
	}
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    cin>>n;
    cur_string = "";
    Try(0);
}


