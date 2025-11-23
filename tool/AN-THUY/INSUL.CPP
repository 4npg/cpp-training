// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "INSUL"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define maxn 100005
#define pb push_back

int n;
int a[maxn];
int64 sum = 0;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    cin>>n;
    f0(i,0,n-1)cin>>a[i],sum+=a[i];

    sort(a,a+n);

    int i = 0, j = n-1;
    vector<int> b;
    while(i<=j){
        b.pb(a[i++]);
        if(i<=j)b.pb(a[j--]);
    }

    f0(k,1,n-1){
        if(b[k] > b[k-1])sum+= ( b[k] - b[k-1] );
    }

    cout<<sum;

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
