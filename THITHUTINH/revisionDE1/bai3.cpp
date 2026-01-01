#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 500000 + 5;

int N;
ll A[MAXN];

int idx[MAXN];
int comp_of_pos[MAXN]; // hạng nén của A[i]
int cnt_val[MAXN];     // tần suất mỗi hạng
int BIT[MAXN];         // Fenwick trên miền hạng (kích thước M)

int GL[MAXN], LR[MAXN]; // greater-left, less-right
int w[MAXN];            // w(i) = LR(i) - GL(i)

int start_pos[MAXN]; // offset bắt đầu của mỗi hạng trong mảng bucket
int fill_cnt[MAXN];  // số phần tử đã đẩy vào nhóm
int bucket_w[MAXN];  // dồn w theo từng nhóm hạng liên tiếp

bool cmp_idx(int i, int j)
{
    if (A[i] != A[j])
        return A[i] < A[j];
    return i < j;
}

inline void bit_add(int M, int i, int v)
{
    for (; i <= M; i += i & -i)
        BIT[i] += v;
}

inline int bit_sum(int i)
{
    int s = 0;
    for (; i > 0; i -= i & -i)
        s += BIT[i];
    return s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
        idx[i] = i;
    }

    // Nén giá trị theo (A[i], i) để ổn định
    sort(idx + 1, idx + N + 1, cmp_idx);
    int M = 0;
    for (int r = 1; r <= N; ++r)
    {
        int p = idx[r];
        if (r == 1 || A[idx[r]] != A[idx[r - 1]])
            ++M;
        comp_of_pos[p] = M;
        ++cnt_val[M];
    }

    // GL: quét trái -> phải
    ll inv_by_value = 0;
    int seen = 0;
    for (int i = 1; i <= M; ++i)
        BIT[i] = 0;
    for (int i = 1; i <= N; ++i)
    {
        int c = comp_of_pos[i];
        GL[i] = seen - bit_sum(c);
        inv_by_value += GL[i];
        bit_add(M, c, 1);
        ++seen;
    }

    // LR: quét phải -> trái
    for (int i = 1; i <= M; ++i)
        BIT[i] = 0;
    seen = 0;
    for (int i = N; i >= 1; --i)
    {
        int c = comp_of_pos[i];
        LR[i] = seen - bit_sum(c);
        bit_add(M, c, 1);
        ++seen;
    }

    for (int i = 1; i <= N; ++i)
        w[i] = LR[i] - GL[i];

    // Gom w theo từng hạng (giá trị) theo thứ tự xuất hiện gốc
    start_pos[1] = 1;
    for (int c = 2; c <= M; ++c)
        start_pos[c] = start_pos[c - 1] + cnt_val[c - 1];
    for (int c = 1; c <= M; ++c)
        fill_cnt[c] = 0;

    for (int i = 1; i <= N; ++i)
    {
        int c = comp_of_pos[i];
        int pos = start_pos[c] + fill_cnt[c];
        bucket_w[pos] = w[i];
        ++fill_cnt[c];
    }

    // Với mỗi nhóm: lấy tổng hậu tố nhỏ nhất của dãy w trong nhóm
    ll tail_sum = 0;
    for (int c = 1; c <= M; ++c)
    {
        int L = start_pos[c];
        int R = start_pos[c] + cnt_val[c] - 1;
        ll s = 0, best = 0;
        for (int j = R; j >= L; --j)
        {
            s += bucket_w[j];
            if (s < best)
                best = s;
        }
        tail_sum += best; // best <= 0
    }

    ll ans = inv_by_value + tail_sum;
    cout << ans << '\n';
    return 0;
}
