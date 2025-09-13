// authur : anphung >> npkly
#include<bits/stdc++.h>
#define TASK ""
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)


int n;int64 s;
const int maxn = 1e6+5;
int64 a[maxn];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("TDOAN.INP","r",stdin);
	freopen("TDOAN.OUT","w",stdout);
	cin>>n>>s;
	a[0] = 0;
	
	f0(i,1,n){
		cin>>a[i];
	}
	int len = 1e9;
	int64 sum = 0;
	int64 af = -1;

	int l = 1;

	for(int r = 1;r<=n;r++){
		sum+=a[r];
		while(sum>=s){
			if(sum==s){
				if(len>r-l+1){
					len = r-l+1;
					af = l;
				}
			}
			sum-=a[l];
			l++;
		}
	}
	if(af!=-1){
		cout<<af<<" "<<len;	
	}else cout<<0;
	
	cerr << "time elapsed: "<<TIME <<"s.\n";
}