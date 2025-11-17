// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

int n,x;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>x;
	vector<int> L(n+1), R(n+1);

	f0(i,1,n){
		L[i] = i-1;
		R[i] = i+1;
	}	

	L[1] = 0;
	R[n] = 0;

	while(x--){
		int i,j;
		cin>>i>>j;

		if(L[i] != 0)R[L[i]] = R[i];
		if(R[i] != 0)L[R[i]] = L[i];

		L[i] = L[j];
		R[i] = j;

		if(L[j] != 0)R[L[j]] = i;
		L[j] = i;
	}

	int head = 1;
	while(L[head] != 0)head = L[head];

	int cur = head;

	while(cur != 0){
		cout<<cur<<" ";
		cur = R[cur];
	}

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


