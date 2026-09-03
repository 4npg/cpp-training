#include<bits/stdc++.h>
#include <ctime>
#include <random>
using namespace std;

#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
<<<<<<< HEAD
#define file "bobaso"
=======
#define file "matkhau"
>>>>>>> f063d656d39fd63d627e7717613bb60030e3d0be

template<typename T> bool minimize (T &a, T b) { if (a > b) return a = b, 1; return 0; }
template<typename T> bool maximize (T &a, T b) { if (a < b) return a = b, 1; return 0; }

const int N_ = 1e5 + 5;
const int mod = (int)1e9 + 7;
const int base = 256;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int rd (int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

bool d[N_];
<<<<<<< HEAD
vector<int> nto;

void sang() {
    d[0] = d[1] = 1;
    for (int i = 2; i * i < N_; i++) {
        if (!d[i]) for (int j = i * i; j < N_; j += i) {
            d[j] = 1;
        }
    }

    for (int i = 2; i < N_; i++) {
        if (!d[i]) nto.emplace_back(i);
    }
}

int k;
int cnt;

void solve() {

    sang(); cin >> k;

    // for (int i = 2; i < 100; i++) {
    //  if (!d[i]) cout << i << ' ' ;
    // }

    // for (int x = 2; x <= k; x++) {
    //  if (!d[x]) for (int y = x; y <= k - x; y++) {
    //      if (!d[y]) for (int z = y; z <= k - x - y; z++) {
    //          if (!d[z])
    //              if (x + y + z == k) cout<< x << ' ' << y << ' ' << z << '\n';
    //      }
    //  }
    // }

    for (int x : nto) {
        if (x > k / 3) break;

        for (int y : nto) {
            if (y < x) continue;
            if (y > (k - x) / 2) break;

            int z = k - x - y;

            // if(!d[z]) cout << x << ' ' << y << ' ' << z << '\n';
            if (!d[z]) cnt++;
        }
    }

    cout << cnt;
}
=======

void sang() {
    d[0] = d[1] = 1;
    for (int i = 2; i < N_; i++) {
        if (!d[i]) for (int j = i * i; j < N_; j += i) d[j] = 1;
    }
}

string s;

vector<int> num;

bool isdigit(char c) {
    return (c >= '0' && c <= '9');
}

void solve() {

    sang();

    cin >> s;

    for (int i = 0; i < (int)s.size(); i++) {
        if (!isdigit(s[i])) continue;

        int x = 0;
        for (int j = i; j < (int)s.size() && isdigit(s[j]); j++) {
            x = x * 10 + (s[j] - '0');
            // cout << x << '\n';
            num.emplace_back(x);
        }

        while (i + 1 < (int)s.size() && isdigit(s[i + 1])) i++;
    }

    for (auto &k : num) cout << k << '\n';
}


>>>>>>> f063d656d39fd63d627e7717613bb60030e3d0be

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);

<<<<<<< HEAD
     freopen(file".inp", "r", stdin);
     freopen(file".out", "w", stdout);
=======
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);
>>>>>>> f063d656d39fd63d627e7717613bb60030e3d0be

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n";
<<<<<<< HEAD
}
=======
}
>>>>>>> f063d656d39fd63d627e7717613bb60030e3d0be
