// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

int n;
string s;
int a[20][20], b[20][20];
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};

void touch(int x, int y){
	f0(k, 0, 4){
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(nx>=1 && nx<=n && ny>=1 && ny<=n){
			b[nx][ny] ^= 1;
		}
	}
}

int solve(int x){
	int best = 1e9;
	int nmask = 1<<n;

	f0(mask, 0, nmask){
		f0(i, 1, n){
			f0(j, 1, n){
				b[i][j] = a[i][j];
			}
		}

		int cnt = 0;
		f0(j, 1, n){
			if(mask&(1<<(j-1))){
				cnt++;
				touch(1, j);
			}
		}

		f0(i, 2, n){
			f0(j, 1, n){
				if(b[i-1][j] != x){
					cnt++;
					touch(i, j);
				}
			}
		}

		bool ok = true;
		f0(j, 1, n){
			if(b[n][j] != x){
				ok = false;
				break;
			}
		}

		if(ok)best = min(best, cnt);
	}
	if(best > (int)1e7)return -1;
	return best;
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
		
	cin>>n;
	f0(i, 1, n){
		cin>>s;
		f0(j, 1, n){
			a[i][j] = s[j-1] - '0';
		}
	}

	int ans0 = solve(0);
	int ans1 = solve(1);

	int res = -1;
	if(ans0 != -1)res = ans0;
	if(ans1 != -1){
		if(res == -1)res = ans1;
		else res = min(res, ans1);
	}

	cout<<res;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


