// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int n,m;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	vector<int> a(n);
	vector<int> b(m);
	f0(i,0,n-1){
		cin>>a[i];
	}
	f0(i,0,m-1){
		cin>>b[i];
	}
	vector<int> ans(m,0);
	int la = 0,lb = 0;
	while(lb<m){
		while(a[la]<b[lb]&&la<n)la++;
		ans[lb]=la;
		lb++;
	}
	for(auto &x:ans)cout<<x<<" ";
}


