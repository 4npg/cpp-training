// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file ""

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//long long Rand(long long l, long long r){
//	return l+rng()%(r-l+1);
//}

#define maxn 1
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int n;

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n;
	int s0 = 0, s1 = 0, s2 = 0;

	f0(i, 0, n-1){
		string type, name;
		cin>>type>>name;

		if(type == "section"){
			s0++; s1 = s2 = 0;
			cout<<s0<<" "<<name<<"\n";
		}else if(type == "subsection"){
			s1++;
			s2 = 0;
			cout<<s0<<"."<<s1<<" "<<name<<'\n';
		}else{
			s2++;
			cout<<s0<<"."<<s1<<"."<<s2<<" "<<name<<'\n';
		}
	}
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
