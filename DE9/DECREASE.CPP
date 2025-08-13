// authur : anphung
// github : 4npg
#include<bits/stdc++.h>
#define TASK "DECREASE"
using namespace std;
#define int64 long long
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int n,nn,cnt=0,mx=0;

int main(){
	fast;
	if(fopen(TASK".inp","r")){
		freopen(TASK ".inp","r",stdin);
		freopen(TASK ".out","w",stdout);
	}
	cin>>n;
	nn=n;
	while(n){
		if(n==0){
			break;
		}
		while(nn){
			mx = max(mx,nn%10);
			nn/=10;
		}
		cnt++;
		n-=mx;
		mx=0;
		nn=n;
	}
	cout<<cnt;
}