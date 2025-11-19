// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define file "HANGCAY"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define maxn 3000006

int n;
int64 t, h[maxn];
int len=1;

void sub1(){
    f0(i,0,n-1){
        int64 miH = h[i], maH = h[i];
        f0(j,i,n-1){
            miH = min(miH, h[j]);
            maH = max(maH, h[j]);
            if(maH - miH <= t){
                len = max(len,j-i+1);
            }else break;
        }
    }
    cout<<len;
}

void sub2(){
    deque<int> dqMin, dqMax;
    int l = 0, ans = 1;
    f0(r,0,n-1){
        while(!dqMax.empty() && h[dqMax.back()] < h[r])dqMax.pop_back();
        dqMax.push_back(r);

        while (!dqMin.empty() && h[dqMin.back()] > h[r]) dqMin.pop_back();
        dqMin.push_back(r);

        while (h[dqMax.front()] - h[dqMin.front()] > t) {
            if (dqMax.front() == l) dqMax.pop_front();
            if (dqMin.front() == l) dqMin.pop_front();
            l++;
        }
        ans = max(ans, r-l+1);
    }
    cout<<ans;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    cin>>n>>t;
    f0(i,0,n-1)cin>>h[i];

    sub2();

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
