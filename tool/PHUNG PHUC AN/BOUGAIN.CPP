// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 100005

string s;
void sub1(){

	int cnt = 0;
	char ls1 = 0;
	char ls2 = 0;

	for(char c:s){
		if(cnt<2){
			cnt++;
			ls2 = ls1;
			ls1 = c;
		}else{
			if(c!=ls1 && c!=ls2 && ls1!=ls2){
				cnt++;
				ls2 = ls1;
				ls1 = c;
			}
		}
	}

	cout<<cnt;	
}

void sub2(){
	vector<string> perm = {"WRY", "WYR", "RYW", "RWY", "YRW", "YWR"};
	int cnt = 0;

	for(auto &x:perm){
		int pos = 0;
		int d = 0;
		for(char c:s){
			if(c == x[pos]){
				++d;
				pos = (pos+1)%3;
			}
		}
		cnt = max(cnt, d);
	}
	cout<<cnt;
}
i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	file("BOUGAIN");
	cin>>s;	

	sub2();
	
	cerr << "time elapsed: "<<TIME <<"s.\n";
}
