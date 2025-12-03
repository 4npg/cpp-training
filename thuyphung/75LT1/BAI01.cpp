#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)

pair<double, double> slidin(vector<ll>& a, ll k, ll n) {
    ll res = 0;
    for (ll i = 0; i < k; i++) {
        res += a[i];
    } // tinh tong k ptu
    double summin = (double)res / k;
    double summax = (double)res / k;
    for (ll i = k; i < n; i++) {
        res = res - a[i - k] + a[i];
        summax = max(summax, ((double)res / k));
        summin = min(summin, ((double)res / k));
    }
    return {summin, summax};
}
// -1 -2 4 -3 5 6 7
// k = 2
// -1 -2 : -3 : -1.5  
// -2 4  : 2  : 1.0  
// 4 -3  : 1  : 0.5  
// -3 5  : 2  : 1.0  
// 5 6   : 11 : 5.5  
// 6 7   : 13 : 6.5  
// k = 3
// -1 -2 4   : 1  : 0.3  
// -2 4 -3   : -1 : -0.3  
// 4 -3 5    : 6  : 2.0  
// -3 5 6    : 8  : 2.7  
// 5 6 7     : 18 : 6.0  
// k = 4
// -1 -2 4 -3     : -2  : -0.5  
// -2 4 -3 5      : 4   : 1.0  
// 4 -3 5 6       : 12  : 3.0  
// -3 5 6 7       : 15  : 3.8  
// k = 5
// -1 -2 4 -3 5     : 3   : 0.6  
// -2 4 -3 5 6      : 10  : 2.0  
// 4 -3 5 6 7       : 19  : 3.8  
// k = 6 
// -1 -2 4 -3 5 6     : 9   : 1.5  
// -2 4 -3 5 6 7      : 17  : 2.8  
// ==> k càng lớn thì tổng trung bình càng nhỏ,k nhro thì tổng trung bình lớn
void READFILE(){
    freopen("INP.TXT","r",stdin);
    freopen("OUT.TXT","w",stdout);
}
int main() {
    fast;
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    double tbmin = 1e9, tbmax = -1e9;
    for (ll k = 2; k <= 3; k++) {
        pair<double,double> res = slidin(a,k,n);
        tbmin = min(tbmin, res.first);
        tbmax = max(tbmax, res.second);
    }
    cout << fixed << setprecision(3) << tbmin << " " << tbmax << "\n";
}
