// author : anphung
// github : 4npg  >>tqn
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int n,m,q;
int x,y,u,v;
int64 c;

const int maxn = 1e3+5;
int64 a[maxn][maxn],d[maxn][maxn];

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>q;
	while(q--){
		cin>>x>>y>>u>>v>>c;
		d[x][y] += c;
		d[x][v+1] -= c;
		d[u+1][y] -= c;
		d[u+1][v+1] += c;
	}
	f0(i,1,n){
		f0(j,1,m){
			a[i][j] = d[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
		}
	}
	f0(i,1,n){
		f0(j,1,m){
			cout<<a[i][j]<<" ";
		}
		cout<<'\n';
	}
}


