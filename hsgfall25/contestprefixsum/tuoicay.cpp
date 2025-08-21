// author : anphung
// github : 4npg  >>tqn
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int n,q;
const int maxn = 1e6+5;
int64 a[maxn],dif[maxn];

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;
	f0(i,1,n){
		cin>>a[i];
	}
	cin>>q;
	while(q--){
		int l,r;
		int64 x;
		cin>>l>>r>>x;
		dif[l]+=x;
		if(r+1<=n)dif[r+1]-=x;
	}
	int64 tmp = 0;
	f0(i,1,n){
		tmp += dif[i];
		cout<<a[i]+tmp<<" ";
	}
}


