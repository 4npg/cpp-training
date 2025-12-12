// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 100005

int n;
int a[maxn];
int bit[maxn];

int getSum(int p){
	int id = p, ans = 0;
	for(; id>0; id--){
		ans = bit[id];
		id -= (id&(-id));
	}
	return ans;
}

void update(int u, int v){
	int id = u;
	while(id<=n){
		bit[id] += v;
		id += (id&(-id));
	}
}


int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n;
	f0(i, 1, n){
		int x; cin>>x;
		update(i, x);
	}	

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


