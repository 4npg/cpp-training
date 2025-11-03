// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "demsoduk"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)

int n,k;
const int maxn = 300006;
int a[maxn];
int cnt[maxn];
const int MAXA = 1000006;
int freq[MAXA];

void sub1(){
    f0(i,0,n-1){
        //cout<<"so "<<a[i]<<": ";
        f0(j,0,n-1){
            if(i!=j){
                if(a[i] % a[j] == k){
                    cnt[i]++;
          //          cout<<a[i]<<" "<<a[j]<<" "<<'\n';
                }
            }
        }
    }
    f0(i,0,n-1){
        cout<<cnt[i]<<" ";
    }
}

void sub2() {
    memset(freq,0,sizeof(freq));
    f0(i,0,n-1)freq[a[i]]++;

    int maxA = 1000000;
    int64 total_gt_k = 0;
    f0(v,k+1,maxA)total_gt_k +=freq[v];
    f0(i,0,n-1){
        int ai=a[i];
        int64 res=0;

        if(ai<k)res = 0;
        else if(ai==k)res=total_gt_k;
        else{
            int x =ai-k;
            for (int d=1;1ll*d*d<=x;++d){
                if(x%d==0) {
                    int d1 = d, d2 = x / d;
                    if(d1>k&&d1<=maxA){
                        res += freq[d1];
                        if (d1 == ai) res--;
                    }
                    if (d2 != d1&&d2 > k&&d2 <= maxA) {
                        res += freq[d2];
                        if (d2 == ai) res--;
                    }
                }
            }
        }
        cnt[i] = res;
    }

    f0(i,0,n-1)cout<<cnt[i]<<" ";
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);
    cin >> n >> k;
    f0(i, 0, n-1) cin >> a[i];

    sub2();
    cerr << "time elapsed: " << TIME << "s.\n";
}
