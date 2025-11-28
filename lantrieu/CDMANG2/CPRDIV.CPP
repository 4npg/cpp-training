// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 1000006
#define pb push_back

int n,m;
bool d[maxn];

void sang(){
	d[0] = d[1] = 1;

	for(int i=2; 1ll*i*i<n; i++){
		if(d[i] == 0){
			for(int j = i; j<maxn; j+=i)d[j] = 1;
		}
	}
}

int legendre(int n, int p){
	int cnt = 0;
	while(n){
		cnt+=n/p;
		n/=p;
	}
	return cnt;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>m;	

	vector<int> nto;
	f0(i,2,n){
		if(!d[i])nto.pb(i);
	}

	int ans = 0;
	for(auto &p:nto){
		int exp = legendre(n, p) - legendre(m, p) - legendre(n-m, p);
		ans += ((exp>0)?1:0);
	}
	cout<<ans;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


