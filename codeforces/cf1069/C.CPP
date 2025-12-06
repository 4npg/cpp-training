// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define pb push_back

int q;

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>q;
	while(q--){
		string s, t;
		cin>>s>>t;

		vector<int> cnt(26, 0);
        for (char c : t) cnt[c - 'a']++;

        bool ok = true;
        for (char c : s) {
            if (cnt[c - 'a'] == 0) {
                ok = false;
                break;
            }
            cnt[c - 'a']--;
        }

        if (!ok) {
            cout << "Impossible\n";
            continue;
        }


        string ans;
        int pos = 0;

        f0(c, 0, 25){
            while (cnt[c] > 0) {
                
                if (pos < (int)s.size() && s[pos] <= char('a' + c)) {
                    ans.pb(s[pos]);
                    pos++;
                } else {
                    ans.pb(char('a' + c));
                    cnt[c]--;
                }
            }
        }

        while (pos < (int)s.size()) {
            ans.pb(s[pos]);
            pos++;
        }

        cout << ans << "\n";
	}

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


