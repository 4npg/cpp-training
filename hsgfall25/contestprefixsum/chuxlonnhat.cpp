// author : anphung
// github : 4npg
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define pb push_back 

const int maxn = 505;
int n;
int a[maxn][maxn];

int getsum(const vector<int>&v,int l,int r){
	return v[r] - (l?v[l-1]:0);
}

void taopre(vector< vector<int> > &cheo){
	for(auto &v:cheo){
		f0(i,1,(int)v.size()-1){
			v[i] += v[i-1];
		}
	}
}

int calc(int x,int y,int k,int offset,
	vector< vector<int> >&chinh,vector< vector<int> >&phu,
	vector< vector<int> >&posc,vector< vector<int> >&posp){
	int idc = x-y+offset;
	int pc = posc[x][y];
	int tongc = getsum(chinh[idc],pc,pc+k-1);

	int idp = x+(y+k-1);
	int pp = posp[x][y+k-1];
	int tongp = getsum(phu[idp],pp,pp+k-1);

	return tongc-tongp;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin>>n;
	f0(i,0,n-1){
		f0(j,0,n-1)cin>>a[i][j];
	}

	int offset = n-1;
	vector< vector<int> > chinh(2*n),phu(2*n);
	vector< vector<int> > posc(n,vector<int>(n)),posp(n,vector<int>(n));

	f0(i,0,n-1){
		f0(j,0,n-1){
			int idc = i-j+offset;
			posc[i][j] = chinh[idc].size();
			chinh[idc].pb(a[i][j]);

			int idp = i+j;
			posp[i][j] = phu[idp].size();
			phu[idp].pb(a[i][j]);
		}
	}

	taopre(chinh);
	taopre(phu);
	int ans = -1e9;
	f0(x,0,n-1){
		f0(y,0,n-1){
			int maxk = min(n-x,n-y);
			f0(k,2,maxk){
				ans = max(ans,calc(x,y,k,offset,chinh,phu,posc,posp));
			}
		}
	}
	cout<<ans;
}


