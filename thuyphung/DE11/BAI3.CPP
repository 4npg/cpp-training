#include <bits/stdc++.h>
using namespace std;
#define TASK "BAI3"
const int maxc = 256;
int freq[maxc];
int last_used[maxc];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if(fopen(TASK".inp","r")){
		freopen(TASK ".inp","r",stdin);
		freopen(TASK ".out","w",stdout);
	}
    int t;cin >> t;
    int test_id = 1;
    while (t--) {
        string s;
        cin >> s;

        for (char c : s) {
            if (last_used[c] != test_id) {
                freq[c] = 0;
                last_used[c] = test_id;
            }
            freq[c]++;
        }
        int idx = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (freq[s[i]] == 1) {
                idx = i + 1;
                break;
            }
        }
        cout << idx << '\n';
        ++test_id;
    }
}
