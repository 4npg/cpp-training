// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define f0(i,a,b) for(int (i)=(a);i<=(b);++i)

const int maxn = 2*1ll*1e6+10;
int n;
int a[maxn];

int gcd(int a,int b){
	if(a==0)return b;
	return gcd(b,a%b);
}
int32_t main() {
    fast;
    cin>>n;
    vector<int> freq(maxn);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    for (int g = maxn; g >= 1; g--) {
        int cnt = 0;
        for (int mul = g; mul <= maxn; mul += g) {
            cnt += freq[mul];
            if (cnt >= 2) { 
                cout << g;
                return 0;
            }
        }
    }
}


