// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define pb push_back

int n;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file("DBANNER");
	cin>>n;
	vector<int> h(n+1);
	f0(i,1,n)cin>>h[i];	

	h.pb(0);
	stack<int> st;
	int64 mxa = 0;

	f0(i,1,n+1){
		while(!st.empty()&&h[i]<h[st.top()]){
			int hei = h[st.top()];
			st.pop();
			int wid = st.empty()?i-1:i-st.top()-1;
			mxa = max(mxa,1LL*hei*wid);
		}
		st.push(i);
	}

	cout<<mxa;
	
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


