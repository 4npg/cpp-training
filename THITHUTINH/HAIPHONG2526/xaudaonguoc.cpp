// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

string xau;
int sum;
string s = "";

i_love_Hoang_Ngan(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>xau;

	for(auto &c:xau){
		if((c>='0'&&c<='9'))sum+=c-48;
		else s+=c;
	}

	if(s==""){
		cout<<sum<<'\n';
		cout<<-1;
		return 0;
	}
	cout<<sum<<'\n';
	for(int i=s.size()-1; ~i; i--){
		cout<<s[i];
	}

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


