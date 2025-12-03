// author: anphung
// github: 4npg
#include <bits/stdc++.h>
#define TASK "BAI2"
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);

int main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    string s;
    cin >> s;
    bool used[10] = {};
    for (char c : s) {
        if (c == '2' || c == '3' || c == '5' || c == '7') {
            int digit = c - '0';
            if (!used[digit]) {
                cout << c << ' ';
                used[digit] = true;
            }
        }
    }

}
