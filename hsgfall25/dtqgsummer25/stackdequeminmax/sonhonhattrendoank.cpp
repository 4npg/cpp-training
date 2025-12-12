// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 1000006
#define pb push_back

int n, k;
int64 a[maxn];
int64 mi[maxn];

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>k;
	f0(i, 1, n)cin>>a[i];

	deque<int64> dq;

	while(dq.size())dq.pop_front();

	f0(i, 1, n){
		while(dq.size() && a[dq.back()] >= a[i])dq.pop_back();
		dq.pb(i);

		if(dq.front() + k <=i)dq.pop_front();
		if(i>=k)mi[i] = a[dq.front()];
	}



	f0(i, k, n){
		cout<<mi[i]<<" ";
	}


	cerr << "time elapsed: "<<TIME <<"s.\n";
}


