// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define file "PASS"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

string s;
int64 cnt;

bool isdit(char c){
    return (c>='0' && c<='9');
}

bool isthuong(char c){
    return (c>='a' && c<='z');
}

bool ishoa(char c){
    return (c>='A' && c<='Z');
}

bool isdb(char c){
    char db[] = {'!', '@', '#', '$', '%', '&', '*', '?'};

    f0(i, 0, 7){
        if(c==db[i])return true;
    }
    return false;
}
bool valid(string s){
    int tt = 0;
    int th = 0;
    int ts = 0;
    int tdb = 0;

    for(auto &c:s){
        if(isdit(c))ts++;
        if(isthuong(c))tt++;
        if(ishoa(c))th++;
        if(isdb(c))tdb++;
    }
    return ((s.size()>=8)&&(ts>=1)&&(tt>=1)&&(th>=1)&&(tdb>=1));
}


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    cin>>s;
    int n = s.size();

    f0(i, 0, n-1){
        f0(j, i+1, n-1){
            if(valid(s.substr(i, j-i+1))){
                cnt++;
            }
        }
    }

    cout<<cnt;
    //cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
