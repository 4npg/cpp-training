// authur : anphung
// github : 4npg
#include<bits/stdc++.h>
#define TASK "MAXGIF"
using namespace std;
#define int64 long long
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int n;
const int maxn = 1e6+5;
int a[maxn];

int main(){
	fast;
	if(fopen(TASK".inp","r")){
		freopen(TASK ".inp","r",stdin);
		freopen(TASK ".out","w",stdout);
	}
	cin>>n;
	int64 summax = -1e9;
	int tmp = 0;
	f0(i,0,n-1){
		cin>>a[i];
		summax = max(summax,1ll*a[i]+tmp);
		// cout<<summax<<" "<<tmp<<" "<<a[i]<<" "<<a[i]+tmp;
		// el;
		tmp = a[i];
	}
	cout<<summax;
}