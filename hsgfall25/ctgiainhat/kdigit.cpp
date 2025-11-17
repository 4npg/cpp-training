// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

string s;
int64 dp[20][20][2];
int64 a,b;
int d,k;

int64 dfs(int pos, int cnt, bool ok, int d, int k){
	if(pos==(int)s.size()){
		return (cnt==k);
	}
	if(dp[pos][cnt][ok]!=-1)return dp[pos][cnt][ok];

	int limit = ok ? (s[pos]-'0'):9;
	int64 res = 0;
	f0(c,0,limit){
		int ncnt = cnt + (c==d);
		if(ncnt>k)continue;
		bool nok = ok && (c==limit);
		res += dfs(pos+1, ncnt, nok, d, k);
	}
	return dp[pos][cnt][ok] = res;
}

int64 calc(int64 x, int d, int k){
	if(x<0)return 0;
	s = to_string(x);
	memset(dp, -1, sizeof(dp));
	return dfs(0,0,1,d,k);
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file("kdigit");
	cin>>a>>b>>d>>k;
	cout<<calc(b,d,k) - calc(a-1,d,k);	

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


