// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

int n;
string s;

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        
    cin>>n>>s;
    double best = 1e18;
    int L = 1, R = n;

    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {

            
            int cnt = 0;
            vector<int> seen(26, 0);

            for (int i = l; i <= r; i++) {
                int c = s[i] - 'a';
                if (!seen[c]) {
                    seen[c] = 1;
                    cnt++;
                }
            }

            int len = r - l + 1;
            double color = (double)cnt / len;

            if (color < best) {
                best = color;
                L = l + 1;
                R = r + 1;
            }
        }
    }

    cout << L << " " << R;

    cerr << "time elapsed: "<<TIME <<"s.\n";
}


