// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file "CTRIA"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 1000006

int n;
int64 a[maxn];

youngboiz_nobug(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n;
	f0(i, 0, n-1)cin>>a[i];

	multiset<int64> s;
	int l = 0;
	int64 ans = 1;
	f0(r, 0, n-1){
		s.insert(a[r]);

		while(s.size() >= 3){
			auto it = s.begin();
			int64 min1 = *it;
			it++;
			int64 min2 = *it;
			int64 mx = *s.rbegin();
			if(min1 + min2 > mx)break;
			s.erase(s.find(a[l]));
			l++;
		}
		ans = max(ans, 1ll*s.size());
	}

	cout<<ans;

	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
