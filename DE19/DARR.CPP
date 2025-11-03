// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define file "DARR"
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define TIME (1.0*clock_t()/CLOCKS_PER_SEC)

int n;
const int maxn = 2e6+10;
int a[maxn];
int ans = -1e9;


void sub1(){
    int ai = 0;
    int aj = 0;
    f0(i,0,n-1){
        f0(j,0,n-1){
            if(a[i]%a[j]==0||a[i]<a[j])continue;
            else if(a[i]>a[j]){
                if(ans<a[i]%a[j]){
                    ans = a[i]%a[j];
                    ai = a[i];
                    aj = a[j];
                }
            }
        }
    }

    cout<<ans;
}

void sub2(){
	sort(a, a+n);
	int ans = 0;
	for (int i = n-1; i >= 0; --i) {
    	if (i < n-1) ans = max(ans, a[i] % a[i+1]);
    	for (int j = 2*a[i]; j <= a[n-1] + a[i]; j += a[i]) {
        	int pos = lower_bound(a, a+n, j) - a;
        	if (pos > 0) ans = max(ans, a[pos-1] % a[i]);
   	 	}
	}	
	cout << ans;

}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".INP","r",stdin);
    freopen(file".OUT","w",stdout);
    cin>>n;
    f0(i,0,n-1)cin>>a[i];
    if(n<=5000)sub1();
    else sub2();
    cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}

