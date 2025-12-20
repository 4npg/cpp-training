// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file "MARK"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 90

string s;

youngboiz_nobug(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>s;

	int cnt = (s[0] == 'D'?1:0);
	int res = cnt;
	for(int i=1; i<s.size(); ++i){
		if(s[i] == s[i-1] && s[i] == 'D'){
			cnt++;
		}else if(s[i] == 'D'){
			cnt = 1;
		}
		else{
			cnt = 0;
		}

		//cout<<s[i]<<" "<<cnt<<'\n';
		res += cnt;
	}

	cout<<res;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}
