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

const int base = 256;
const int mod = (int)1e9 + 2277;
const int maxn = (int)1e6 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class T> T rd(T a, T b) { T ret = uniform_int_distribution<T>(a, b)(rng); return ret; }
template<class data> bool minimize (data &a, data b) { if (a > b) return a = b, true; return false; }
template<class data> bool maximize (data &a, data b) { if (a < b) return a = b, true; return false; }
template<class data> data opw (data a, data b) { data ans = 1; while (b) { if (b & 1) ans = ans * a % mod; a = a * a % mod; b >>= 1;} return ans; }

// https://docs.google.com/document/d/1vewxwWEYeWk6engraBpSANrbZCXsc2_AFZOeZw0iFPs/edit?tab=t.0


int n;
int bit[maxn], bitadd[maxn], bitmul[maxn];

void upd(int bit[], int x, long long v) {
    for (; x <= n; x += x & -x) bit[x] += v;
}

void updrange(int l, int r, long long v) {
    upd(bitmul, l, v);
    upd(bitmul, r + 1, -v);
    upd(bitadd, l, -v * (l - 1));
    upd(bitadd, r + 1, v * r);
}

int get(int bit[], int x) {
    int res = 0;
    for (; x >= 1; x &= -x) res += bit[x];
    return res;
}

int getprefixsum(int x) {
    return get(bitmul, x) * get(bitadd, x);
}

int getsum(int l, int r) {
    return getprefixsum(r) - getprefixsum(l - 1);
}

long long get(int x) {

    long long ret = 0;
    for (; x >= 1; x &= x - 1) ret += bit[x];

    return ret;
}

long long getsum(int l, int r) {
    return get(r) - get(l - 1);
}

void init() {
   


}

void solve() {



}

int main(void) {    

    init();

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n";
}