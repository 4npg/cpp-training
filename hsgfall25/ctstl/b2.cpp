// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(int (i)=(a);i<=(b);++i)

int n;

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    cin>>n;
    map<int,int> a;
    while(n--){
    	string s;
    	int num;
    	cin>>s;
    	if(s!="size"){
    		cin>>num;
    		if(s=="add"){
    			a[num]++;
    		}else if(s=="count"){
    			cout<<((a.count(num)?a[num]:0));el;
    		}else if(s=="del"){
    			if(a.count(num)>=1){
    				a.erase(num);
    			}
    		}
    	}else{
    		cout<<a.size();el;
    	}
    }

}


