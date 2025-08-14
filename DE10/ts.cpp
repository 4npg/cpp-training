// authur : anphung
// github : 4npg
#include<bits/stdc++.h>
#define TASK ""
using namespace std;
#define int64 long long
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

const int maxn = 1e6+5;
int d[maxn];

void sang(){
	d[0] = 0;
	d[1] = 1;
	for(int i=2;i*i<=maxn;i++){
		if(d[i]==0){
			for(int j=i*i;j<=maxn;j+=i){
				d[j]+=i;
				if(i*i!=j)d[j]+=i/j;
			}
		}
	}
}

int main(){
	fast;
	if(fopen(TASK".inp","r")){
		freopen(TASK ".inp","r",stdin);
		freopen(TASK ".out","w",stdout);
	}
	sang();
	d[1] * (maxn);
	cout<<d[10];
}