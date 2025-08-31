// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define pb push_back 
#define pob pop_back 

int n;
int64 k;
const int maxn = 1e6+5;
int64 a[maxn];

deque<int> maxdq,mindq;
int64 res; 

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	f0(i,0,n-1)cin>>a[i];
	int l=0;

	f0(r,0,n-1){
		while(!maxdq.empty()&&a[maxdq.back()]<=a[r])maxdq.pob();
		maxdq.pb(r);

		while(!mindq.empty()&&a[mindq.back()]>=a[r])mindq.pob();
		mindq.pb(r);

		while(!maxdq.empty()&&!mindq.empty()&&a[maxdq.front()]-a[mindq.front()]>k){
			if(maxdq.front()==l)maxdq.pop_front();
			if(mindq.front()==l)mindq.pop_front();
			l++;
		}
		res+=(r-l+1);
	}	
	cout<<res;
}


