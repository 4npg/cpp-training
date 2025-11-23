// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "RANNUM"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define maxn 100005
#define pb push_back
#define all(a) (a).begin(),(a).end()

int n;
int a[maxn];


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".ans","w",stdout);

    cin>>n;
    f0(i,0,n-1)cin>>a[i];

    int ans = n;
    vector<int> val(n);
    f0(i,0,n-1)val[i] = a[i];
    sort(all(val));
    val.erase(unique(all(val)),val.end());

    for(auto &x:val){
        int bestk = n;

        f0(k,1,n){
            bool ok = true;

            for(int l = 0; l+k-1<n; ++l){
                bool found = false;
                for(int i = l; i<l+k;++i){
                    if(a[i]==x){
                        found = true;
                        break;
                    }
                }
                if(!found){
                    ok = false;
                    break;
                }
            }
            if(ok){
                bestk = k;
                break;
            }
        }
        ans = min(ans,bestk);
    }

    cout<<ans;

    //cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}

