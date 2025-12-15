// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 100005

int n, q;
int64 a[maxn];
int dp[maxn];

i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>q;
	f0(i, 0, n-1)cin>>a[i];

	stack<int> st;
	vector<int> nxt(n+1);

	fd(i, n-1, 0){
		while(!st.empty() && a[st.top()] <= a[i])st.pop();
		nxt[i] = st.empty() ? 0 : st.top();

		st.push(i);
	}

	fd(i, n-1, 0){
		if(nxt[i] == 0)dp[i] = 0;
		else dp[i] = dp[nxt[i]] + 1;
	}

	while(q--){
		int x; cin>>x;
		cout<<dp[x-1]<<'\n';
	}


	cerr << "time elapsed: "<<TIME <<"s.\n";
}




