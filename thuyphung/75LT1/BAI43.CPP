#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "tenbai"
#define nl cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll i=a;i<=b;++i)
#define fi first
#define se second
#define pb push_back
#define all(a) (a).begin(),(a).end()

int32_t main() {
    fast;
    if (fopen(TASK ".inp","r")) {
        freopen(TASK ".inp","r",stdin);
        freopen(TASK ".out","w",stdout);
    }

    ll x, y; cin >> x >> y;
    ll d = y - x;
    if(d == 0) {
        cout << 0; nl;
        return 0;
    }

    // Tìm k nhỏ nhất sao cho k*k >= d
    ll k = 0;
    while(k*k < d) k++;

    /*
    Giải thích phân chia d:
    - Khoảng cách d cần được đi bằng các bước nhảy:
      Bước nhảy đầu = 1, bước cuối = 1
      Các bước nhảy liên tiếp chênh lệch tối đa 1

    - Có 2 dạng d được chia thành bước:
      1) d <= k^2:
         Số bước tối thiểu = 2*k - 1
         Ví dụ: nếu d = 9 (k=3), ta có thể đi các bước:
         1,2,3,2,1 (tổng = 9), tổng bước = 5 = 2*3 - 1

      2) d > k^2 nhưng d <= k*(k+1):
         Số bước tối thiểu = 2*k
         Ví dụ: d=12 (k=3 vì 3^2=9 <12<=3*4=12)
         Các bước: 1,2,3,3,2,1 (tổng=12), tổng bước = 6 = 2*3

      Ý tưởng: 
        - Bước tăng dần từ 1 đến k
        - Nếu d lớn hơn k^2, ta phải giữ bước nhảy ở k trong 1 bước nữa
        - Tổng bước tăng thêm 1 thành 2*k

    */

    if(d <= k*k) cout << 2*k - 1;
    else cout << 2*k;
}
