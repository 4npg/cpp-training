// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "money"
#define int64 long long
#define f0(i, a, b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define maxn 100

int n, s;
int a[maxn];

void sub1(){
    sort(a+1, a+n+1, greater<int>());

    int cnt = 0;
    int i = 1;
    while(s>0){
        if(s>=a[i]){
            while(s>=a[i]){
                s-=a[i];
                cnt++;
            }
        }else i++;
    }

    cout<<cnt;
}


int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".ans","w",stdout);

    cin>>n>>s;
    f0(i, 1, n)cin>>a[i];

    sub1();

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
