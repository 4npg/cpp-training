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

#define maxn 1000000009
#define pb push_back

int64 l, r;

int dit(int64 x){
	int d = 0;
	while(x){
		d++;
		x/=10;
	}
	return d;
}

void sub1(){
	vector<int64> res;

	for(int64 n = l; n <= r; ++n){
		int d = dit(n);
		int64 sq = n*n;
		int64 base = 1;
		f0(i, 0, d-1)base*=10;

		int64 ri = sq%base;
		int64 le = sq/base;

		if(le + ri == n)res.pb(n);
	}

	cout<<res.size()<<'\n';

	for(int64 x:res)cout<<x<<", ";
}

void sub2(){

	vector<int64> kap = {1, 9, 45, 55, 99, 297, 703, 999, 2223, 2728, 4950, 5050, 7272, 7777, 9999, 17344, 22222, 77778, 82656, 95121, 99999, 142857, 148149, 181819, 187110, 208495, 318682, 329967, 351352, 356643, 390313, 461539, 466830, 499500, 500500, 533170, 538461, 609687, 643357, 648648, 670033, 681318, 791505, 812890, 818181, 851851, 857143, 961038, 994708, 999999, 4444444, 4927941, 5072059, 5555556, 9372385, 9999999, 11111112, 13641364, 16590564, 19273023, 19773073, 24752475, 25252525, 30884184, 36363636, 38883889, 44363341, 44525548, 49995000, 50005000, 55474452, 55636659, 61116111, 63636364, 69115816, 74747475, 75247525, 80226927, 80726977, 83409436, 86358636, 88888888, 91838088, 94520547, 99999999, 234567901, 332999667, 432432432, 567567568, 667000333, 765432099, 999999999};

	vector<int64> res;
    for(int64 x : kap)
        if(l <= x && x <= r)
            res.pb(x);

    cout << res.size() << '\n';
    for(int64 x : res) cout << x << " ";

}

i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>l>>r;
	sub2();
	cerr << "time elapsed: "<<TIME <<"s.\n";
}
