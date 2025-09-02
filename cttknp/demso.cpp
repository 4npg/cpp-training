// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int n,q;
const int maxn = 2e5+10;
int64 a[maxn];

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	f0(i,0,n-1)cin>>a[i];
	cin>>q;
	sort(a,a+n);
	while(q--){
		int64 l,r;
		cin>>l>>r;
		auto itl = lower_bound(a,a+n,l);
		auto itr = upper_bound(a,a+n,r);
		cout<<itr-itl<<'\n';
	}
}


