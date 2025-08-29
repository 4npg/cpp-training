// author : anphung
// github : 4npg  >>tqn
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int n,q;
int a[2005][2005];
int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	a[0][0] = 0;
	f0(i,1,n){
		f0(j,1,n){
			char x;cin>>x;
			a[i][j] = a[i-1][j]+a[i][j-1]-a[i-1][j-1]+ (x=='*');
		}
	}
	while(q--){
		int r1,c1,r2,c2;
		cin>>r1>>c1>>r2>>c2;
		// for(int i = r1;i<=r2;i++){
		// 	for(int j=c1;j<=c2;j++){
		// 		cout<<a[i][j]<<" ";
		// 	}
		// 	cout<<'\n';
		// }
		cout<<a[r2][c2] + a[r1-1][c1-1] - a[r2][c1-1] - a[r1-1][c2]<<'\n';
		//cout<<'\n';
	}
}


