#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
pair<ll, pair<ll, ll>> xuLy(const ll mang[], ll k) {
    ll tongMax = -1e18, tongHienTai = 0;
    ll vt_bd = 0, tamBd = 0, vt_kt = -1;
    for (ll i = 0; i < k; i++) {
        tongHienTai += mang[i];
        if (tongHienTai > tongMax) {
            tongMax = tongHienTai;
            vt_bd = tamBd;
            vt_kt = i;
        }
        if (tongHienTai < 0) {
            tongHienTai = 0;
            tamBd = i + 1;
        }
    }
    return {tongMax, { vt_bd, vt_kt}};
}

int main() {
    ll m, n;
    cin >> m >> n;
    
    ll a[110][110];
    for (ll i = 0; i < m; i++){
        for (ll j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    
    ll tam[110] = {0};
    ll tong_max = -1e18;
    ll ax = 0, bx = 0, ay = 0, by = 0;
    for (ll l = 0; l < n; l++) {
        for (ll i = 0; i < m; i++) {
            tam[i] = 0;
        }
        for (ll r = l; r < n; r++) {
            for (ll i = 0; i < m; i++) {
                tam[i] += a[i][r];
            }
            auto res = xuLy(tam, m);
            ll tongHT = res.fi;
            ll vt_bd = res.se.fi, vt_kt = res.se.se;
            
            if (tongHT > tong_max) {
                tong_max = tongHT;
                ax = l;
                bx = r;
                ay = vt_bd;
                by = vt_kt;
            }
        }
    }
    
    cout << tong_max << "\n";
    cout << ay << " " << ax << " " << by << " " << bx << "\n";
    
 
}