// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "task"
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

const int maxn = 1000006;
const int mod = 123456789;

bool d[maxn];
vector<int> prime;
unordered_map<int64, int64> cntp;

void sang(){
    d[0] = d[1] = 1;
    for(int i = 2; i * i < maxn; ++i){
        if(!d[i]){
            for(int j = i * i; j < maxn; j += i)
                d[j] = 1;
        }
    }
    for(int i = 2; i < maxn; ++i)
        if(!d[i]) prime.push_back(i);
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(file".inp", "r", stdin);
    freopen(file".ans", "w", stdout);
    sang();

    int n;
    cin >> n;

    f0(i, 1, n){
        int64 x;
        cin >> x;
        for(int p : prime){
            if(1LL * p * p > x) break;
            if(x % p == 0){
                int64 c = 0;
                while(x % p == 0){
                    x /= p;
                    c++;
                }
                cntp[p] += c;
            }
        }
        if(x > 1) cntp[x]++;
    }

    int64 ans = 1;
    for(auto &it : cntp){
        ans = (ans * (it.second + 1)) % mod;
    }

    cout << ans;
    cerr << "time elapsed: " << TIME << "s.\n";
}
