// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file ""

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 1000006
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)

int n, k;
int64 a[maxn];
int64 cnt = 0;

void sub1(){
	f0(i, 0, n-1){
		f0(j, i+1, n-1){
			if(i != j){
				if((a[i] + a[j])%k == 0)cnt++;
			}
		}
	}
	
	cout<<cnt;
}


con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>k;
	vector<int64> freq(n+1, 0);
	f0(i, 0, n-1){
		cin>>a[i];
		freq[a[i]%k]++;
	}

	cnt += (freq[0] * (freq[0]-1))/2;

	if(k%2==0)cnt+=(freq[k/2] * (freq[k/2]-1))/2;

	f0(r, 1, (k-1/2)){
		cnt+=(freq[r]*freq[k-r]);
	}

	cout<<cnt;
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
