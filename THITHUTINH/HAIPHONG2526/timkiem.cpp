// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 1000006
#define pb push_back

int n;
int64 a[maxn];
int64 b[maxn];
vector<int64> nto;
int64 d[maxn];
bool pr[maxn];

int64 cnt(int64 x){
	int res = 1;
	for(auto p:nto){
		if(1ll*p*p>x)break;
		if(x%p==0){
			int cnt = 0;
			while(x%p==0){
				x/=p;
				cnt++;
			}
			res *=(cnt+1);
		}
	}
	if(x>1)res*=2;
	return res;
}


void sangdoan(int64 l, int64 r){
	for(int i=2; i<=maxn; i++){
		int64 st = (l+i-1)/i*i;
		for(int j=0; st+j<=r; j+=i)if(st+j!=i)pr[st+j-l] = 1;
	}
	for(int i=0; i<=r-l; ++i){
		if(!pr[i] && i+l>1){
			nto.pb(i+l*1ll);
		}
	}
}
void sub2(){
	stack<int64> st;

	f0(i, 0, n-1){
		while(!st.empty() && d[i] > d[st.top()]){
			b[st.top()] = a[i];
			st.pop();
		}
		st.push(i);
	}

	f0(i, 0, n-1){
		cout<<b[i]<<" ";
	}
}

i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	if(n<=100000){
		nto.clear();
		sangdoan(1, 1000000);	
	}else{
		nto.clear();
		sangdoan(100000, 1000000000);
	}
	f0(i, 0, n-1){
		cin>>a[i];
		d[i] = cnt(a[i]);
		b[i] = -1;
	}
	

	sub2();	

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


