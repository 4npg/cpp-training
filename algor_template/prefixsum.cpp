#include <bits/stdc++.h>
using namespace std;

/* 1D prefix sums and 2D prefix sums, difference array */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1D prefix
    int n; cin >> n;
    vector<long long> a(n+1), pref(n+1,0);
    for (int i=1;i<=n;i++) { cin>>a[i]; pref[i]=pref[i-1]+a[i]; }
    // sum [l,r] = pref[r]-pref[l-1]

    // difference array for range add
    vector<long long> diff(n+3,0);
    auto range_add = [&](int l,int r,long long v){
        diff[l]+=v; diff[r+1]-=v;
    };
    // after many ops:
    vector<long long> finalA(n+1);
    long long cur=0;
    for(int i=1;i<=n;i++){ cur+=diff[i]; finalA[i]=cur; }

    // 2D prefix sample
    int R,C; // read and fill a2
    return 0;
}
