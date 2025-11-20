// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file "BAI2"
#define maxn 1000006

int n;
int a[maxn];
int cnt;
bool ok(int i, int j, int k){
	return ((a[i] + a[j] == a[k] || a[i] + a[k] == a[j] || a[j] + a[k] == a[i]));
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen(file".inp","r",stdin);
	freopen(file".ans","w",stdout);
	cin>>n;
	f0(i,0,n-1){
		cin>>a[i];
	}

	f0(x,0,n-1){
		f0(y,x+1,n-1){
			f0(z,y+1,n-1){
				if(ok(x,y,z))cnt++;
			}
		}
	}
	cout<<cnt;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}





