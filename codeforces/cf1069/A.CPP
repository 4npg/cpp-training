// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

int t;

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>t;
	while(t--){
		int n; cin>>n;

		set<int> st;
		f0(i, 0, n-1){
			int x; cin>>x;
			st.insert(x);
		}

		int cur = st.size();

		while(!st.count(cur)){
			st.insert(cur);
			cur++;
		}

		cout<<cur<<'\n';
	}

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


