#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file "" 

// Fast input / output

static struct FastInput {
    static constexpr int BUF_SIZE = 1 << 20;
    char buf[BUF_SIZE];
    size_t chars_read = 0;
    size_t buf_pos = 0;
    FILE *in = stdin;
    char cur = 0;

    inline char get_char() {
    if (buf_pos >= chars_read) {
        chars_read = fread(buf, 1, BUF_SIZE, in);
        buf_pos = 0;
        buf[0] = (chars_read == 0 ? -1 : buf[0]);
    }
    return cur = buf[buf_pos++];
}

    inline void tie(int) {}

    inline explicit operator bool() {
        return cur != -1;
      }

    inline static bool is_blank(char c) {
        return c <= ' ';
    }

    inline bool skip_blanks() {
        while (is_blank(cur) && cur != -1) {
            get_char();
        }
        return cur != -1;
    }

    inline FastInput& operator>>(char& c) {
        skip_blanks();
        c = cur;
        return *this;
    }

    inline FastInput& operator>>(string& s) {
        if (skip_blanks()) {
            s.clear();
            do {
                s += cur;
            } while (!is_blank(get_char()));
        }
        return *this;
    }

    template <typename T> inline FastInput& read_integer(T& n) {
        // unsafe, doesn't check that characters are actually digits
        n = 0;
        if (skip_blanks()) {
            int sign = +1;
            if (cur == '-') {
                sign = -1;
                get_char();
            }
            do {
                n += n + (n << 3) + cur - '0';
            } while (!is_blank(get_char()));
            n *= sign;
        }
        return *this;
      }

    template <typename T> inline typename enable_if<is_integral<T>::value, FastInput&>::type operator>>(T& n) {
        return read_integer(n);
    }

    #if !defined(_WIN32) | defined(_WIN64) 
        inline FastInput& operator>>(__int128& n) {
            return read_integer(n);
        }
      
    #endif

    template <typename T> inline typename enable_if<is_floating_point<T>::value, FastInput&>::type operator>>(T& n) {
        // not sure if really fast, for compatibility only
        n = 0;
        if (skip_blanks()) {
            string s;
            (*this) >> s;
            sscanf(s.c_str(), "%lf", &n);
        }
        return *this;
}

} fast_input;

static struct FastOutput {
    static constexpr int BUF_SIZE = 1 << 20;
    char buf[BUF_SIZE];
    size_t buf_pos = 0;
    static constexpr int TMP_SIZE = 1 << 20;
    char tmp[TMP_SIZE];
    FILE *out = stdout;

    inline void put_char(char c) {
        buf[buf_pos++] = c;
        if (buf_pos == BUF_SIZE) {
            fwrite(buf, 1, buf_pos, out);
            buf_pos = 0;
        }
    }

    ~FastOutput() {
        fwrite(buf, 1, buf_pos, out);
    }

    inline FastOutput& operator<<(char c) {
        put_char(c);
        return *this;
    }

    inline FastOutput& operator<<(const char* s) {
        while (*s) {
            put_char(*s++);
        }
        return *this;
    }

    inline FastOutput& operator<<(const string& s) {
        for (int i = 0; i < (int) s.size(); i++) {
            put_char(s[i]);
        }
        return *this;
    }

    template <typename T> inline char* integer_to_string(T n) {
        // beware of TMP_SIZE
        char* p = tmp + TMP_SIZE - 1;
        if (n == 0) {
            *--p = '0';
        } else {
            bool is_negative = false;
            if (n < 0) {
                is_negative = true;
                n = -n;
            }
            while (n > 0) {
                *--p = (char) ('0' + n % 10);
                n /= 10;
            }
            if (is_negative) {
                *--p = '-';
            }
        }
        
        return p;
    }

    template <typename T> inline typename enable_if<is_integral<T>::value, char*>::type stringify(T n) {
        return integer_to_string(n);
    }

    #if !defined(_WIN32) | defined(_WIN64)
        inline char* stringify(__int128 n) {
            return integer_to_string(n);
        }
    #endif

    template <typename T> inline typename enable_if<is_floating_point<T>::value, char*>::type stringify(T n) {
        sprintf(tmp, "%.17f", n);
        return tmp;
    }

    template <typename T> inline FastOutput& operator<<(const T& n) {
        auto p = stringify(n);
        for (; *p != 0; p++) {
            put_char(*p);
        }
        return *this;
    }
} fast_output;

#define fin fast_input
#define fout fast_output
#define endl "\n"

const int base = 137;
const int mod = (int)1e9 + 9;
const int maxn = (int)1e6 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class T> T rd(T a, T b) { T ret = uniform_int_distribution<T>(a, b)(rng); return ret; }
template<class data> bool minimize (data &a, data b) { if (a > b) return a = b, true; return false; }
template<class data> bool maximize (data &a, data b) { if (a < b) return a = b, true; return false; }
template<class data> data opw (data a, data b) { data ans = 1; while (b) { if (b & 1) ans = ans * a % mod; a = a * a % mod; b >>= 1;} return ans; }

#define all(a) ((a).begin(), (a).end())

struct dhash {
    int n;
    static const int base = 137;
    static const int mod1 = (int)1e9 + 7;
    static const int mod2 = (int)1e9 + 9;

    struct hash {
        long long h1, h2;

        bool operator < (const hash &o) const {
            if (h1 != o.h1) return h1 < o.h1;
            return h2 < o.h2;
        }

        bool operator == (const hash &o) const { 
            return h1 == o.h1 && h2 == o.h2;
        }
    };

    long long hs1[maxn], hs2[maxn];
    long long pw1[maxn], pw2[maxn];

    void init(const string &s) {

        pw1[0] = pw2[0] = 1;
        hs1[0] = hs2[0] = 0;
        
        n = (int)s.size() - 1;

        for (int i = 1; i <= n; i++) {
            pw1[i] = 1LL * pw1[i-1] * base % mod1;
            pw2[i] = 1LL * pw2[i-1] * base % mod2;

            hs1[i] = (hs1[i-1] + 1LL * s[i] * pw1[i-1] % mod1) % mod1;
            hs2[i] = (hs2[i-1] + 1LL * s[i] * pw2[i-1] % mod2) % mod2;
        }
    }

    hash get(int l, int r) {
        long long ret1 = hs1[r] - hs1[l-1];
        if (ret1 < 0) ret1 += mod1;
        ret1 = ret1 * pw1[n - l +1] % mod1;

        long long ret2 = hs2[r] - hs2[l-1];
        if (ret2 < 0) ret2 += mod2;
        ret2 = ret2 * pw2[n - l +1] % mod2;

        return {1LL * ret1, 1LL * ret2};
    }
} H;

int n, k; string s;
// long long hs[maxn], pw[maxn];

void init() {
   
    fin >> n >> k >> s;

    // pw[0] = 1;

    // for (int i = 1; i < maxn; i++) {
    //     pw[i] = (pw[i-1] * base) % mod;
    // }

    s = ' ' + s;
    H.init(s);

    // for (int i = 1; i <= n; i++) {
    //     hs[i] = (hs[i-1] + 1LL * s[i] * pw[i-1] % mod) % mod;
    // }

}

// long long gethash(int l, int r) {
//     long long tmp = hs[r] - hs[l-1];
//     if (tmp < 0) tmp += mod;
//     return 1LL * tmp * pw[maxn-l+1] % mod;
// }

bool check(int len) {
    if (len == 0) return true;
    if (k == 1) return true;

    vector<dhash::hash> hs_substr; hs_substr.reserve(n - len + 1);

    for (int i = len; i <= n; i++) {
        hs_substr.emplace_back(H.get(i - len + 1, i));
    }

    sort(hs_substr.begin(), hs_substr.end());

    int sz = hs_substr.size();

    int cnt = 1;

    for (int i = 1; i < sz; i++) {
        if(hs_substr[i] == hs_substr[i-1]) cnt++;
        else cnt = 1;
        if(cnt >= k)return true;
    }

    return false;
}

void solve() {

    int l = 1, r = n;
    int ans = 0;

    while (l <= r) {
        int mid = ((l + r)>>1);
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
        
    fout << ans;
}

int main(void) {    

    init();

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n";
}