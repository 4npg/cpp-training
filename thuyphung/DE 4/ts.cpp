// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 1000006

int n, k;
bool d[maxn];
int cnt;
void sang(){
    d[0] = d[1] = 1;
    for(int i = 2; i*i<maxn; i++){
        if(d[i] == 0){
            for(int j = i*i; j<maxn; j+=i)d[j] = 1;
        }
    }
}


int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>n>>k;
    sang();

    f0(x, 2, n-k){
        if(!d[x] && !d[x+k])cnt++;
    }

    cout<<cnt;
    cerr << "time elapsed: "<<TIME <<"s.\n";
}


