# Hái táo — Giải thích chi tiết (DP + Segment Tree)

> **Mô tả bài toán (tóm tắt)**

Marisa có `n` cây táo đánh số từ `1` đến `n`. Có `q` gói dịch vụ, gói thứ `i` là một đoạn `[l_i, r_i]` với giá `c_i` — nếu chọn gói này thì Nitori sẽ hái **toàn bộ** các cây từ `l_i` đến `r_i`. Hỏi chi phí nhỏ nhất để thu hoạch **toàn bộ** các cây `1..n`. Nếu không thể, in `-1`.

**Ràng buộc**

* `1 ≤ n, q ≤ 1e5`
* `1 ≤ l_i, r_i ≤ n`
* `1 ≤ c_i ≤ 1e9`
* Thời gian: 200 ms, bộ nhớ: 256 MB

**Ví dụ**

Input:

```
5 3
1 4 2
5 5 3
2 5 1
```

Output:

```
3
```

> Giải thích ví dụ: Chọn gói `[1,4]` (cost 2) và `[5,5]` (cost 1) → tổng 3. (Trong ví dụ trên, giá `[2,5] = 1` thay vì 1? chú ý: ví dụ đầu problem khác nhưng ý là chọn 2 gói rẻ nhất phủ 1..5)

---

# Hướng tư duy chính (intuition)

Bài này là bài "cover intervals" nhưng **mục tiêu là tối thiểu tổng chi phí**, không phải tối thiểu số gói. Do đó các phương pháp tham lam thông thường (chọn đoạn cover xa nhất) sẽ sai.

Cần xây dựng **trạng thái biểu diễn "đã phủ tới đâu rồi"**. Một cách tự nhiên là tính theo prefix:

* Đặt `dp[i]` = chi phí nhỏ nhất để đã hái tất cả cây `1..i`.
* Mục tiêu cần tìm `dp[n]`.

Tại sao prefix? Bởi vì khi chọn một gói `[l,r]`, gói đó chỉ hữu dụng nếu trước đó t đã hái xong đến ít nhất `l-1`. Sau khi dùng gói, mức phủ có thể nâng tới `r`. Vì thế trạng thái chỉ phụ thuộc vào điểm ta đã phủ đến — rất đúng bản chất DP prefix.

---

# Công thức chuyển trạng thái (transition)

Với gói `[l,r]` có giá `c`:

```
Nếu tồn tại j ∈ [l-1, r] sao cho dp[j] != INF thì
    dp[r] = min(dp[r], dp[j] + c)
```

Giải thích: nếu đã phủ tới `j` (j >= l-1), thì gói đó cộng thêm sẽ đảm bảo phủ tới r. Ta cần lấy giá nhỏ nhất trong các dp[j] trên đoạn `[l-1, r]` rồi cộng `c`.

Khởi tạo: `dp[0] = 0` (không tốn gì để hái 0 cây), các `dp[i>0] = INF`.

Kết quả: nếu `dp[n]` vẫn INF → in `-1`, ngược lại in `dp[n]`.

---

# Bài toán rút gọn về truy vấn min trên đoạn + cập nhật điểm

Công thức chuyển trạng thái cần **lấy min(dp[j]) trên đoạn `[l-1, r]`** nhiều lần (cho nhiều gói khác nhau). Với `n,q ≤ 1e5`, ta cần một cấu trúc dữ liệu để trả về min trên đoạn và cập nhật giá trị tại một điểm nhanh:

* **Segment Tree** (hoặc Fenwick tree biến thể cho min) cho phép query và point-update trong O(log n).

Ý tưởng tổng quát:

1. Lưu `dp` vào segtree (ban đầu dp[0]=0, các vị trí khác INF).
2. Duyệt các `r` từ 1 tới n (hoặc duyệt gói theo r tăng dần). Với mỗi gói kết thúc ở r:

   * Query `mn = min(dp[l-1 .. r])` từ segtree.
   * Nếu `mn < INF` thì `dp[r] = min(dp[r], mn + c)`.
3. Sau xử lý tất cả gói có cùng r, nếu `dp[r] < INF` update segtree tại vị trí r với dp[r].

Lưu ý: ta phải cập nhật dp[r] nhỏ nhất sau khi xét đủ gói kết thúc ở r. Nếu cập nhật ngay lập tức cũng ổn, miễn là segtree giữ giá trị dp đúng tại mọi thời điểm.

---

# Chứng minh tính đúng (ý chính)

* Mỗi dp[r] mô tả chi phí tối thiểu để phủ 1..r. Bất kỳ tập gói nào phủ 1..r thì tồn tại gói cuối cùng trong tập đó (gói có r' lớn nhất trong tập hoặc gói khiến r được
  "reach"). Ta xem gói cuối cùng đó phải là một gói `[l,r]` trong input. Trước khi dùng gói này, phải phủ tới `j` với `j ∈ [l-1, r]` (thậm chí `j = l-1` đủ). Chi phí toàn bộ = chi phí đạt tới `j` + `c`. Do đó dp[r] phải bằng min trên những giá trị dạng `dp[j] + c`. Công thức trên lấy đúng min đó.

* Do ta bảo toàn giá trị dp bằng cách cập nhật từ nhỏ tới lớn r, và segtree đảm bảo lấy đúng min trong đoạn, nên cuối cùng dp[n] là chi phí tối thiểu toàn cục.

---

# Độ phức tạp

* Xây segtree: O(n)
* Với mỗi gói: một truy vấn O(log n) và một cập nhật O(log n) (tùy cách tổ chức). Tổng O(q log n).
* Nếu duyệt r từ 1..n và cho mỗi r xét các gói kết thúc ở r: tổng vẫn O(q log n + n log n).

Do đó thuật toán chạy tốt với `n,q ≤ 1e5`.

---

# Cài đặt C++17 (mẫu hoàn chỉnh)

```cpp
// author : anphung >> npkly
#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 INF = (int64)4e18;

struct SegTree {
    int n;
    vector<int64> st;
    SegTree(int _n = 0) { init(_n); }
    void init(int _n) {
        n = 1; while (n < _n) n <<= 1;
        st.assign(2*n, INF);
    }
    // point update: st[pos] = min(st[pos], val)
    void update(int pos, int64 val) {
        pos += n;
        st[pos] = min(st[pos], val);
        for (pos >>= 1; pos; pos >>= 1) st[pos] = min(st[pos<<1], st[pos<<1|1]);
    }
    // query min on inclusive [l, r]
    int64 query(int l, int r) {
        if (l > r) return INF;
        l += n; r += n;
        int64 res = INF;
        while (l <= r) {
            if (l & 1) res = min(res, st[l++]);
            if (!(r & 1)) res = min(res, st[r--]);
            l >>= 1; r >>= 1;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    // group gói theo r để xét r tăng dần
    vector<vector<array<int,3>>> byR(n+1);
    for (int i = 0; i < q; ++i) {
        int l, r; long long c;
        cin >> l >> r >> c;
        if (r >= 1 && r <= n) byR[r].push_back({l, r, (int)c});
    }

    SegTree st(n+1);
    vector<int64> dp(n+1, INF);
    dp[0] = 0;
    st.update(0, 0);

    for (int r = 1; r <= n; ++r) {
        int64 best = INF;
        for (auto &pkg : byR[r]) {
            int l = pkg[0];
            int64 c = pkg[2];
            int L = max(0, l-1);
            int64 mn = st.query(L, r);
            if (mn < INF) best = min(best, mn + c);
        }
        dp[r] = best;
        if (dp[r] < INF) st.update(r, dp[r]);
    }

    if (dp[n] >= INF) cout << -1;
    else cout << dp[n];
    return 0;
}
```

> Ghi chú implementation:

* Ta dùng `st.update(pos, val)` dưới dạng "point-min-update" (giữ giá trị nhỏ nhất đã thấy cho pos). Điều này phù hợp vì dp[pos] chỉ giảm theo thời gian.
* Nhóm gói theo `r` để chỉ xét các gói có r hiện tại khi xử lý r — dễ hiểu và dễ debug.

---

# Các trường hợp biên & tips debug

1. **Không có cách phủ toàn bộ** → dp[n] = INF → in `-1`.
2. **Khoảng l bằng 1**: lúc đó `L = l-1 = 0`, ta query [0, r] — hợp lý vì có thể chưa chọn gói nào trước.
3. **Gói thừa**: nếu một gói có cost quá cao mà dp[r] đã có giá rẻ hơn, `update` sẽ không thay đổi.
4. **Sắp xếp gói**: không nhất thiết phải sắp xếp theo r nếu ta push vào `byR[r]`, vì ta xử lý r tăng dần.
5. **Kiểm tra với examples nhỏ**: tự tạo các trường hợp tiny (n ≤ 6) brute-force để so sánh kết quả.

---

# Các cách mở rộng / biến thể

* Có thể dùng Fenwick tree biến thể để lưu min và query min prefix, nhưng vì ta cần query min trên đoạn tùy ý `[l-1, r]` nên Fenwick chuẩn không đủ. Một cách là chuyển đổi bài toán sang một dạng prefix-only query, nhưng phức tạp hơn và dễ sai; segment tree là giải pháp trực tiếp và an toàn.
* Nếu q rất lớn (ví dụ millions), cần tối ưu memory/IO, hoặc dùng offline + sweep-line kết hợp cấu trúc dữ liệu khác.

---

# Tổng kết ngắn gọn

* Mô hình chuẩn: `dp[i]` = chi phí nhỏ nhất để phủ `1..i`.
* Transition lấy `min(dp[j])` trên `j ∈ [l-1, r]` cho mỗi gói `[l,r,c]` và cộng `c`.
* Dùng Segment Tree để query min trên đoạn + point-update.
* Độ phức tạp: `O((n+q) log n)` — phù hợp cho `1e5`.

---

# npkl
