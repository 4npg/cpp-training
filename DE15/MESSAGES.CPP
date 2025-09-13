// authur : anphung >> npkly
#include<bits/stdc++.h>
#define TASK ""
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define file(name) (if(fopen(name".inp","r")){freopen(name".inp","r",stdin);freopen(name".out","w",stdout);})
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int64 n,m;
const int INF = 1e9;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("MESSAGES.INP","r",stdin);
	freopen("MESSAGES.OUT","w",stdout);
	cin>>n>>m;
	vector< vector<int64> > c(n+1,vector<int64>(m+1));
	f0(i,1,n){
		f0(j,1,m){
			cin>>c[i][j];
		}
	}
	vector< vector<int64> > dp(n+1,vector<int64>(m+1,INF));
	vector< vector<int64> > trace(n+1,vector<int64>(m+1,0));

	dp[0][0] = 0;

	f0(j,1,m){
		f0(i,0,n){
			f0(k,0,i){
				if(dp[i-k][j-1]+c[k][j]<dp[i][j]){
					dp[i][j] = dp[i-k][j-1]+c[k][j];
					trace[i][j] = k;	
				}
			}
		}
	}

	cout<<dp[n][m]<<'\n';
	vector<int> index(m+1,0);
	int i=n,j=m;
	while(j){
		int k = trace[i][j];
		index[j] = k;
		i-=k;
		j--;
 	}
 	for(auto &x:index){
 		cout<<x<<'\n';
 	}
	cerr << "time elapsed: "<<TIME <<"s.\n";
}