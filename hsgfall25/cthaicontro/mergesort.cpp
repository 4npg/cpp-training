// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define pb push_back
int n,m;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	vector<int> a(n);
	f0(i,0,n-1)cin>>a[i];
	cin>>m;
	vector<int> b(m);
	f0(i,0,m-1)cin>>b[i];
	int i=0,j=0;
	vector<char> ans;
	while(i<n&&j<m){
		if(a[i]<=b[j]){
			cout<<a[i]<<" ";
			i++;
			ans.pb('a');
		}else{
			cout<<b[j]<<" ";
			j++;
			ans.pb('b');
		}
	}
	while(i<n){
		cout<<a[i]<<" ";
		ans.pb('a');
		i++;
	}
	while(j<m){
		cout<<b[j]<<" ";
		ans.pb('b');
		j++;
	}
	cout<<'\n';
	for(auto &x:ans)cout<<x;
}


