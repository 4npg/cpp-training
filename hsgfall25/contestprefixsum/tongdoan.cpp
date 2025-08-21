// author : anphung
// github : 4npg  >>tqn
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int n,t;
const int maxn = 1e6+5;
int64 pre[maxn];

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	pre[0] = 0;
	f0(i,1,n){
		int64 x;cin>>x;
		pre[i] = pre[i-1]+x;
	}
	cin>>t;
	while(t--){
		int l,r;
		cin>>l>>r;
		cout<<pre[r]-pre[l-1]<<'\n';
	}
}


