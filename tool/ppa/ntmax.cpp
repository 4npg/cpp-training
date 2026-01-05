// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file "ntmax"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 100000007
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)

bool d[maxn];

void sang(){
	for(int i=2; i*i<maxn; i++){
		if(!d[i]){
			for(int j=i*i; j<maxn; j+=i)d[j] = 1;
		}
	}
}

string s;
vector<int> po;

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);

	sang();

	cin>>s;
	int cur = 0;
	int cnt = 0;
	int ans = 0;
	if(isdigit(s[s.size()-1]))s = s + 'a';

	for(int i=0; i<s.size(); i++){
		if(isdigit(s[i])){
			cur = cur*10+s[i]-'0';
			cnt++;
		}else{
			if(cur>0)po.emplace_back(cur);
			cur = 0;
		}
	}

	for(auto &p:po)if(!d[p])ans = max(ans, p);

	cout<<cnt<<'\n'<<ans;
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
