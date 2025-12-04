// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define maxn 200005

int n, q;
int64 a[maxn], t[maxn*4];

void update(int p, int x){
	f0(i, 1, n){
		if(i == p){
			a[i] = x;
			break;
		}
	}
}

void print(){
	f0(i, 1, n){
		cout<<a[i]<<" ";
	}
}

int64 get(int p){
	int64 ans = LLONG_MAX;
	f0(j, 1, n){
		if(p!=j){
			ans = min(ans, a[j] + abs(p-j));
		}
	}
	return ans;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>q;
	f0(i, 1, n)cin>>a[i];

	while(q--){
		int type, i;
		cin>>type>>i;
		if(type == 1){
			int x; cin>>x;
			update(i, x);
		}else{
			cout<<get(i)<<'\n';
		}
	}

	cerr << "time elapsed: "<<TIME <<"s.\n";
}





