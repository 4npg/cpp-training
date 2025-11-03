// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "minprod"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define maxn (int)1e5+10
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()

int n;
int64 a[maxn],b[maxn];


void sub1(){
    int64 ans = -1e6;
    f0(i,0,n-1){
        f0(j,0,n-1){
            if(i!=j){
                ans = max(ans,min(a[i]*a[j]*1ll,b[i]*b[j]*1ll));
            }
        }
    }
    cout<<ans;
}

bool cmpa(int i,int j){
    return a[i]>a[j];
}

bool cmpb(int i,int j){
    return b[i]>b[j];
}

void sub2(){
    const int K = 500;
    vector<int> idx(n);
    iota(all(idx), 0);

    sort(idx.begin(), idx.end(), cmpa);
    vector<int> a_top(idx.begin(), idx.begin() + min(K, n));

    sort(idx.begin(), idx.end(), cmpb);
    vector<int> b_top(idx.begin(), idx.begin() + min(K, n));

    vector<int> cand = a_top;
    cand.insert(cand.end(), b_top.begin(), b_top.end());

    sort(all(cand));
    cand.erase(unique(cand.begin(), cand.end()), cand.end());

    int64 ans = LLONG_MIN;
    f0(i,0,(int)cand.size()-1){
        f0(j,i+1,(int)cand.size()-1){
            int u = cand[i], v = cand[j];
            int64 val = min(a[u]*a[v],b[u]*b[v]);
            ans = max(ans,val);
        }
    }

    cout << ans;
}


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);
    cin>>n;
    f0(i,0,n-1)cin>>a[i];
    f0(i,0,n-1)cin>>b[i];
    if(n<=3000)sub1();
    else sub2();
    cerr <<'\n'<< "time elapsed: "<<TIME <<"s.\n";
}
