// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define maxn 3000006

int t;
bool d[maxn];
vector<int> pre(maxn);
int m[maxn];
int64 tcs(int64 n){
	int64 sum = 0;
	while(n){
		sum += n%10;
		n /= 10;
	}
	return sum;
}

void sang(){
	d[0] = d[1] = 1;
	for(int i=2; i*i< maxn; ++i){
		if(d[i] == 0){
			for(int j=i*i; j<maxn; j+=i){
				d[j] = 1;
			}
		}
	}
	pre[0] = 0;
	f0(i, 5, maxn){
		if(d[i] == 0 && tcs(i)%5 == 0){
			pre[i] = pre[i-1] + 1;
		}else pre[i] = pre[i-1];
	}

}
int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	sang();
	cin>>t;	
	while(t--){
		int l, r;
		cin>>l>>r;
		cout<<pre[r] - pre[l-1]<<'\n';
	}

	cerr << "time elapsed: "<<TIME <<"s.\n";
}





