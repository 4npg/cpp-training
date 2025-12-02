// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define bit(mask,i) ((mask>>i)&1)
#define maxn 25
#define pb push_back
#define all(a) (a).begin(),(a).end()

int n, s;
int cnt;
int a[maxn];
vector< vector<int> > cauhinh;
int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>s;
	f0(i, 0, n-1)cin>>a[i];


	f0(mask, 0, (1<<n)-1){
		int sum = 0;
		vector<int> cauhinhcur;
		cauhinhcur.clear();
		f0(i, 0, n-1){
			if(bit(mask, i)){
				sum+=a[i];
				cauhinhcur.pb(i+1);
			}
		}
		if(sum == s){
			cnt++;
			cauhinh.pb(cauhinhcur);

		}
	}

	cout<<cnt<<'\n';
	reverse(all(cauhinh));
	for(auto &ch:cauhinh){
		for(auto &val:ch){
			cout<<val<<" ";
		}
		cout<<'\n';
	}
	cerr << "time elapsed: "<<TIME <<"s.\n";
}





