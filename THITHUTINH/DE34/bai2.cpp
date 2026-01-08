// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)

con_meo_dua_leo(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int m, n;
    cin >> m >> n;
    vector<int> a(m), b(n);
    f0(i,0,m-1) cin >> a[i];
    f0(i,0,n-1) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;
    f0(bi,0,n-1){
        int bi_val = b[bi];
        bool f = false;
        for(int i=0; i<a.size()-1 && !f; i++){
            for(int j=i+1; j<a.size() && !f; j++){
                if((a[i] < bi_val && bi_val < a[j]) || (a[j] < bi_val && bi_val < a[i])){
                    a.erase(a.begin()+j);
                    a.erase(a.begin()+i);
                    ans++;
                    f = true;
                }
            }
        }
    }

    cout << ans;
    cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
