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
	//file("SUMATION");
	cin>>n;
	vector<double> a(n);
	for(auto &x:a)cin>>x;
	priority_queue<double,vector<double>,greater<double>> fq;

	for(auto &x:a)fq.push(x);
	double ans = 0.0;
	
	while(fq.size()>1){
		double a = fq.top();
		fq.pop();
		double b = fq.top();
		fq.pop();
		fq.push(a+b);
		ans+=(a+b)*0.05;
	}
	cout<<setprecision(2)<<ans;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


