// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file "changhe"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 1
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)

string s;
int cnt[20];

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>s; int n = s.size();
	int sum = 0;
	for(auto &c:s){
		sum += c-'0';
		cnt[c-'0']++;
	}

	if(cnt[0] == 0 || sum%3 != 0){
		return cout<<-1, 0;
	}

	cnt[0]--;
	string ans = "";
	bool f = false;

	for(int d=0; d<=8; d+=2){
		if(cnt[d] == 0)continue;
		cnt[d]--;

		string pre;
		f0(x, 0, 9){
			f0(k, 0, cnt[x]-1){
				pre.push_back('0' + x);
			}
		}

		string ok = pre + char('0'+d) + '0';
		if(!f || ok<ans){
			ans = ok;
			f = 1;
		}
		cnt[d]++;
	}

	cout<<((f)?ans:"-1");
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
