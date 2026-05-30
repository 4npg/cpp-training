#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file ""

#define f0(i, a, b) for(int i = (a); i <= (a); ++i)
#define fd(i, a, b) for(int i = (a); i >= (b); --i)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int inf = 1e9+7;
const int mod = 1e9+7;
const int maxn = 1e6+5;

template <class X, class Y> bool maximize(X &a, Y b){
    if(a < b) return a = b, true;
    return false;
}

template <class X, class Y> bool minimize(X &a, Y b){
    if(a > b) return a= b, true;
    return false;
}

int n, k;
long long a[maxn];
long long sum;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 
    // int bla = uniform_int_distribution<int>(1, 100)(rng);

    cin >> n >> k;

    f0(i, 1, n){
    	cin >> a[i];
    	sum += a[i];	
    } 

    if ( sum % k == 0 ){
    	sum /= k;
    } else {
    	cout << "ze";
    	return 0;
    }

    
    cerr << "\ntime elapsed: "<<TIME<<"s.\n";
}