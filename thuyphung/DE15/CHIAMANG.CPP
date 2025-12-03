// authur : anphung >> npkly
#include<bits/stdc++.h>
#define TASK ""
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int n;

int res;


int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("CHIAMANG.INP","r",stdin);
	freopen("CHIAMANG.OUT","w",stdout);
	cin>>n;
	vector<int64> pre(n+1,0);
	f0(i,0,n-1){
		int64 x;
		cin>>x;
		pre[i+1] = pre[i] + x;
	}

	f0(i,0,n-1){
		if(pre[i+1] == pre[n-i]){
			res = i+1;
		}
	}

	cout<< (res==0?0:res);

	cerr << "time elapsed: "<<TIME <<"s.\n";
}