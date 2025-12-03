// author : anphung
// github : 4npg  >>tqn
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "LOOP"
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define pb push_back
#define fi first
#define se second
int n;
int64 k;
const int maxn = 1e6+5;
int64 a[maxn];
int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	if(fopen(TASK".inp","r")){
		freopen(TASK".inp","r",stdin);
		freopen(TASK".out","w",stdout);
	}
	cin>>n>>k;
	vector<pair<int64,int64>> v;
	f0(i,0,n-1){
		cin>>a[i];
		v.pb({a[i],1});
	}	
	int64 ans=0;
	f0(i,0,v.size()-1){
		int64 val = v[i].fi;
		int64 mul = v[i].se;
		if(val%k==0){
			v.pb({val/k,mul*k});
		}
		else{
			
			f0(j,0,v.size()-1){
				ans+=v[j].fi*v[j].se;
			}
			break;
		}
	}
	cout<<ans;
}


