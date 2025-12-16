// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

const int mod = 1e9+7;
int n;
const int maxn = 1e6+5;

int f[maxn];
int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;

	f[0] = 1;
	f0(i, 1, n){
		 f0(j, 1, 6){
			if(j<=i)
				f[i] = (f[i] + f[i-j])%mod;
			else break;
		}
	}

	cout<<f[n];
}


