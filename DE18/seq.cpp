// authur : anphung
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "seq"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define f0(i,a,b) for(int i=(a); i<=(b); ++i)
#define all(a) (a).begin(),(a).end()
#define fi first
#define se second
int n, q;
const int maxn = 1e6+5;
int64 a[maxn];

int64 solve(int64 k) {
    int len = 0, best = 0;
    f0(i, 0, n-1) {
        if (a[i] > k) len = 0;
        else {
            len++;
            best = max(best, len);
        }
    }
    return best;
}

void sub1() {
    while (q--) {
        int64 k;
        cin >> k;
        cout << solve(k);
        el;
    }
}

bool cmp(pair<int64,int>x,pair<int64,int> y){
    return x.fi<y.fi;
}
void sub2() {
    vector<int> L(n), R(n);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        L[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        R[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    vector<pair<int64, int>> V;
    for (int i = 0; i < n; ++i)
        V.emplace_back(a[i], R[i] - L[i] - 1);

    sort(all(V), cmp);
    for (int i = 1; i < n; ++i)
        V[i].second = max(V[i].second, V[i - 1].second);

    while (q--) {
        int64 k;
        cin >> k;
        auto it = upper_bound(all(V), make_pair(k, INT_MAX), cmp);
        cout << (it == V.begin() ? 0 : prev(it)->second);
        el;
    }
}


int32_t main() {
    fast;
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    cin >> n >> q;
    f0(i, 0, n-1) cin >> a[i];
    sub2();
    
}
