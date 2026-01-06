// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file ""

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//long long Rand(long long l, long long r){
//	return l+rng()%(r-l+1);
//}

#define maxn 500005
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

struct ant{
	long long x, w;
	int d;
	ant(long long _w=0,long long _x=0,int _d=0) : w(_w), x(_x), d(_d){}

	friend bool operator < (const ant &a, const ant &b){ 
		return a.x<b.x; 
	}
};

struct fen{
	int n;
	long long bit[maxn];
	void init(int _n){ 
		n=_n; 
		f0(i,1,n) 
		bit[i]=0; 
	}
	
	void add(int i,long long v){ 
		while(i<=n){ 
			bit[i]+=v; 
			i+=i&-i; 
		} 
	}
	
	long long sum(int i){ 
		long long s=0; 
		while(i>0){ 
			s+=bit[i]; 
			i-=i&-i; 
		} 
		return s; 
	}
};

int n;
long long l;
ant a[maxn];
long long xs[maxn];

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	
	cin>>n>>l;

	long long total=0;
	f0(i,1,n){
		long long w,x; int d;
		cin>>w>>x>>d;
		a[i]=ant(w,x,d);
		xs[i]=x;
		total+=w;
	}

	vector<pair<long long,long long>> ev;

	f0(i,1,n){
		long long t=(a[i].d==-1 ? a[i].x : l-a[i].x);
		ev.emplace_back(t,a[i].w);
	}

	sort(ev.begin(),ev.end());
	long long need=(total+1)/2,cur=0,T=0;

	for(auto &p:ev){
		cur+=p.second;
		if(cur>=need){ T=p.first; break; }
	}

	sort(xs+1,xs+n+1);
	int m=unique(xs+1,xs+n+1)-xs-1;
	sort(a+1,a+n+1);

	fen bit; bit.init(m);
	long long total_right=0,ans=0;

	f0(i,1,n){
		int id=lower_bound(xs+1,xs+m+1,a[i].x)-xs;
		if(a[i].d==1){ bit.add(id,1); total_right++; }
		else{
			long long lim=a[i].x-2*T;
			if(lim<=0) ans+=total_right;
			else{
				int pos=lower_bound(xs+1,xs+m+1,lim)-xs;
				ans+=total_right-bit.sum(pos-1);
			}
		}
	}

	cout<<ans<<"\n";

	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
