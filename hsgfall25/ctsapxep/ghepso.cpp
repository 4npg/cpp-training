// author : anphung
// github : 4npg  >>tqn
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int n;
const int maxn = 1e6+5;
string a[maxn];

bool cmp(string a,string b){
	return a+b>b+a;
}
int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	f0(i,0,n-1){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	f0(i,0,n-1){
		cout<<a[i];
	}
}


