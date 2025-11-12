// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

int n,k;
set<double> ans;

void solve(double tmp,int hs){
	if(hs==0){
		ans.insert(tmp);
		return;
	}

	if(tmp<0.5){
		return;
	}

	if(fmod(tmp,1.0)==0){
		solve(tmp/2.0,hs-1);
		solve(tmp-0.5,hs-1);
	}else{
		solve(tmp-0.5,hs-1);
	}
}

void sub1(){
	solve(n,k);
	cout<<ans.size()<<'\n';
	bool ok = true;
	for(auto res:ans){
		if(!ok){
			cout<<" ";
		}
		cout<<fixed<<setprecision(1)<<res;
		ok = false;
	}

}


int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>k;
	
	vector< set<double> > dp(k+1);

	dp[0].insert(n);
	f0(i,1,k){
		for(auto tmp:dp[i-1]){
			if(fmod(tmp,1.0)==0.0){
				dp[i].insert(tmp/2.0);
			}

			if(tmp>=0.5){
				dp[i].insert(tmp-0.5);
			}
		}
	}

	cout<<dp[k].size()<<'\n';

	bool ok = true;
	for(auto res:dp[k]){
		if(!ok){
			cout<<' ';
		}
		cout<<fixed<<setprecision(1)<<res;
		ok = false;
	}

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


