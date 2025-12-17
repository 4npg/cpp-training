// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 1000000000
#define bit(mask, i) (mask&(1<<i))

string n;
int64 ans = -1;  

bool nto(int64 n){
	if(n<2)return false;
	if(n == 2 || n == 3)return true;
	if(n%2 == 0 || n%3 == 0)return false;

	for(int i=5; i*i<=n; i+=6){
		if(n%i == 0 || n%(i+2) == 0)return false;
	}
	return true;
}

i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n;
	int sz = n.size();

	f0(mask, 1, (1<<sz)-1){
		string t = "";
		f0(i, 0, sz-1){
			if(bit(mask, i)){
				t+=n[i];
			}
		}

		if(t.size() > 1 && t[0] == '0')continue;

		int64 val = stoll(t);
		if(nto(val))ans = max(ans, val);
	}

	cout<<ans;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}




