// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

int t;

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>t;
	while(t--){
		int n, l, r;
		cin>>n>>l>>r;

		vector<int> pre(n+1, 0);

		f0(i, 1, n){
			pre[i] = i;	
		}

		pre[r] = pre[l-1];

		vector<int> a(n+1);

		f0(i, 1, n){
			a[i] = pre[i] ^ pre[i-1];
		}

		f0(i, 1, n)cout<<a[i]<<" ";
		cout<<'\n';
	}

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


