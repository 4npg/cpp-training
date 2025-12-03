#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "tenbai"
#define nl cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll i=a;i<=b;++i)
#define fi first
#define se second
#define pb push_back
#define all(a) (a).begin(),(a).end()

int32_t main() {
    fast;
    if (fopen(TASK ".inp","r")) {
        freopen(TASK ".inp","r",stdin);
        freopen(TASK ".out","w",stdout);
    }

    map<pair<ll,ll>,ll> cnt;
    FOR(i,1,6) {
        ll w,h; cin>>w>>h;
        if (w>h) swap(w,h);
        cnt[{w,h}]++;
    }

    if (cnt.size()!=3) return cout<<"NO",0;

    for (auto &p : cnt)
        if (p.se != 2) return cout<<"NO",0;

    vector<pair<ll,ll>> f; for (auto &p : cnt) f.pb(p.fi);

    multiset<ll> canh;
    for (auto &p : f) canh.insert(p.fi), canh.insert(p.se);

    cout << ((canh.size()==6 && set<ll>(all(canh)).size()==3) ? "YES" : "NO");
}
