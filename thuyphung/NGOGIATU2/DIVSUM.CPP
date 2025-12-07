// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define pb push_back
int64 x, y;
int cnt;

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>x>>y;

	vector<int> div;

	for(int i=1; i*i<=x; ++i){
		if(x%i==0){
			div.pb(i);
			if(x/i!=i)div.pb(x/i);
		}
	}

	for(auto &a:div){
		if(x%(y-a)==0&&y-a>=1){
			if(a<=(y-a))cnt++;
		}
	}

	cout<<cnt;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


