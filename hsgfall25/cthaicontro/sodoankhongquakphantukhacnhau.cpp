// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int n,k;
const int maxn = 1e6+5;
int a[maxn];

int64 solve(int k){
	if(k<0)return 0;
	map<int,int> cnt;
	int l=0,khac=0;
	int64 res = 0;
	f0(r,0,n-1){
		if(++cnt[a[r]]==1)khac++;
		while(khac>k){
			if(--cnt[a[l]]==0){
				cnt.erase(a[l]);
				khac--;
			}
			l++;
		}
		res+=(r-l+1);
	}
	return res;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin>>n>>k;
	f0(i,0,n-1)cin>>a[i];
	cout<<solve(k);
}


