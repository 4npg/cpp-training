#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define file "task"
int n, k;
vector<int64> a;

int64 dfs(int pos, int last){
    if(pos > n) return 0;
    int64 res = 0;

    res = dfs(pos+1, last);

    if(last == -1 || pos > last && pos <= last + k){
        res = max(res, a[pos] + dfs(pos+1, pos));
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".ans","w",stdout);
    cin >> n >> k;
    a.resize(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];

    cout << dfs(1, -1);
}
