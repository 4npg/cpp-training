// authur : anphung
// github : 4npg
#include<bits/stdc++.h>
#define TASK "BAI1"
using namespace std;
#define int64 long long
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int n;
int sumcol[200];
int sumrow[200];
bool check(int i,int j){
	return sumrow[i]==sumcol[j];
}
int main(){
	fast;
	if(fopen(TASK".inp","r")){
		freopen(TASK ".inp","r",stdin);
		freopen(TASK ".out","w",stdout);
	}
	cin>>n;
	f0(i,0,n-1){
		f0(j,0,n-1){
			int x;cin>>x;
			sumrow[i]+=x;
			sumcol[j]+=x;
		}
	}
	int cnt=0;
	f0(i,0,n-1){
		f0(j,0,n-1){
			if(check(i,j)){
				//cout<<"("<<i+1<<")"<<" "<<"("<<j+1<<")";
				cnt++;
			}
		}
		// el;
	}
	cout<<cnt;
}