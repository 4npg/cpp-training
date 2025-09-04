#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> names = {
        "Luyện Đan Uyên",
        "Nguyễn Minh Tuấn",
        "Nguyễn Minh Hiếu",
        "Lưu Ngọc Bảo",
        "Lã Quang Minh",
        "Bùi Duy Hoàng",
        "Lã Ngọc Huyền",
        "Nguyễn Hồng Ngọc"
    };

    random_device rd;
    mt19937 gen(rd());

    cout << "Bấm Enter để quay tên...\n";

    while (!names.empty()) {
        cin.get();

        uniform_int_distribution<int> dist(0, (int)names.size() - 1);
        int idx = dist(gen);

        cout << "Tên được chọn 1: " << names[idx] << "\n";

        names.erase(names.begin() + idx);
    }

    return 0;
}
