#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define pb push_back

int main() {
    fast;
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<int> res;
    for (int i = 1; i <= n; i++) {
        res.pb(i);
    }

    vector<int> a(n);

    for (int i = n - 1; i >= 0; i--) {
        int idx = res.size() - p[i] - 1; 
        cout<<res[idx]<<" "<<idx<<" "<<p[i]<<"\n";
        a[i] = res[idx];
        res.erase(res.begin() + idx); 
    }
cout<<'\n';
    for (int num : a) {
        cout << num << " ";
    }
}
