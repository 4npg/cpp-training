#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file ""

#define f0(i, a, b) for(int i = (a); i <= (b); ++i)
#define bit(mask, i) ((mask>>i)&1)

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

#define data vector < int >

int n, k;
data sub;
set< data > ans;

void Try(int pos){
	int last = ( sub.empty() ? 0 : sub.back() );

	f0(i, last+1, n){
		if( sub.empty() || last != i){
			sub.emplace_back(i);
			if(sub.size() == k){
				data vsub = sub;
				sort(vsub.begin(), vsub.end());
				do{
					ans.insert(vsub);
				} while(next_permutation(vsub.begin(), vsub.end()));
			}else Try(pos+1);
			sub.pop_back();
		}
	}
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 

    int bla = uniform_int_distribution<int>(1, 10)(rng);
    int bla2 = uniform_int_distribution<int>(1, bla-1)(rng);
    // n = bla; k = bla2;
    // cout << "n = " << n << ", k = " << k << '\n';
    	
    cin >> n >> k;
    
    Try(1);

    for(auto &x : ans){
    	for(auto &v : x){
    		cout << v << " ";
    	}
    	cout << '\n';
    }
    cerr << "\ntime elapsed: "<<TIME<<"s.\n";
}