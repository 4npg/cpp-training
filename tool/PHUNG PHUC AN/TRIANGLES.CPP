// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 5010
#define pb push_back
#define fi first 
#define se second

int n;
vector<int64> b;
vector<int> cnt;

i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	file("TRIANGLES");
	cin>>n;
	map<int64, int> mp;
	f0(i, 0, n-1){
		int64 x; cin>>x;
		mp[x]++;
	}	

	for(auto &p:mp){
		b.pb(p.fi);
		cnt.pb(p.se);
	}

	int k = b.size();
	int64 ans = 0;
	f0(i, 0, k-1){
		if(cnt[i] >= 3)ans++;
	}

	f0(j, 0, k-1){
		f0(i, 0, j-1){
			if(cnt[i] >= 2 && 2*b[i] > b[j])ans++;
		}
	}

	f0(j, 0, k-1){
		if(cnt[j] >= 2){
			ans += j;
		}
	}

	f0(z, 0, k-1){
		int l = 0, r = z-1;
		while(l<r){
			if(b[l] + b[r] > b[z]){
				ans += (r-l);
				r--;
			}else l++;
		}
	}
	cout<<ans;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}
