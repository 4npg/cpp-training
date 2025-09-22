// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}

int a[2000];
int n,k;
int check[2000];

void print(){
	f0(i,1,k){
		cout<<a[i]<<" ";
	}
	cout<<'\n';
}

void Try(int pos){
	for(int j = a[pos-1]+1;j<=n-k+pos;++j){
		
		a[pos] = j;
		if(pos==k)print();
		else Try(pos+1);
	}
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	a[0] = 0;
	Try(1);
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


