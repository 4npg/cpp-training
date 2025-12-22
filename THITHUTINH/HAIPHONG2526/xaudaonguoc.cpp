// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file ""

// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 100005
#define pb push_back
#define all(a) (a).begin(),(a).end()

string s;
int sum;
string ans;

i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>s;
	for(auto &c:s){
		if(c>='0' && c<='9'){
			sum += c-48;
		}else ans.pb(c);
	}

	reverse(all(ans));
	cout<<sum<<'\n';
	if(!ans.empty()){
		cout<<ans;
	}else cout<<-1;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}




