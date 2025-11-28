// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define fi first 
#define se second
#define pb push_back

int n;
int maxa = INT_MIN;

int gcd(int a, int b){
    if(b==0)return a;
    return gcd(b, a%b);
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);

    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxa = max(maxa, a[i]);
    } 

    vector<vector<pair<int,int>>> vec(maxa+1);

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int g = gcd(a[i], a[j]);
            vec[g].pb({i,j});
        }
    }

    int ans = 0;

    for(int g1=maxa; g1>=1; g1--){
        if(vec[g1].size() == 0) continue;

        for(int g2=g1; g2>=1; g2--){
            if(vec[g2].size() == 0) continue;

            bool ok = false;

            for(auto p1 : vec[g1]){
                int i1 = p1.fi;
                int j1 = p1.se;
                for(auto p2 : vec[g2]){
                    int i2 = p2.fi;
                    int j2 = p2.se;
                    if(i1!=i2 && i1!=j2 && j1!=i2 && j1!=j2){
                        if(g1==g2) {
                            if(i1!=i2 || j1!=j2){
                                ok = true;
                                break;
                            }
                        } else ok = true;
                    }
                
                    if(ok) break;
                
                }

                if(ok){
                    ans = max(ans, g1 + g2);
                    break; 
                }
            }
        }
    }

    cout << ans;
    // cerr<<"time elapsed: "<<TIME<<"s.\n";
}
