// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}

int n;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	file("triple");
	cin>>n;
	vector<int> spf(n+1,0);
	for(int i=2;i<=n;i++){
		if(!spf[i]){
			spf[i] = i;
			if(1LL*i*i<=n){
				for(int j=i*i;j<=n;j+=i){
					if(!spf[j])spf[j]=i;
				}
			}
		}
	}
	f0(i,1,n)if(!spf[i])spf[i]=i;

	vector<int> freq(n+1,0);
	for(int x=1;x<=n;++x){
		int y=x;
		int sp=1;
		while(y>1){
			int p=spf[y];
			int cnt=0;
			while(y%p==0){
				y/=p;
				cnt^=1;
			}
			if(cnt)sp*=p;
		}
		freq[sp]++;
	}
	int64 ans = 0;
	for(int v=1;v<=n;++v){
		int c=freq[v];
		if(c>=3)ans+=c*(c-1)*(c-2)/6;
	}
	cout<<ans;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


