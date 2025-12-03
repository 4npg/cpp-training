#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
bool cmp(ll a,ll b){
	return b>a;
}
void READFILE(){
    freopen("INP.TXT","r",stdin);
    freopen("OUT.TXT","w",stdout);
}
int main() {
    fast;
    ll n; cin >> n;
    vector<double> a(n);
    map<double, ll> freq;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    sort(a.begin(), a.end());
    cout<<freq.size()<<"\n";
    for (ll i = n-1;i>=0; i--) {
        if (i == 0 || a[i] != a[i - 1]) {
            cout << a[i] << " " << freq[a[i]] << "\n";
        }
    }

}
