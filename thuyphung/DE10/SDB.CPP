// authur : anphung
// github : 4npg
#include<bits/stdc++.h>
#define TASK "SDB"
using namespace std;
#define int64 long long
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fi first
#define se second
int n;
const int maxn = 1e6+5;
int a[maxn];
int d[maxn];
int main(){
	fast;
	if(fopen(TASK".inp","r")){
		freopen(TASK ".inp","r",stdin);
		freopen(TASK ".out","w",stdout);
	}
	cin>>n;
	
	int cnt=0;
	f0(i,0,n-1){
		cin>>a[i];
		d[a[i]]++;
	}
	f0(i,0,n-1){
		if(d[a[i]]==1)cnt++;
	}
	cout<<cnt;
	el;
	f0(i,0,n-1){
		if(d[a[i]]==1){
			cout<<a[i]<<'\n';
		}
	}
}