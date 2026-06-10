#include<bits/stdc++.h>
using namespace std;

#define file ""
#define TIME (1.0*clock()/CLOCKS_PER_SEC)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class T> bool maximize(T &a, T b){
    if( a < b ) return a = b, true;
    return false;
}

const int maxn = 1e6+5;

int cntdiv(int n) {
    int ret = 0;
    for( int i = 1; i*i <= n; i++){
        if( n%i == 0 ) {
            ret++;
            if ( n/i != i ) ret++;
        }
    }

    return ret;
}

int mindiv[maxn];

void sang(){
    for( int i = 2; i*i < maxn; ++i ) {
        if(mindiv[i]) continue;
        mindiv[i] = i;

        for(int j = i+i; j<maxn; j+=i ) {
            mindiv[j] = i;
        }
    }
}

#define miniDATA vector<int>

int sub2(int n) {
    if(n == 1)return 1;
    miniDATA prep;
    int lastDiv = 1;
    int cnt = 0;

    while( n != 1 ){
        if(mindiv[n] != lastDiv) {
            if(cnt)prep.emplace_back(cnt);
            cnt = 0;
        }
        ++cnt;
        lastDiv = mindiv[n];
        n /= mindiv[n];
    }
    if(cnt)prep.emplace_back(cnt);
    int ret = 1;
    for(auto i : prep)ret *= (i+1);
    return ret;
}

void solve(){
    sang();
    int n; cin >> n;

    int ans = 0;

    for( int i = 1; i<=n; ++i ) {
        maximize(ans, cntdiv(i));
        cout << i << ' ' << cntdiv(i) << ' ' << sub2(i) <<  '\n';
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);  

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n";
}