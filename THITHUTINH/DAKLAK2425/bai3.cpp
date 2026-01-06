// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file "bai3"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 1000006
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int n, q;
long long d[maxn], pre[maxn], a[maxn];

void sub1(){
	long long sz = 0;
	f0(i, 1, n){
		long long u, v; cin>>u>>v;
		d[u] += 1;
		d[v+1] -= 1;
		sz = max(sz, v);
	}

	f0(i, 1, sz){
		d[i] += d[i-1];
	}
	f0(i, 1, sz)a[i] += d[i];
	cin>>q;
	while(q--){
		int x; cin>>x;
		cout<<a[x]<<'\n';
	}
}
con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n; 

	vector<long long> u(n), v(n);
    vector<long long> toado;

    for(int i = 0; i < n; i++){
        cin >> u[i] >> v[i];
        toado.emplace_back(u[i]);
        toado.emplace_back(v[i] + 1);
    }

    int q;
    cin >> q;
    vector<long long> x(q);

    for(int i = 0; i < q; i++){
        cin >> x[i];
        toado.emplace_back(x[i]);
    }

    sort(toado.begin(), toado.end());
    toado.erase(unique(toado.begin(), toado.end()), toado.end());

    int m = toado.size();
    vector<int> d(m + 2, 0);

    for(int i = 0; i < n; i++){
        int l = lower_bound(toado.begin(), toado.end(), u[i]) - toado.begin() + 1;
        int r = lower_bound(toado.begin(), toado.end(), v[i] + 1) - toado.begin() + 1;
        d[l]++;
        d[r]--;
    }

    for(int i = 1; i <= m; i++)
        d[i] += d[i-1];

    for(int i = 0; i < q; i++){
        int id = lower_bound(toado.begin(), toado.end(), x[i]) - toado.begin() + 1;
        cout << d[id] << '\n';
    }
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
