// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file ""

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//    return l+rng()%(r-l+1);
//}

#define maxn 10000007
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)
#define pb push_back

int l, r;
vector<int> ans;
bool d[maxn];

void sang(){
    d[0] = d[1] = 1;

    for(int i = 2; i*i<maxn; ++i){
        if(d[i] == 0){
            for(int j=i*i; j<maxn; j+=i)d[j] = 1;
        }
    }
}

int tcs(int x){
    int sum = 0;
    while(x){
        if(x%10 != 2 && x%10 != 3 && x%10 != 5 && x%10 != 7)return -1;
        else{
            sum += x%10;
            x/=10;
        }
    }
    return sum;
}

void de(){
    sang();
    f0(i, 1, 30000){
        if(!d[i] && tcs(i) != -1 && !d[tcs(i)]){
            ans.pb(i);
        }
    }
    for(auto &x:ans)cout<<x<<", ";
}

void sub2(){
    vector<int> hople = {2, 3, 5, 7, 23, 223, 227, 337, 353, 373, 557, 577, 733, 757, 773, 2333, 2357, 2377, 2557, 2753, 2777, 3253, 3257, 3323, 3527, 3727, 5233, 5237, 5273, 5323, 5527, 7237, 7253, 7523, 7723, 7727, 22573, 23327, 25237, 25253, 25523, 27253, 27527};

    cin>>l>>r;
    int ub = upper_bound(hople.begin(), hople.end(), r) - hople.begin();
    int lb = lower_bound(hople.begin(), hople.end(), l) - hople.begin();

    cout<<ub-lb;   
}

void sub1(){
    cin>>l>>r;
    sang();
    int cnt = 0;
    for(int i=l; i<=r; i++){
        if(!d[i] && tcs(i)!=-1 && !d[tcs(i)])cnt++;
    }
    cout<<cnt;
}
con_meo_dua_leo(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout); 

    sub1();
    
    cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
