// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define all(a) (a).begin(),(a).end()
#define bit(mask,i) ((mask>>i)&1)
#define pb push_back 

int n;
const int maxn = 1e5+5;
int64 s;
int64 a[maxn];

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>s;
	f0(i,0,n-1)cin>>a[i];
	int m = (n>>1);
	vector<int64> lo,hi;
	f0(mask,0,(1<<m)-1){
		int64 sum = 0;
		f0(i,0,m-1){
			if(bit(mask,i))sum+=a[i];
		}lo.pb(sum);
	}	

	int m2 = n-m;
	f0(mask,0,(1<<m2)-1){
		int64 sum=0;
		f0(i,0,m2-1){
			if(bit(mask,i))sum+=a[m+i];
		}hi.pb(sum);
	}

	sort(all(hi));

	int64 ans = 0;
	for(auto &x:lo){
		int64 target = s-x;
		auto l = lower_bound(all(hi),target);
		auto r = upper_bound(all(hi),target);
		ans+=(r-l);
	}
	cout<<ans;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


