// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define fi first
#define se second
#define pb push_back 

int n;

string sol(int num){
	string s = to_string(num);
	map<char,int> fq;
	string ch = "";
	int idx = 1;
	for(char c:s){
		if(fq.find(c)==fq.end()){
			fq[c] = idx++;
		}
		ch += to_string(fq[c])+" ";
	}
	return ch;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	//file("DANGCAU");
	cin>>n;
	map<string,vector<int>> gp;
	f0(i,1,n){
		
		//cout<<i<<" "<<sol(i)<<'\n';
		gp[sol(i)].pb(i);
	}
	int ans = 0;
	for(auto &val:gp){
		//cout<<val.fi<<" "<<" "<<val.se[0]<<'\n';
		ans += val.se[0]*val.se.size();
	}
	cout<<ans;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


