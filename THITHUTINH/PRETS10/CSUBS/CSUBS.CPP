// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 1000
#define mod 1000000
#define pb push_back
#define fi first 
#define se second

int t, a, s, b;
vector<int> cnt;
int ans;

void Try(int pos, int cur){
	if(cur > b)return;
	if(pos == t){
		if(cur>=s && cur<=b)ans++;
		return;
	}
	f0(x, 0, cnt[pos]){
		Try(pos+1, cur+x);
	}
}

void sub1(){
	Try(0, 0);
	cout<<ans;
}
i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>t>>a>>s>>b;
	vector<int> cnt(t+1, 0);
    for(int i = 0; i < a; i++){
        int x; cin >> x;
        cnt[x]++;
    }

    vector<int> dp(a+1, 0), ndp(a+1, 0);
    dp[0] = 1;

    for(int i = 1; i <= t; i++){
        vector<int> pre(a+1, 0);
        pre[0] = dp[0];
        for(int j = 1; j <= a; j++)
            pre[j] = (pre[j-1] + dp[j]) % mod;

        for(int j = 0; j <= a; j++){
            int l = j - cnt[i] - 1;
            if(l >= 0)
                ndp[j] = (pre[j] - pre[l] + mod) % mod;
            else
                ndp[j] = pre[j];
        }

        dp.swap(ndp);
        fill(ndp.begin(), ndp.end(), 0);
    }


	int ans = 0;
	f0(j, s, b)ans = (ans + dp[j])%mod;

	cout<<ans;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}
