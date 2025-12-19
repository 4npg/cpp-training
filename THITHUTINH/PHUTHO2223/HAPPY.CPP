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

#define maxn (int64)1e18
#define mod (int64)(1e9+7)
#define pb push_back 

int64 n;
int ans = 0;

bool valid(const string &s){
	int mood = 1;
	for(auto &c:s){
		if(c == 'S' || c == 'D')mood = 1;
		else if(c == 'H')mood = 0;
		else if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')mood ^= 1;
	}
	return mood == 1;
}

void Try(string &s){
	if((int)s.size() == n){
		if(valid(s))ans++;
		return;
	}

	for(auto c = 'A'; c <= 'Z'; c++){
		s.pb(c);
		Try(s);
		s.pop_back();
	}
}

void sub1(){
	string s = "";
	Try(s);
	cout<<ans%mod;
}

struct Mat{
	int64 a[2][2];
};

Mat mul(Mat x, Mat y){
	Mat r{};
	f0(i, 0, 1){
		f0(j, 0, 1){
			f0(k, 0, 1){
				r.a[i][j] = (r.a[i][j] + x.a[i][k] * y.a[k][j])%mod;
			}
		}
	}
	return r;
}

Mat mpow(Mat base, int64 e){
	Mat res{};
	res.a[0][0] = res.a[1][1] = 1;
	while(e){
		if(e&1)res = mul(res, base);
		base = mul(base, base);
		e>>=1;
	}
	return res;
}
i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n;
	if(n==1){
		cout<<19;
		return 0;
	}
	Mat M{};
	M.a[0][0] = 20; M.a[0][1] = 7;
	M.a[1][0] = 6; M.a[1][1] = 19;

	Mat R = mpow(M, n);

	cout<<R.a[0][0];
	
	cerr << "time elapsed: "<<TIME <<"s.\n";
}
