#include<bits/stdc++.h>
using namespace std;

#define file ""
#define TIME (1.0*clock()/CLOCKS_PER_SEC)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class X> bool maximize(X &a, const X &b){ if(a < b)return a = b, true; return false;}

template<class X> bool minimize(X &a, const X &b){ if(a > b)return a = b, true; return false;}

const int maxn = 1e6+5;
// const int mod = 1e9+7;
// dem uoc cua n

template<class T> T sub1(T n){
    T ans = 0;
    for( int i = 1; i <= n; ++i){
        if(n % i == 0){
            ans++;
        }
    }
    return ans;
}

template<class T> T sub2(T n){
    T ans = 0;
    for ( int i = 1; i*i <= n; i++){
        if(n % i == 0){
            ans++;
            if(n / i != i)ans++;
        }
    }
    return ans;
}

#define miniDATA vector<int>
#define DATA vector<long long>

bool d[maxn];
// map<int, int> mp;
DATA pri;

void sang(){
    for(int i=2; i*i < maxn; i++){
        if(!d[i]){
            for(int j = i*i; j < maxn; j+=i)d[j] = 1;
        }
    }

    for(int i=2; i<maxn; i++)if(!d[i])pri.emplace_back(i);
}

template<class T> T sub3(T n){
    DATA prep;
    for(auto &x:pri){
        if(n % x == 0){
            int cnt = 0;
            while(n % x == 0){
                // mp[x]++;
                cnt++;
                n /= x;
            }
            if(cnt) prep.emplace_back(cnt);
        }
    }
    if(n > 1)prep.emplace_back(1);

    T ans = 1;
    // for(auto &x:mp){
    //     ans *= (x.second+1);
    // }

    for(auto &x : prep){
        ans *= (x+1);
    }

    return ans;
}

template<class T> T mulmod(T a, T b, T mod){
    T ans = 0;
    while(b){
        if(b&1)ans = (ans + a)%mod;
        a = (a + a)%mod;
        b>>=1;
    }    
    return ans;
}

template<class T> T opw(T a, T b, T mod){
    T ans = 1;
    while(b){
        if(b&1) ans = mulmod(ans, a, mod);
        a = mulmod(a, a, mod);
        b>>=1;
    }
    return ans;
}

template<class T> bool test(T a, T n, T k, T m){
    T mod = opw(a, m, n);
    if(mod == 1 || mod == n-1)return 1;

    for(int l = 1; l < k; ++l){
        mod = mulmod(mod, mod, n);
        if(mod == n-1)return 1;
    }
    return 0;
}


template<class T> bool miller(T n){
    static DATA checkset = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

    for(auto &a : checkset){
        if(n == a)return 1;
    }
    if(n < 41)return 0;

    T k = 0, m = n-1;
    while(m % 2 == 0){
        m /= 2;
        k++;
    }

    for(auto &a : checkset){
        if(!test(a, n, k, m))return 0;
    }
    return 1;
}

template<class T> bool cp(T n){
    T c = sqrt(n+4);
    return c*c == n || (c-1)*(c-1) == n;
}

template<class T> T sub4(T n){
    if(n == 1)return 1;
    miniDATA prep;

    for(auto &p:pri){
        int cnt = 0;
        while(n % p == 0){
            n /= p;
            ++cnt;
        }
        if(cnt)prep.emplace_back(cnt);
    }

    if( n != 1){
        if(miller(n))prep.emplace_back(1);
        else if(cp(n))prep.emplace_back(2);
        else {
            prep.emplace_back(1);
            prep.emplace_back(1);
        }
    }

    int ans = 1;
    for(auto &x:prep)ans *= (x+1);
    return ans;
}

// long long t;

void solve(){
    // cin >> t;

    // while ( t-- ){
    //     long long n; cin >> n;

    //     cout << ((miller(n))?"YES":"NO") << '\n';
    // }

    // long long n = uniform_int_distribution<long long>(1, 1000000000)(rng);

    long long n = 100;
    cout << "n = " << n << '\n';
    cout << sub2(n) << ' ' << sub3(n) << ' ' << sub4(n) << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    sang();

    solve();

    // sang();

    // int bla = uniform_int_distribution<int>(1, 1000)(rng);
    // cout << bla << '\n';


    // for(auto &x:pri){
    //     if(bla % x == 0){
    //         while(bla % x == 0){
    //             mp[x]++;
    //             bla /= x;
    //         }
    //     }
    // }
  
    // for(auto &x:mp){
    //     cout << x.first << ' ' << x.second << '\n';
    // }
    cerr << "\ntime elapsed: " << TIME << "s.\n";
}
