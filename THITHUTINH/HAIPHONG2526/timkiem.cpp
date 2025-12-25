// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 1000006
#define pb push_back

int n;
int64 a[maxn];
int64 b[maxn];
int64 mi = 1e9;
int64 ma = -1e9;
vector<int64> nto;
int d[maxn];
int64 rem[maxn];
int dv[maxn];

void sang(){
    d[0] = d[1] = 1;

    for(int i=2; i*i<maxn; i++){
        if(d[i] == 0){
            for(int j=i*i; j<maxn; j+=i){
                d[j] = 1;
            }
        }
    }

    f0(i, 2, maxn-1)if(!d[i])nto.pb(i);
}

void sangdoan(int64 l, int64 r){
    int len = r - l + 1;

    f0(i, 0, len-1){
    	rem[i] = l + i;
    	dv[i] = 1;
    }

    for(int p:nto){
    	if(1ll*p*p>r)break;

    	int64 st = max(1ll*p*p, ((l+p-1)/p)*p);

    	for(int64 x=st; x<=r; x+=p){
    		int i = x -l;
    		int cnt = 0;
    		while(rem[i] % p == 0){
    			rem[i] /= p;
    			cnt++;
    		}
    		if(cnt)dv[i] *= (cnt+1);
    	}
    }
    f0(i, 0, len-1){
    	if(rem[i]>1)dv[i]*=2;
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

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n;
	f0(i, 0, n-1){
		cin>>a[i];
		mi = min(mi, a[i]);
		ma = max(ma, a[i]);
		b[i] = -1;
	}
	
	sang();
	sangdoan(mi, ma);

	f0(i, 0, n-1)
		d[i] = dv[a[i] - mi];

	sub2();	

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


