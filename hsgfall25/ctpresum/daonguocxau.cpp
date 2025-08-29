// author : anphung
// github : 4npg
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

string s;
int q;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>s;
	cin>>q;
	int n = s.size();
	vector<int> pre(n/2+2,0);
	f0(i,0,q-1){
		int k;cin>>k;
		pre[k]++;
	}
	f0(i,1,n/2){
		pre[i]+=pre[i-1];
	}
	f0(i,1,n/2){
		if(pre[i]%2==1){
			swap(s[i-1],s[n-i]);
		}
	}
	cout<<s;
}


