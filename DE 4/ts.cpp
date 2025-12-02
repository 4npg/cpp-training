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
    string s;
     getline(cin,s);
    ll n = s.size(), res = 0;
    vector<ll> pre(n+1,0);
    for(int i=0; i<n; ++i)
    {
        if(s[i] == '0') pre[i+1] = pre[i] - 1;
        else pre[i+1] = pre[i] + 1;
    }
    unordered_map<ll ,ll> cnt;
    for(int i = 1; i<=n+1; ++i){
        res += cnt[pre[i]];
        cnt[pre[i-1]]++;
    }
    cout << res;

}
