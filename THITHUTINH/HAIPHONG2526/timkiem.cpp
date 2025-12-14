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

vector<int> nto;
int d[maxn];
bool pr[maxn];

int cnt(int x){
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



void sang(){
	pr[0] = pr[1] = 1;

	for(int i=2; i*i<maxn; i++){
		if(pr[i] == 0){
			for(int j=i*i; j<maxn; j+=i){
				pr[j] = 1;
			}
		}
	}

	f0(i, 2, maxn){
		if(!pr[i])nto.pb(i);
	}
}


void sub2(){
	stack<int> st;

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
	sang();
	cin>>n;
	f0(i, 0, n-1){
		cin>>a[i];
		d[i] = cnt(a[i]);
		b[i] = -1;
	}
	
	sub2();	

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


