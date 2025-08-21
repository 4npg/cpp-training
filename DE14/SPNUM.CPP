// author : anphung
// github : 4npg  >>tqn
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)


const int maxn = 1e6+5;
bitset<maxn> d; 

int64 n;
int64 cnt = 0 ;
void sang(){
	d[0] = d[1] = 1;
	for(int i=2;i*i<maxn;++i){
		if(d[i] == 0){
			for(int j=i*i;j<maxn;j+=i)d[j] = 1;
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	sang();
	cin>>n;
	for(int i=2;i*i<=n;i++){
		if(d[i]==0)cnt++;
	}
	cout<<cnt;
}


