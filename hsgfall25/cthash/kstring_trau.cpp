// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file "kstring"
#define pb push_back

const int64 base = 131;
const int64 mod = 1000000007;

int n,k;
string s;

int sub1() {
    int ans = 0;
    for (int len = 1; len <= n; ++len) {
        unordered_map<string, int> freq;
        bool ok = false;

        for (int i = 0; i + len <= n; ++i) {
            string sub = s.substr(i, len);
            freq[sub]++;
            if (freq[sub] >= k) ok = true;
        }

        if (ok) ans = len;
    }
    return ans;
}



int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen(file".inp","r",stdin);
	freopen(file".ans","w",stdout);
	cin>>n>>k>>s;
	int ans = sub1();
	cout<<ans;

	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}


