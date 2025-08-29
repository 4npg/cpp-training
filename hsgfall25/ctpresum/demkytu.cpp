// author : anphung
// github : 4npg  >>tqn
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

const int maxn = 1e6+5;
int n,q;
string s;
int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	cin>>s;
	vector<vector<int>> pre(26,vector<int>(n+1,0));
	f0(i,1,n){
		int c = s[i-1]-'a';
		for(int j=0;j<26;j++){
			pre[j][i] =pre[j][i-1]; 
		}
		pre[c][i]++;
	}
	while(q--){
		char x;int l,r;
		cin>>x>>l>>r;
		int idx = x-'a';
		cout<<pre[idx][r] - pre[idx][l-1]<<'\n';

	}
}


