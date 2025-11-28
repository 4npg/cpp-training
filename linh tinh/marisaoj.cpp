#include <bits/stdc++.h>
using namespace std;
#define int64 long long 
#define f0(i,a,b) for(int (i)=(a); (i)<=(b); ++i)

int n,s;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>s;

    vector<int> freq(1001, 0);
    f0(i,0,n-1){
        int x;
        cin >> x;
        freq[x]++;
    }

    int64 res = 0;
    
    for (int x = 1; x <= 1000; x++) {
        int y = s - x;

        if (x < y) {
            res += 1LL * freq[x] * freq[y];
        } else if (x == y) {
            res += 1LL * freq[x] * (freq[x] - 1) / 2;
        }
    }

    cout << res;
}
