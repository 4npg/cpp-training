// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define file "MIT"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define maxn 100005

int n;

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);
    cin>>n;
    set<int> st;
    f0(i,0,n-1){
    	int x;cin>>x;
    	st.insert(x);
    }

    cout<<st.size()<<'\n';
    for(auto &l:st)cout<<l<<" ";
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
