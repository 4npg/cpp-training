// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

int n;
string s;

void xuli(){
	f0(len, 1, n){
		unordered_set<string> st;	
		st.reserve(n);

		for(int i = 0; i+len<=n; ++i){
			st.insert(s.substr(i, len));
		}
		if(st.size() == n-len+1){
			cout<<len<<'\n';
			return;
		}
	}
	cout<<n<<'\n';
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>s;

	xuli();
	

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


