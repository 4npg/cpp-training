// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file ""

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 1000006
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)
#define pb push_back

int d[maxn];
string s;
vector<int> a;
void sang(){
	for(int i=2; i*i<maxn; ++i){
		if(d[i] == 0){
			for(int j = i; j<maxn; j+=i){
				if(d[j] == 0)d[j] = i;
			}
		}
	}
}

vector<int> ptich(int x){
	vector<int> res;
	while(x>1){
		int p = d[x];
		res.pb(p);
		while(x%p==0){
			x/=p;
		}
	}
	return res;
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	sang();
	cin>>s;
	int temp = 0;
	for(auto &c:s){
		if(isdigit(c)){
			temp = temp * 10 + c-48;
		}else{
			if(temp>0)a.pb(temp);
			temp = 0;
		}
	}

	if(temp>0)a.pb(temp);

	int l = 0;
	int sz = a.size()-1;
	int ans = 0;
	map<int,int> cnt;
	vector<vector<int>> fac(sz+1);

	f0(i, 0, sz){
		fac[i] = ptich(a[i]);
	}

	// for(auto &v:fac){
	// 	for(auto &x:v){
	// 		cout<<x<<" ";
	// 	}
	// 	cout<<'\n';
	// }

	f0(r, 0, sz){
		bool f = true;
		while(f){
			f = false;
			for(int p:fac[r]){
				if(cnt[p] == 1){
					for(int q:fac[l]){
						cnt[q]--;
					}
					l++;
					f = true;
					break;
				}
			}
		}
		for(int p:fac[r]){
			cnt[p]++;
		}
		ans = max(ans, r-l+1);
	}

	cout<<ans;
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
