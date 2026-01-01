// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b);++i)
#define fd(i,a,b) for(int i = (a); i >= (b);--i)
#define file ""

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 1000006
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int n, a[maxn], d[maxn];
vector<int> fac[maxn];

void sang(){
	for(int i=2; i<maxn; ++i){
		if(d[i] == 0){
			for(int j=i; j<maxn; j+=i){
				if(d[j] == 0)d[j] = i;
			}
		}
	}

	f0(i, 2, maxn-1){
		int x = i;
		while(x>1){
			int p = d[x];
			fac[i].emplace_back(p);
			while(x%p == 0)x/=p;
		}
	}
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	sang();

	cin>>n;
	f0(i, 1, n){
		cin>>a[i];
	}

	vector<int> lpos(maxn, -1);
	vector<int> lres(n+1, -1);

	f0(i, 1, n){
		int bj = -1;
		int midist = INT_MAX;

		for(int p : fac[a[i]]){
			if(lpos[p] != -1){
				int dist = i - lpos[p];
				if(dist < midist || (dist == midist && lpos[p] < bj)){
					midist = dist;
					bj = lpos[p];
				}
			}
		}

		lres[i] = bj;

		for(int p : fac[a[i]])lpos[p] = i;
	}

	fill(lpos.begin(), lpos.end(), -1);

	vector<int> rres(n+1, -1);

	fd(i, n, 1){
		int bj = -1;
		int midist = INT_MAX;

		for(int p : fac[a[i]]){
			if(lpos[p] != -1){
				int dist = lpos[p] - i;
				if(dist < midist || (dist == midist && lpos[p] < bj)){
					midist = dist;
					bj = lpos[p];
				}
			}
		}

		rres[i] = bj;

		for(int p:fac[a[i]])lpos[p] = i;
	}


	f0(i, 1, n){
		int resj=-1;
        if(lres[i]!=-1 && rres[i]!=-1){
            int dl = abs(i - lres[i]);
            int dr = abs(i - rres[i]);
            if(dl<dr) resj=lres[i];
            else if(dr<dl) resj=rres[i];
            else resj=min(lres[i], rres[i]);
        }
        else if(lres[i]!=-1) resj=lres[i];
        else if(rres[i]!=-1) resj=rres[i];
        cout<<resj<<" ";
	}

	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
