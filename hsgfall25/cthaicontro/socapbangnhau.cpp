// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int n,m;
const int maxn = 1e6+5;
int64 a[maxn],b[maxn];
int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	f0(i,0,n-1)cin>>a[i];
	f0(i,0,m-1)cin>>b[i];

	int i=0,j=0;
	int64 ans = 0;
	while(i<n&&j<m){
		if(a[i]==b[j]){
			int64 cnta=0,cntb=0;
			int64 val = a[i];
			while(i<n&&a[i]==val){
				cnta++;
				i++;
			}
			while(j<m&&b[j]==val){
				cntb++;
				j++;
			}
			ans += cnta*cntb;
		}else if(a[i]<b[j])i++;
		else j++;
	}
	cout<<ans;
}


