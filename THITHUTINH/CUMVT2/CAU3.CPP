// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define pb push_back

string s;

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>s;
	int n = s.size();
	int ans = 1;
	for(char c = 'a'; c<='z'; c++){
		vector<int> p(n+1, 0);
		f0(i, 1, n){
			p[i] = p[i-1] +(s[i-1] == c? 1 : -1);
		}
		vector<int> st;
		f0(i, 0, n){
			if(st.empty() || p[i] < p[st.back()])
				st.pb(i);
		}

		for(int r=n; ~r; r--){
			while(!st.empty() && p[st.back()] < p[r]){
				ans = max(ans, r-st.back());
				st.pop_back();
			}
		}
	}
	cout<<ans;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


