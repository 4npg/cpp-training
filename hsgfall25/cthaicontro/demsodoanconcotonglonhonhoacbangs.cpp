// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int n;
const int maxn = 1e6+5;
int64 a[maxn];
int64 ans;
int64 sum,s;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>s;
	f0(i,0,n-1)cin>>a[i];

	int r = 0;
	f0(l,0,n-1){
		while(r<n&&sum<s){
			sum+=a[r++];
		}
		if(sum>=s)ans+=(1ll)*(n-r+1);
		sum-=a[l];
	}
	cout<<ans;
}


