// authur : anphung >> npkly
#include<bits/stdc++.h>
#define TASK ""
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

const int mod = 1e9+7;

int n;
int64 fib[110];

void Try(int n){
	fib[0] = fib[1] = 1;
	for(int i=2;i<=n;i++){
		fib[i] = (fib[i-1] + fib[i-2])%mod;
		//cout<<fib[i]<<" ";
	}
	cout<<fib[n]%mod;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("FIBONACCI.inp","r",stdin);
	freopen("FIBONACCI.out","w",stdout);
	cin>>n;
	Try(n-1);
	cerr << "time elapsed: "<<TIME <<"s.\n";
}