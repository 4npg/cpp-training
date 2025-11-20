// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define file "BAI1"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define maxn 1000006

int n;
int64 a[maxn];
int64 ans[maxn];

void sub1(){
    f0(i,0,n-1){
        bool ok = false;
        f0(j,i+1,n-1){
            if(a[j]>a[i]){
                cout<<a[j];
                ok = true;
                break;
            }
        }
        cout<<" ";
        if(ok == false)cout<<0<<" ";
    }
}

void sub2(){
    stack<int64> st;
    for(int i = n-1; ~i; i--){
        while(!st.empty() && a[st.top()]<=a[i]){
            st.pop();
        }

        if(st.empty())ans[i] = 0;
        else ans[i] = a[st.top()];
        st.push(i);
    }

    f0(i,0,n-1)cout<<ans[i]<<" ";
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    cin>>n;
    f0(i,0,n-1)cin>>a[i];

    sub2();
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
