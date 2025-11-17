// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

int64 m,k;
string s;

int64 revpos(int64 pos, int64 m, const string &s){
	for(int i =(int)s.size()-1;~i;i--){
		char c = s[i];

		if(c == 'A'){
			if(pos == m-1)pos = 0;
			else pos = pos + 1;
		}else{
			if(pos==m-1)pos = 1;
			else if(pos==0)pos = 0;
			else pos = pos + 1;
		}
		if(pos>=m)pos-=m;
	}
	return pos;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	cin>>m>>k;	
	cin>>s;

	if(!s.empty() && s.back() == '.')s.pop_back();

	cout<< revpos(k-1,m,s)<<" "<<revpos(k,m,s)<<" "<<revpos(k+1,m,s);

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


