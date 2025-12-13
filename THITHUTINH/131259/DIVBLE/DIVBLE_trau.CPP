// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define file "DIVBLE"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define maxn 1000006


int n;
int64 a[maxn];
int64 cnt;
int64 cnt0, cnt1, cnt2;


void sub1(){
    f0(i, 0, n-1){
        f0(j, i+1, n-1){
            if((a[i] + a[j])%3==0){
                cnt++;
                //cout<<a[i]<<" "<<a[j]<<'\n';
            }
        }
    }

    cout<<cnt;
}


void sub2(){
    cout<< (cnt0*(cnt0-1))/2 + (cnt1*cnt2);
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r", stdin);
    freopen(file".ans","w", stdout);

    cin>>n;

    f0(i, 0, n-1){
        cin>>a[i];
        if(a[i]%3==0){
            cnt0++;
        }else if(a[i]%3==1)cnt1++;
        else if(a[i]%3==2)cnt2++;
    }

    sub1();

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
