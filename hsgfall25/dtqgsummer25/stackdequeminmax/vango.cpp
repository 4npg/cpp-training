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

#define maxn 1000006

int n;
int64 a[maxn];

i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n;
	f0(i, 0, n-1)cin>>a[i];
	vector<int> l(n+1), r(n+1);
	stack<int> st;

	f0(i, 0, n-1){
		while(!st.empty() && a[st.top()] >= a[i])st.pop();

		l[i] = st.empty() ? 0 : st.top();
		st.push(i);
	}

	while(!st.empty())st.pop();

	fd(i, n-1, 0){
		while(!st.empty() && a[st.top()] >= a[i])st.pop();
		r[i] = st.empty() ? n : st.top();
		st.push(i);
	}
	int64 ans = 0;
	f0(i, 0, n-1){
		int64 res = r[i] - l[i] -1;
		ans = max(ans, min(a[i], res));
	}

	cout<<ans;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}




