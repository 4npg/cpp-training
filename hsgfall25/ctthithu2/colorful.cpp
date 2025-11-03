// author : anphung
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define file "remk"
#define f0(i,a,b) for(int i=(a); i<=(b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)

int n;
string s;

void sub1(){
    double mind = 1e9;
    int lans=1, rans=1;
    f0(l,0,n-1){
        set<char> sub;
        f0(r,l,n-1){
            sub.insert(s[r]);
            int len = r-l+1;
            int cnt = sub.size();
            double d = (double)cnt / len;
            if(d < mind){
                mind = d;
                lans = l+1;
                rans = r+1;
            }
        }
    }
    cout << lans << " " << rans << "\n";
}

void sub2(){
    int freq[256] = {0};
    int unique = 0;
    int l = 0, lans=1, rans=1;
    double mind = 1e9;

    for(int r=0; r<n; r++){
        if(freq[s[r]]==0) unique++;
        freq[s[r]]++;

        double d = (double)unique / (r-l+1);
        if(d < mind){
            mind = d;
            lans = l+1;
            rans = r+1;
        }
    }

    cout << lans << " " << rans << "\n";
}


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    //freopen(file".out","w",stdout);
    cin>>n>>s;

    sub1();
    cout<<'\n';
    sub2();

    cerr << "time elapsed: " << TIME << "s.\n";
}
