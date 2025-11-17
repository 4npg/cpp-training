// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

int n,cnt;

bool ok (int64 x){
	string s = to_string(x);
	if(s.size()<2)return false;
	f0(i,1,(int)s.size()-1){
		if(s[i]<s[i-1])return false;
	}
	return true;
}


int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file("STEP");
	cin>>n;
	f0(i,0,n-1){
		int64 x;cin>>x;
		if(ok(x))cnt++;
	}

	cout<<cnt;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


