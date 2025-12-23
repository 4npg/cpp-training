// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int i=(a); (i)>=(b); --i)
#define file ""

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 100005

int n, q;
int b[maxn];
int a[maxn];

void update(int i, int x){
	while(i <= n){
		b[i] += x;
		i += (i&(-i));
	}
}

int get(int i){
	int res = 0;
	while(i){
		res += b[i];
		i -= (i&(-i));
	}
	return res;
}

int chat(int x){
	int l = 1, r = n;
	int res = -1;
	while(l <= r){
		int mid = (l+r)/2;
		if(a[mid] + get(mid) >= x){
			res = mid;
			r = mid - 1;
		}else l = mid+ 1;
	}
	return res;
}

youngboiz_nobug(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n;
	f0(i, 1, n)cin>>a[i];

	sort(a+1, a+n+1);
	cin>>q;
	while(q--){
		int x; cin>>x;
		int j = chat(x);
		if(j == -1)cout<<-0<<'\n';
		else cout<<n-j+1<<'\n', update(j, -1);
	}
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
