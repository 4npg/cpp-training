// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 200005

struct Node{
	int64 sum, pref, suff, ans;
};

Node t[maxn*4];
int a[maxn];
int n,q;

Node mergeNode(const Node &l, const Node &r){
	Node res;
	res.sum = l.sum + r.sum;
	res.pref = max(l.pref, l.sum + r.pref);
	res.suff = max(r.suff, r.sum + l.suff);
	res.ans = max({l.ans,r.ans,l.suff+r.pref});
	return res;
}

Node makeNode(int64 x){
	Node res;
	res.sum = x;
	int64 v = max((int64)0,x);
	res.pref = res.suff = res.ans = v;
	return res;
}

void build(int id, int l, int r){
	if(l==r){
		t[id] = makeNode(a[l]);
		return;
	}
	int mid = (l+r)/2;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);
	t[id] = mergeNode(t[id*2], t[id*2+1]);
}

void update(int id, int l, int r, int pos, int64 val){
	if(l==r){
		t[id] = makeNode(val);
		return ;
	}
	int mid = (l+r)/2;
	if(pos<=mid) update(id*2, l, mid, pos, val);
	else update(id*2+1, mid+1, r, pos, val);
	t[id] = mergeNode(t[id*2], t[id*2+1]);
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	f0(i,1,n)cin>>a[i];

	build(1,1,n);
	while(q--){
		int k;
		int64 x;
		cin>>k>>x;
		update(1,1,n,k,x);
		cout<<t[1].ans<<'\n';
	}

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


