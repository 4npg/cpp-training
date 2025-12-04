#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll INF = 2e18; 

// Kích thước tối đa của mảng (ví dụ: N=200000 + 1)
const int MAX_N = 200005; 

// Mảng Segment Tree cho ST1 (a_i + i) và ST2 (a_i - i)
// Kích thước 4*N là an toàn cho cây phân đoạn
ll tree1[4 * MAX_N]; 
ll tree2[4 * MAX_N]; 

int N; // Kích thước mảng gốc

// =======================================================
// === HÀM CHUNG: XÂY DỰNG (BUILD) ===
// =======================================================

// Hàm xây dựng cây 1 (a_i + i)
void build1(const vector<ll>& arr, int node, int start, int end) {
    if (start == end) {
        tree1[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build1(arr, 2 * node, start, mid);
        build1(arr, 2 * node + 1, mid + 1, end);
        tree1[node] = min(tree1[2 * node], tree1[2 * node + 1]);
    }
}

// Hàm xây dựng cây 2 (a_i - i)
void build2(const vector<ll>& arr, int node, int start, int end) {
    if (start == end) {
        tree2[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build2(arr, 2 * node, start, mid);
        build2(arr, 2 * node + 1, mid + 1, end);
        tree2[node] = min(tree2[2 * node], tree2[2 * node + 1]);
    }
}

// =======================================================
// === HÀM CHUNG: CẬP NHẬT (UPDATE) ===
// =======================================================

// Cập nhật cây 1
void update1(int node, int start, int end, int idx, ll val) {
    if (start == end) {
        tree1[node] = val;
    } else {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid) {
            update1(2 * node, start, mid, idx, val);
        } else {
            update1(2 * node + 1, mid + 1, end, idx, val);
        }
        tree1[node] = min(tree1[2 * node], tree1[2 * node + 1]);
    }
}

// Cập nhật cây 2
void update2(int node, int start, int end, int idx, ll val) {
    if (start == end) {
        tree2[node] = val;
    } else {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid) {
            update2(2 * node, start, mid, idx, val);
        } else {
            update2(2 * node + 1, mid + 1, end, idx, val);
        }
        tree2[node] = min(tree2[2 * node], tree2[2 * node + 1]);
    }
}

// =======================================================
// === HÀM CHUNG: TRUY VẤN (QUERY) ===
// =======================================================

// Truy vấn cây 1 (tìm Min)
ll query1(int node, int start, int end, int l, int r) {
    if (l > r || r < start || end < l) { // Trường hợp đoạn rỗng hoặc nằm ngoài
        return INF;
    }
    if (l <= start && end <= r) { // Trường hợp nằm hoàn toàn bên trong
        return tree1[node];
    }
    int mid = (start + end) / 2;
    ll p1 = query1(2 * node, start, mid, l, r);
    ll p2 = query1(2 * node + 1, mid + 1, end, l, r);
    return min(p1, p2);
}

// Truy vấn cây 2 (tìm Min)
ll query2(int node, int start, int end, int l, int r) {
    if (l > r || r < start || end < l) { // Trường hợp đoạn rỗng hoặc nằm ngoài
        return INF;
    }
    if (l <= start && end <= r) { // Trường hợp nằm hoàn toàn bên trong
        return tree2[node];
    }
    int mid = (start + end) / 2;
    ll p1 = query2(2 * node, start, mid, l, r);
    ll p2 = query2(2 * node + 1, mid + 1, end, l, r);
    return min(p1, p2);
}

// =======================================================
// === HÀM MAIN GIẢI QUYẾT BÀI TOÁN ===
// =======================================================

void solve() {
    int q;
    if (!(cin >> N >> q)) return;

    // Mảng a_i ban đầu (sử dụng 1-based indexing)
    vector<ll> a(N + 1);
    
    // Mảng dữ liệu cho ST1 (a_i + i) và ST2 (a_i - i)
    vector<ll> arr1_init(N + 1);
    vector<ll> arr2_init(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
        arr1_init[i] = a[i] + i;
        arr2_init[i] = a[i] - i;
    }

    // Xây dựng hai cây
    build1(arr1_init, 1, 1, N);
    build2(arr2_init, 1, 1, N);

    for (int k = 0; k < q; ++k) {
        int type;
        if (!(cin >> type)) break;

        if (type == 1) {
            // Loại 1: Cập nhật giá (1 i x)
            int i;
            ll x;
            cin >> i >> x;
            
            a[i] = x; 

            // Cập nhật ST1: (x + i)
            update1(1, 1, N, i, x + i);
            
            // Cập nhật ST2: (x - i)
            update2(1, 1, N, i, x - i);

        } else if (type == 2) {
            // Loại 2: Truy vấn chi phí nhỏ nhất (2 i)
            int i;
            cin >> i;

            // 1. Bên phải (j >= i): min(a_j + j) - i
            ll min_val_right = query1(1, 1, N, i, N);
            ll cost_right = min_val_right - i;

            // 2. Bên trái (j < i): min(a_j - j) + i
            ll min_val_left = query2(1, 1, N, 1, i - 1); // Đoạn [1, i-1]
            ll cost_left = min_val_left + i;
            
            // Kết quả
            ll min_cost = min(cost_right, cost_left);
            
            cout << min_cost << "\n"; // Dùng "\n" thay vì endl để tăng tốc
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}