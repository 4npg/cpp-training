// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define all(a) (a).begin(),(a).end()


int n;
vector<int64> l,r,w,dp;
vector<int> idx;

int tknp(int i){
	int le=0,ri=i-1,res=-1;
	while(le<=ri){
		int mid = le + ((ri-le)>>1);
		if(r[idx[mid]]<l[idx[i]]){
			res = mid;
			le = mid + 1;
		}else ri = mid - 1;
	}
	return res;
}

bool cmp(int x,int y){
	return r[x] < r[y];
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	idx.resize(n);
	l.resize(n);
	r.resize(n);
	w.resize(n);
	dp.resize(n);
	
	f0(i,0,n-1){
		cin>>l[i]>>r[i]>>w[i];
		idx[i] = i;

	}
	sort(all(idx),cmp);	

	f0(i,0,n-1){
		int64 chon = w[idx[i]];
		int prev = tknp(i);
		if(prev!=-1)chon += dp[prev];
		dp[i] = max((i>0)?dp[i-1]:0,chon);
	}
	cout<<dp[n-1];

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


