// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define pb push_back

const int64 base = 131;
const int64 mod = 1000000007;

int n,k;
string s;
vector<int64> h,pw;

int64 getHash(int l,int r){
	int64 res = (h[r]-h[l-1]*pw[r-l+1])%mod;
	if(res<0)res+=mod;
	return res;
}

bool check(int len){
	if(len==0)return true;
	vector<int64> sub;
	sub.reserve(n-len+1);

	f0(i,len,n)sub.pb(getHash(i-len+1,i));
	sort(sub.begin(),sub.end());

	int cnt = 1;
	f0(i,1,(int)sub.size()-1){
		if(sub[i]==sub[i-1])cnt++;
		else cnt = 1;
		if(cnt>=k)return true;
	}
	return false;
}



int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file("kstring");
	cin>>n>>k>>s;
	if(k==1||k==0){
		cout<<n;
		return 0;
	}
	s = " " + s;
	h.assign(n+1,0);
	pw.assign(n+1,1);

	f0(i,1,n){
		h[i] = (h[i-1]*base+(s[i]-'a'+1))%mod;
		pw[i] = pw[i-1]*base%mod;
	}

	int l=0,r=n,ans=0;

	while(l<=r){
		int mid = (l+r)/2;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}

	cout<<ans;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


