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
#define pb push_back
#define fi first 
#define se second
int t;
i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>t;
	while(t--){
		int n; cin>>n;
		int64 a[maxn];
		f0(i, 1, n)cin>>a[i];

		stack< pair<int64, int> > st;
		vector<int64> ans(n+1, 0);

		f0(i, 1, n){
			int64 h = a[i];
			while(!st.empty() && st.top().fi < h)st.pop();

			if(st.empty()){
				st.push({h, 1});
			}else if(st.top().fi == h){
				int cnt = st.top().se;
				st.pop();

				ans[i] += cnt;
				st.push({h, cnt+1});
			}else{
				st.push({h, 1});
			}
		}

		while(!st.empty()) st.pop();

		fd(i, n, 1){
			int64 h = a[i];
			while(!st.empty() && st.top().fi < h)st.pop();

			if(st.empty()){
				st.push({h, 1});
			}else if(st.top().fi == h){
				int cnt = st.top().se;
				st.pop();

				ans[i] += cnt;
				st.push({h, cnt+1});
			}else{
				st.push({h, 1});
			}
		}

		f0(i, 1, n)cout<<ans[i]<<" ";
		cout<<'\n';
	}

	cerr << "time elapsed: "<<TIME <<"s.\n";
}




