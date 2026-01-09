// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file "erasechar"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//long long Rand(long long l, long long r){
//	return l+rng()%(r-l+1);
//}

#define maxn 2005
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int k, n;
string s;

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>k>>s;

	int L = n-k;
	if(L <= 0){
		return cout<<"No", 0;
	}

	for(int l = 0; l+L-1<n; ++l){
		int r = l+L-1;
		int i=l, j=r;
		bool ok = true;
		while(i<j){
			if(s[i] != s[j]){
				ok = false;
				break;
			}
			++i, --j;
		}
		if(ok){
			return cout<<s.substr(l, L), 0;
		}
	}

	cout<<"No";
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
