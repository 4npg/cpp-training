// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file "COPRIME"
#define maxn 1000006

//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());


int n;
int a[maxn];


int gcd(int a, int b){
	if(b==0)return a;
	return gcd(b, a%b);
}


int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(file".INP", "w", stdin);
    freopen(file".OUT", "w", stdout);
    cin>>n;
    f0(i, 1, n)cin>>a[i];
	int l = 1;
	int ma = ((gcd(a[l], a[l+1])==1)?1:0);

		for(int r=l+1; r<=n; r++){
			if(gcd(a[r], a[r-1])==1){
				if(ma < r-l+1)ma = max(ma, r-l+1);
			}else{
				l = r;
			}
		}

	cout<<ma;
	//cerr << "time elapsed: "<<TIME <<"s.\n";
}


