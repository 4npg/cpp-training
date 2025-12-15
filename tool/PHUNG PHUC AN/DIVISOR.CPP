// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define pb push_back
#define se second

//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

#define maxn 1000006
#define mod 123456789


bool d[maxn];
vector<int> nto;

void sang(){
	d[0] = d[1] = 1;

	for(int i=2; i*i<maxn; ++i){
		if(d[i] == 0){
			for(int j=i*i; j<maxn; j+=i)d[j] = 1;
		}
	}

	for(int i=2; i<maxn; ++i)if(!d[i])nto.pb(i);
}

unordered_map<int64, int64> cntp;

int n;
int64 a[maxn];
int64 num = 1;

i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    file("DIVISOR");

	sang();

	cin>>n;

	f0(i, 1, n){
		int64 x; cin>>x;
		for(int p:nto){
			if(1LL * p * p > x)break;
			if(x%p == 0){
				int64 c = 0;
				while(x%p == 0){
					x /= p;
					c++;
				}
				cntp[p] += c;
			}
		}
		if(x>1)cntp[x]++;
	}

	int64 ans = 1;
	for(auto &x:cntp){
		ans = (ans*(x.se+1))%mod;
	}

	cout<<ans;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


