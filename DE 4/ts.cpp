#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> sang(int n) {
    vector<char> is(n+1, true);
    is[0]=is[1]=false;
    for (int i=2;i*i<=n;i++) if (is[i])
        for (int j=i*i;j<=n;j+=i) is[j]=false;
    vector<int> nto;
    for (int i=2;i<=n;i++) if (is[i]) nto.push_back(i);
    return nto;
}

ll vp(ll n, int p){
    ll cnt = 0;
    while (n) {
        n /= p;
        cnt += n;
    }
    return cnt;
}

mt19937 rd(time(0));

int Rand(int l, int r){
	return l + rd()%(r-l+1);
}

void sinh(int n, int m){
    m = Rand(1,20);
    n = Rand(m,20);
    ofstream fuck("in.txt");
    fuck<<n<<" "<<n;
}

void thuong(int n, int m){
    cin>>n>>m;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m,n;
    cin>>n>>m;
    if(n==m){
        cout<<0;
        return 0;
    }
    auto nto = sang(n);
    int ans = 0;
    for (int p : nto) {
        ll e = vp(n, p) - vp(m, p) - vp(n - m, p);
        if (e > 0) ans++;
    }
    cout << ans << '\n';
}
