// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file ""

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 100005
#define all(a) (a).begin(), (a).end()

int n;
int a[maxn];
vector<int> nen;
int t[maxn*4];

void update(int id, int l, int r, int p){
	if(l == r){
		t[id] += 1;
		return;
	}

	int mid = (l+r)/2;
	if(p<=mid)update(id*2, l, mid, p);
	else update(id*2+1, mid+1, r, p);

	t[id] = t[id*2] + t[id*2+1];
}

int get(int id, int l, int r, int u, int v){
	if(v<l || r<u)return 0;
	if(u<=l && r<=v)return t[id];

	int mid = (l+r)/2;
	int tl = get(id*2, l, mid, u, v);
	int tr = get(id*2+1, mid+1, r, u, v);
	return tl + tr;
}
youngboiz_nobug(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n;
	nen.resize(n);
	f0(i, 0, n-1)cin>>a[i], nen[i] = a[i];

	sort(all(nen));
	nen.erase(unique(all(nen)),nen.end());

	f0(i, 0, n-1)a[i] = lower_bound(all(nen), a[i]) - nen.begin() + 1;

	int64 ans = 0;
	f0(i, 0, n-1){
		if(a[i] + 1 <= nen.size()){
			ans += get(1, 1, nen.size(), a[i] + 1, nen.size());
		}
		update(1, 1, nen.size(), a[i]);
	}

	cout<<ans;
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
