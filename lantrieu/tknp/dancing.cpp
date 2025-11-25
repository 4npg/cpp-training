// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define pb push_back
#define all(a) (a).begin(),(a).end()

int n;
vector<int> nampos, namneg, nupos, nuneg;

bool check(int k, vector<int> &nam, vector<int> &nu, bool isGreater){
    int i=0, j=0, cnt=0;
    while(i<nam.size() && j<nu.size() && cnt<k){
        if(isGreater){
            if(nam[i] > nu[j]){
                cnt++;
                i++; j++;
            } else i++;
        } else {
            if(nam[i] < nu[j]){
                cnt++;
                i++; j++;
            } else i++;
        }
    }
    return cnt >= k;
}

int bns(vector<int> &nam, vector<int> &nu, bool isGreater){
    int lo = 0, hi = min(nam.size(), nu.size()), ans = 0;
    while(lo <= hi){
        int mid = lo + ((hi - lo) >> 1);
        if(check(mid, nam, nu, isGreater)){
            ans = mid;
            lo = mid + 1;
        } else hi = mid - 1;
    }
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n;
    f0(i,0,n-1){
        int x; cin >> x;
        if(x>0) nampos.pb(x); else namneg.pb(-x);
    }
    f0(i,0,n-1){
        int x; cin >> x;
        if(x>0) nupos.pb(x); else nuneg.pb(-x);
    }

    sort(all(nampos));
    sort(all(namneg));
    sort(all(nupos));
    sort(all(nuneg));

    int ans = bns(nampos, nuneg, false) + bns(namneg, nupos, true);
    cout << ans;

    cerr << "time elapsed: " << TIME << "s.\n";
}
