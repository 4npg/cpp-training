// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define pb push_back
#define fi first
#define se second

const int64 inf = 2e18;
const int maxn = 505;
int64 d[maxn][maxn];
int n,m,q;


int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>q;
	f0(i,1,n){
		f0(j,1,n){
			d[i][j] = ((i==j)?0:inf);
		}
	}

	f0(i,1,m){
		int a,b;int64 c;
		cin>>a>>b>>c;
		d[a][b] = min(d[a][b],c);
		d[b][a] = min(d[b][a],c);
	}

	f0(k,1,n){
		f0(i,1,n){
			f0(j,1,n){
				if(d[i][k]+d[k][j]<d[i][j]){
					d[i][j] = d[i][k]+d[k][j];
				}
			}
		}
	}

	while(q--){
		int a,b;
		cin>>a>>b;
		if(d[a][b]>=inf/2)cout<<-1<<'\n';
		else cout<<d[a][b]<<'\n';
	}

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


