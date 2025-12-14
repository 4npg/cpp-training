// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

int64 n;
int s, p;

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n;
	if(n==1){
		cout<<0<<'\n'<<1;
		return 0;
	}
	int cnt = 0;
	for(int i=2; i*i<=n; i++){
		if(n%i==0){
			cnt = 0;
			while(n%i==0){
				n/=i;
				cnt++;
			}
			//cout<<i<<" "<<cnt<<'\n';
			if(cnt&1)p+=cnt;
			else s+=cnt;
		}
	}
	if(n>1)p++;
	cout<<s<<'\n'<<p;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


