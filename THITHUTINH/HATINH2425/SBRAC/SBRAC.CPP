// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file "SBRAC"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 12

string s;

youngboiz_nobug(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);

	cin>>s;
	int n = s.size();

	int cl = 0, q = 0;
	for(char c:s){
		if(c == ')')cl++;
		if(c == '?')q++;
	}

	int bal = 0, ma = 0;
	int rcl = cl;
	int rq = q;

	for(char c:s){
		if(c == '('){
			bal++;
		}else if(c == ')'){
			bal--;
			rcl--;
		}else {
			if(bal + 1 <= rcl + rq -1){
				bal++;
				rq--;
			}else{
				bal--;
				rq--;
			}
		}
		if(bal < 0){
			cout<<0;
			return 0;
		}
		ma = max(ma, bal);
	}

	if(bal != 0){
		cout<<0;
		return 0;
	}
	cout<<ma;
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
