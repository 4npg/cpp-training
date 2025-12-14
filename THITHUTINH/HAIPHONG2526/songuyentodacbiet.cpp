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
int a[maxn];
int cnt;
bool d[maxn];

int tcs(int x){
	int sum = 0;
	while(x){
		sum += x%10;
		x/=10;
	}
	return sum;
}

void sang(){
	d[0] = d[1] = 1;

	for(int i=2; i*i<maxn; i++){
		if(d[i] == 0){
			for(int j=i*i; j<maxn; j+=i)d[j] = 1;
		}
	}


}

i_love_Hoang_Ngan(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sang();
	cin>>n;
	f0(i, 0, n-1){
		cin>>a[i];
		if(!d[a[i]] && !d[tcs(a[i])])cnt++;
	}

	cout<<cnt;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


