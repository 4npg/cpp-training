// author : anphung
// github : 4npg  >>tqn
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "CAU1"
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int64 a,b,res;

int64 gcd(int64 a,int64 b){
	if(b==0)return a;
	return gcd(b,a%b);
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	if(fopen(TASK".inp","r")){
		freopen(TASK".inp","r",stdin);
		freoepn(TASK".out","w",stdout);
	}
	cin>>a>>b;

	for(int i=1;i*i<=gcd(a,b);++i){
		if(gcd(a,b)%i==0){
			res++;
			if(gcd(a,b)/i!=i)res++;
		}
	}
	cout<<res;
}


