// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define f0(i,a,b) for(int (i)=(a);i<=(b);++i)
#define pb push_back
const int maxn = 1e6+5;
int d[maxn];
int64 n;
void sang(){
	d[0] = d[1] = 1;
	for(int i=2;i*i<maxn;i++){
		if(d[i]==0){
			for(int j = i*i;j<maxn;j+=i)d[j]=1;
		}
	}
}

bool check(int64 n,const vector<int>primes){
	if(n<2)return 0;
	if(n==2)return 1;
	if(n%2==0)return n==2;
	for(auto &x:primes){
		if(x==2)continue;
		if((int64)x>n/x)break;
		if(n%x==0)return 0;
	}
	return 1;
}

int32_t main() {
    fast;
    sang();
    cin>>n;
    vector<int> primes;
   	for(int i=2;i*i<=n;i++)if(d[i]==0)primes.pb(i);
   	bool found = 0;
    for(size_t j=1;j<primes.size();++j){
        int y = primes[j];
        int64 z = 4ll + 1ll*y*y;
        if(z > n) break;
        if(check(z,primes)){
           cout<<2<<' '<<y<<' '<< z;
           el;
           found = 1;
        }
    }
    if(!found) cout << -1 << '\n';
}


