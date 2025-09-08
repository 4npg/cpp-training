// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
int n;

int64 solve(vector<int64>&a){
	sort(a.begin(),a.end());
	int64 n = a.size();
	vector<int64> pre(n+1,0);
	f0(i,0,n-1){
		pre[i+1] = pre[i] + a[i];
	}
	int64 res = 0;
	f0(j,0,n-1){
		res += 1LL * j * a[j] - pre[j];
	}
	return res;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	vector<int64> x(n),y(n);
	f0(i,0,n-1){
		cin>>x[i]>>y[i];
	}	
	cout<<solve(x)+solve(y);

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


