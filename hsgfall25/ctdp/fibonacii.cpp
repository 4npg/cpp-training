// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define all(a) (a).begin(),(a).end()
#define pb push_back

int t;
int n;

__int128 fib(int n){
	if(n==0||n==1)return 1LL;
	__int128 a=1,b=1;
	for(int i=2;i<=n;i++){
		__int128 c=a+b;
		a=b;
		b=c;
	}
	return b;
}

void print(__int128 x){
	if(x==0){
		cout<<0;return;
	}
	string s;
	while(x){
		s.pb(char('0'+x%10));
		x/=10;
	}
	reverse(all(s));
	cout<<s<<'\n';
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		print(fib(n));
	}
}


