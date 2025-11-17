// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define pb push_back
#define pof pop_front
int n;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file("BKID");
	cin>>n;
	vector<int64> a(n+1);
	f0(i,1,n)cin>>a[i];
	
	deque<int> st;
	f0(i,1,n)st.pb(i);

	f0(luot,1,n-1){
		int x = st.front();st.pof();
		int y = st.front();st.pof();

		if(a[x]>a[y]){
			cout<<x<<'\n';
			st.push_front(y);
		}else {
			cout<<y<<'\n';
			st.push_front(x);
		}
	}

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


