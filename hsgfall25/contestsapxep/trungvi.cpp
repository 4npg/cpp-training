// author : anphung
// github : 4npg  >>tqn
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define all(a) (a).begin(),(a).end()
int n;
const int maxn = 1e6+5;


int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	vector<int64>a(n);
	f0(i,0,n-1){
		cin>>a[i];
	}
	sort(all(a));
	cout<<a[(n+1)/2-1];
}


