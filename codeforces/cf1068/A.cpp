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
		int n, k;
		string s;
		cin>>n>>k>>s;

		vector<int> aw(n, 0);

		f0(i, 0, n-1){
			if(s[i] == '1'){
				f0(j, i, min(n-1, i+k)){
					aw[j] = 1;
				}
			}
		}

		int cnt = 0;
		f0(i, 0, n-1){
			if(aw[i] == 0)cnt++;
		}
		cout<<cnt<<'\n';
	}


	cerr << "time elapsed: "<<TIME <<"s.\n";
}


