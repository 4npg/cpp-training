// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 1000006

int n;
int64 x;
int64 a[maxn];
int ans=INT_MAX;

i_love_Hoang_Ngan(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>x;
	f0(i, 1, n){
		cin>>a[i];
	}

	int l = 1;
	int64 sum = 0;
	for(int r=1; r<=n; r++){
		sum+=a[r];

		while(sum>=x){
			ans = min(ans, r-l+1);
			sum-=a[l];
			l++;
		}
	}

	cout<<((ans!=INT_MAX)?ans:0);

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


