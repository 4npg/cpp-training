// authur : anphung >> npkly
#include<bits/stdc++.h>
#define TASK ""
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

bool palin(string s){
	for(int i=0;i<s.size()/2;++i){
		if(s[i]!=s[s.size()-i-1])return false;
	}
	return true;
}

string s;
int ans;
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("CWORD.inp","r",stdin);
	freopen("CWORD.out","w",stdout);
	while(cin>>s){
		ans += (palin(s)?1:0);
	}
	cout<<ans;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}