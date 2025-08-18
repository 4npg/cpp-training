// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "minkseq"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define f0(i,a,b) for(int (i)=(a);i<=(b);++i)
#define pb push_back
#define pob pop_back
#define all(a) (a).begin(),(a).end()

int t,n,k;
const int maxn = 1e6+5;
int64 a[maxn];
int64 b[maxn];
int64 ans;
vector<int>cur;
bool cmp(int i,int j){
	return a[i]<a[j];
}
void Try(int pos){
	if(cur.size()==k){
		int64 sum = 0,mx = LLONG_MIN;
		for(auto &x:cur){
			mx = max(mx,a[x]);
			sum+=b[x];
		}
		ans = min(ans,sum*mx);
		return;
	}
	if(pos==n)return;
	cur.pb(pos);
	Try(pos+1);
	cur.pob();

	Try(pos+1);
}

void sub1(){
	ans = LLONG_MAX;
	cur.clear();
	Try(0);
	cout<<ans;
	el;
}

void subpq(){
	vector<int> idx(n);
	iota(all(idx),0);
	sort(all(idx),cmp);
	priority_queue<int64> pq;
	int64 ans = LLONG_MAX;
	int64 sum = 0;
	for(auto &x:idx){
		if(pq.size()>=k-1){
			ans = min(ans,a[x]*(b[x]+sum));
		}
		pq.push(b[x]);
		sum+=b[x];
		if(pq.size()>k-1){
			sum-=pq.top();
			pq.pop();
		}
	}
	cout<<ans;
	el;
}
int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    cin>>t;
    while(t--){
    	cin>>n>>k;
    	f0(i,0,n-1)cin>>a[i];
    	f0(i,0,n-1)cin>>b[i];
    	if(n<=20){
    		sub1();
    	}else{
    		subpq();
    	}
    }

}


