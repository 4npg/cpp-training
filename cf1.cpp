#include<bits/stdc++.h>
using namespace std;

#define f0(i, a, b) for(int i = (a); i <= (b); ++i)
#define fd(i, a, b) for(int i = (a); i >= (b); --i)

#define TIME (1.0*clock()/CLOCKS_PER_SEC)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e6+5;
const int mod = 1e9+7;
const int inf = 1e9;

template <class X, class Y > bool maximize(X &a, Y b){
	if(a < b) return a = b, true;
	return false;
}

template <class X, class Y > bool minimize(X &a, Y b){
	if(a > b) return a = b, true;
	return false;
}

long long a[maxn];
int n, q;

struct seg{
	int n; vector<long long> t;

	seg(int _n){
		n = _n;
		t.resize(4*n+5);
	}

	// void build(int id, int l, int r){
	// 	if(l == r){
	// 		t[id] = a[l];
	// 		return;
	// 	}

	// 	int mid = (l + r)/2;
	// 	build(id*2, l, mid);
	// 	build(id*2+1, mid+1, r);

	// 	t[id] = t[id*2] + t[id*2+1];
	// }

	inline void update(int id, int l, int r, int p, long long x){
		if( l == r ){
			t[id] += x;
			return ;
		}

		int mid = (l + r)/2;
		if( p <= mid )update(id*2, l, mid, p, x);
		else update(id*2+1, mid+1, r, p, x);

		t[id] = t[id*2] + t[id*2+1];
	}

	long long get(int id, int l, int r, int u, int v){
		if(v < l || r < u) return 0;
		if( u <= l && r <= v)return t[id];

		int mid = (l + r)/2;
		long long tl = get(id*2, l, mid, u, v);
		long long tr = get(id*2+1, mid+1, r, u, v);

		return tl + tr;
	}
};


struct seg2{
	int n; vector<long long> t;

	seg2(int _n){
		n = _n; 
		t.resize(4*n+5);
	}
};


template < class dataT >
struct fenwick{
	int n;
	vector<dataT> bit;

	fenwick(int _n): n(_n), bit(n+1, 0){}

	void add(int i, dataT val){
		for(; i<=n; i+=i&-i) bit[i] += val;
	}
	
	void updateRage(int l, int r, int v){
		// add(l, v);
		// add(r+1, -v);
		add(l, (n-l+1)*v);
		add(r+1, -(n-r)*v);
		add(l, v);
		add(r+1, -v);
	}

	dataT sum(int i){
		dataT s = 0;
		for(; i>0; i-=i&-i) s += bit[i];
		return s;
	}

	dataT get(int l, int r){
		return sum(r) - sum(l-1);
	}
};

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	// int bla = uniform_int_distribution<int>(1, 100)(rng);

	// cout<<bla;

	cin >> n >> q;


	fenwick<long long> fw(n);

	f0(i, 1, n){
		cin>>a[i];

		fw.add(i, a[i]);
	}

	while(q--){
		int op, u;

		cin>>op>>u;
		if(op == 1){
			long long v; cin>>v;
			fw.add(u, v);
		}else {
			int v; cin>>v;
			cout<< fw.get(u, v)<<'\n';
		}
	}

	
	/* seg attempt 
	seg sg(n);

	f0(i, 1, n){
		cin>> a[i];

		sg.update(1, 1, n, i, a[i]);
	}

	// sg.build(1, 1, n);

	// cin>>q;
	while(q--){
		int op, u;

		cin>>op>>u;
		if(op == 1){
			long long v; cin>>v;
			sg.update(1, 1, n, u, v);
		}else {
			int v; cin>>v;
			cout << sg.get(1, 1, n, u, v)<<'\n';
		}
	}
	
	*/

	
	cerr << "\ntime elapsed:" << TIME << "s.\n";
}