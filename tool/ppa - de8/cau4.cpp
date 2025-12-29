// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b);++i)
#define fd(i,a,b) for(int i = (a); i >= (b);--i)
#define file "cau4"

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int Rand(int l, int r){
	return l+rng()%(r-l+1);
}

#define maxn 1000006
#define lg 20
#define inf (int64)4e18

int n, k;
int a[maxn];
bool d[maxn];
int cost[maxn];

void sang(){
	d[0] = d[1] = 1;

	for(int i = 2; i*i<maxn; ++i){
		if(d[i] == 0){
			for(int j = i*i; j<maxn; j+=i){
				d[j] = 1;
			}
		}
	}
}

void init(){
	int p = -1;
	f0(i, 0, maxn-1){
		if(!d[i])p = i;
		cost[i] = (p == -1 ? INT_MAX : i-p);
	}

	p = -1;

	fd(i, maxn-1, 0){
		if(!d[i])p = i;
		if(p != -1){
			cost[i] = min(cost[i], p - i);
		}
	}
}

void nhaptay(){
	cin>>n>>k;
	f0(i, 0, n-1)cin>>a[i];
}

void nhaprand(){
	n = Rand(1, 20);
	k = Rand(1, 10);

	cerr<<n<<" "<<k<<'\n';
	f0(i, 0, n-1){
		a[i] = Rand(1, 100);
		cerr<<a[i]<<" ";
	}
}

void printc(){
	f0(i, 1, n){
		cout<<cost[a[i-1]]<<" ";
	}

	cout<<'\n';
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	 freopen(file".inp", "r", stdin);
	 freopen(file".out", "w", stdout);

	sang();

	nhaptay();

	init();

	int64 sum = 0, ans = inf;

	f0(i, 1, n){
		sum += cost[a[i]];
		if(i > k)sum -= cost[a[i-k]];
		if(i >= k)ans = min(ans, sum);
	}

	cout<<ans;

	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
