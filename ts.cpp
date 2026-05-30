#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file "code"

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int inf = 1e9+7;
const int mod = 97;
const int maxn = 1e6+5;

#define data pair<int, int>

template <class X, class Y> bool maximize(X &a, Y b){
    if(a < b) return a = b, true;
    return false;
}

template <class X, class Y> bool minimize(X &a, Y b){
    if(a > b) return a= b, true;
    return false;
}

string s;
long long ans = 0;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 
    // int bla = uniform_int_distribution<int>(1, 100)(rng);

    if(fopen(file".inp", "r", stdin)){
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }

    cin >> s;
    // int n = s.size();

    // vector<int> pre3(n+1, 0);

    // for(int i = 1; i <= n; ++i){
    //     pre3[i] = (pre3[i-1] + (s[i-1] -'0')) % 3;
    // }

    // map<data, int> cnt;

    // int cur = 0;
    // int pow10 = 1;

    // cnt[{0, pre3[n]}]++;

    // for(int i = n-1; i >= 0; --i){
    //     int d = s[i] - '0';
    //     cur = (d * pow10 + cur) % mod;

    //     data tmp = {cur, pre3[i]};

    //     ans += cnt[tmp];

    //     cnt[tmp]++;

    //     pow10 = pow10 * 10 % mod;
    // }

    // cout << ans;

    // xau qua so 
    stringstream ss(s);
    int x; ss >> x;
    cout << x;

    // so qua xau
    stringstream ss;
    int y = 100; ss << y;
    string s = ss.str();
    cout << y;

    cerr << "\ntime elapsed: "<<TIME<<"s.\n";
}