// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define file "CNTPALIN"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

const int64 base = 131;
const int64 mod = 1000000007;

string s,t;
vector<int64> hs,ht,pw;
int n;

int64 getHash(int l,int r,const vector<int64> &h){
	int64 res = (h[r]-h[l-1]*pw[r-l+1])%mod;
	if(res<0)res+=mod;
	return res;
}

bool checkpal(int l,int r){
	int tl = n-r+1;
	int tr = n-l+1;
	return getHash(l,r,hs) == getHash(tl,tr,ht);
}

int64 cal(){
	int64 ans = 0;

	f0(ct,1,n){
		int lo=0, hi=min(ct-1,n-ct);
		while(lo<hi){
			int mid = (lo + hi+1)/2;
			if(checkpal(ct-mid,ct+mid))lo=mid;
			else hi = mid-1;
		}
		ans += lo + 1;
	}

	f0(ct,1,n-1){
		int lo=0, hi=min(ct,n-ct);
		while(lo<hi){
			int mid = (lo + hi+1)/2;
			if(checkpal(ct-mid+1,ct+mid))lo=mid;
			else hi = mid-1;
		}
		ans += lo;
	}

	return ans;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen(file".inp","r",stdin);
	freopen(file".out","w",stdout);
	cin>>s;
	n = s.size();
	s = " " + s;
	t = s.substr(1);
	reverse(t.begin(),t.end());
	t = " " + t;

	hs.assign(n+1,0);
	ht.assign(n+1,0);
	pw.assign(n+1,1);

	f0(i,1,n){
		hs[i] = (hs[i-1]*base + (s[i]-'a'+1))%mod;
		ht[i] = (ht[i-1]*base + (t[i]-'a'+1))%mod;
		pw[i] = pw[i-1]*base%mod;
	}

	cout<<cal();

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


