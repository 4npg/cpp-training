// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    int T;
    if(!(cin>>T)) return 0;
    while(T--){
        int n;
        cin>>n;
        vector<int64> a(n+1,0);
        for(int i=1;i<=n;i++) cin>>a[i];
        vector<int> pref(n+1,0);
        for(int i=1;i<=n;i++){
            pref[i] = (pref[i-1] + (int)(a[i] % 3) ) % 3;
        }
        bool found = false;
        for(int l=1;l<=n-2;l++){
            for(int r=l+1;r<=n-1;r++){
                int s1 = pref[l]%3;
                int s2 = (pref[r] - pref[l]) % 3;
                if(s2<0) s2+=3;
                int s3 = (pref[n] - pref[r]) % 3;
                if(s3<0) s3+=3;
                if( (s1==s2 && s2==s3 && s1==s3) || (s1!=s2 && s1!=s3 && s2!=s3) ){
                	// cout<<"FOUND\n";
                    cout<<l<<" "<<r<<"\n";
                    found = true;
                    // cout<<s1%3<<" "<<s2%3<<" "<<s3%3<<"\n";
                }
            }
        }
        if(!found) cout<<0<<" "<<0<<"\n";
    }
    
    cerr << "time elapsed: "<<TIME <<"s.\n";
    return 0;
}
