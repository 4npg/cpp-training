
# Đề Thi Tin Học

---

## Bài 1 — HÌNH VUÔNG TỐI THIỂU

**Mô tả.**  
Cho một tập hợp gồm **n** điểm trên mặt phẳng tọa độ, mỗi điểm có tọa độ nguyên `(x, y)`.  
Hãy tìm **diện tích nhỏ nhất** của một hình vuông (các cạnh song song với trục tọa độ) sao cho tất cả các điểm đều nằm trong hoặc trên biên của hình vuông đó.

**Input**
- Dòng 1: số nguyên dương `n` (1 ≤ n ≤ 100000) — số điểm.
- `n` dòng tiếp theo: mỗi dòng chứa hai số nguyên `x` và `y` (−10^9 ≤ x, y ≤ 10^9) — tọa độ một điểm.

**Output**
- Một số nguyên duy nhất — diện tích của hình vuông nhỏ nhất.

**Ví dụ**

***INPUT***

```text
3
1 1
3 2
4 4

```
***OUTPUT***

```text
9
```

---

## Bài 2 — CẶP SỐ CHIA HẾT CHO 3

**Mô tả.**  
Cho dãy `a1, a2, ..., an`. Một cặp chỉ số `(i, j)` với `i < j` được gọi là cặp đẹp nếu `(a[i] + a[j])` chia hết cho 3. Hãy đếm số cặp đẹp.

**Input**
- Dòng 1: số nguyên dương `n` (1 ≤ n ≤ 100000).
- Dòng 2: `n` số nguyên `a1 a2 ... an` (−10^9 ≤ ai ≤ 10^9).

**Output**
- Một số nguyên duy nhất — số lượng cặp `(i, j)` thỏa điều kiện.

**Ví dụ**

***INPUT***

```text
5
1 2 3 4 5

```
***OUTPUT***

```text
4
```
