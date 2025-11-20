#include<bits/stdc++.h>
using namespace std;
#define int64 long long 
#define file "BAI3"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

string s;
int n;
int mem[2005][27]; 

int f(int i, int last){
    if(i == n) return 0;
    if(mem[i][last+1] != -1) return mem[i][last+1];

    int res = f(i+1, last);

    int cur_idx = s[i]-'A';
    if(last == -1 || cur_idx >= last)
        res = max(res, 1 + f(i+1, cur_idx));

    return mem[i][last+1] = res;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    cin>>s;
    n = s.size();

    memset(mem,-1,sizeof(mem));

    cout << f(0,-1);
}
