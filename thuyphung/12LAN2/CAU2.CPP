// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define fi first
#define se second

string s;

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	getline(cin, s);
	map<char, int> mp;

	for(auto &c: s){
		c = tolower(c);
		if((c>='a'&&c<='z')){
			mp[c]++;
		}
	}	

	for(auto &val:mp){
		cout<<val.fi<<" "<<val.se<<'\n';
	}

	cerr << "time elapsed: "<<TIME <<"s.\n";
}





