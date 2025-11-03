// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

const int64 base1 = 131, base2 = 137;
const int64 mod1 = 1000000007, mod2 = 1000000009;

struct Hash {
	vector<int64> h1,h2,p1,p2;
	int n;

	Hash(string &s){
		n = s.size();
		h1.assign(n+1,0);
		h2.assign(n+1,0);
		p1.assign(n+1,1);
		p2.assign(n+1,1);
		f0(i,1,n){
			h1[i] = (h1[i-1]*base1+s[i-1])%mod1;
			h2[i] = (h2[i-1]*base2+s[i-1])%mod2;
			p1[i] = (p1[i-1]*base1)%mod1;
			p2[i] = (p2[i-1]*base2)%mod2;
		}
	}
	pair<int64,int64> get(int l,int r){
		int64 x1 = (h1[r] - h1[l-1] * p1[r-l+1] % mod1 + mod1) % mod1;
		int64 x2 = (h2[r] - h2[l-1] * p2[r-l+1] % mod2 + mod2) % mod2;
		return {x1,x2};
	}
};

string s;
int q;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>s;
	string t = s;
	reverse(t.begin(),t.end());
	cin>>q;
	Hash H1(s),H2(t);
	int n = s.size();

	 while (q--) {
        int l, r; cin >> l >> r;
        auto hash1 = H1.get(l, r);
        auto hash2 = H2.get(n - r + 1, n - l + 1);
        if (hash1 == hash2) cout << "YES\n";
        else cout << "NO\n";
    }

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


