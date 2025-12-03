#include<bits/stdc++.h>
using namespace std;
#define ll int
#define pb push_back
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr)
struct po {
    ll x, y;
    ll index;
};
void READFILE(){
    freopen("INP.TXT","r",stdin);
    freopen("OUT.TXT","w",stdout);
}
int main() {
    fast;
    ll n;cin >> n;
    vector<po> pos;
    
    for (ll i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        pos.pb({x, y, i + 1});
    }

    double tkc = DBL_MAX;
    ll res = -1;

    for (ll i = 0; i < n; ++i) {
        double sum = 0.0;
        for (ll j = 0; j < n; ++j) {
            if (i == j) continue;
            ll dx = pos[j].x - pos[i].x;
            ll dy = pos[j].y - pos[i].y;
            sum += sqrt(dx * dx + dy * dy);
        }
        
        if (sum < tkc) {
            tkc = sum;
            res = pos[i].index;
        } else if (sum == tkc) {
            if (pos[i].index < res) {
                res = pos[i].index;
            }
        }
    }

    cout << res << " " << fixed << setprecision(3) << tkc << endl;

}