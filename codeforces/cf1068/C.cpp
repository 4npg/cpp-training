// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> a(n);
    unordered_set<long long> set_a;
    
    f0(i, 0, n - 1) {
        cin >> a[i];
        set_a.insert(a[i]);
    }

    unordered_set<long long> p_potential;
    for (long long val : set_a) {
        for (long long d = 1; d * d <= val; ++d) {
            if (val % d == 0) {
                p_potential.insert(d);
                p_potential.insert(val / d);
            }
        }
    }
    
    vector<long long> p_candidates;
    for (long long x : p_potential) {
        if (x == 0) continue;
        
        bool is_perfect_multiple = true;
        for (long long m = 1; ; ++m) {
            if (x > k / m) {
                 break; 
            }
            long long multiple = m * x;
            
            if (set_a.find(multiple) == set_a.end()) {
                is_perfect_multiple = false;
                break;
            }
        }

        if (is_perfect_multiple) {
            p_candidates.push_back(x);
        }
    }
    
    vector<bool> covered(n, false);
    int covered_count = 0;
    vector<long long> result_b;

    unordered_map<long long, int> coverage_count;
    
    for (long long b : p_candidates) {
        coverage_count[b] = 0;
    }
    f0(i, 0, n - 1) {
        long long val = a[i];
        for (long long b : p_candidates) {
            if (val % b == 0) {
                coverage_count[b]++;
            }
        }
    }

    while (covered_count < n) {
        long long best_b = -1;
        int max_coverage = 0;

        for (long long b : p_candidates) {
            if (coverage_count.at(b) > max_coverage) {
                max_coverage = coverage_count.at(b);
                best_b = b;
            }
        }
        
        if (max_coverage == 0) {
            cout << -1 << "\n";
            return; 
        }

        // Cập nhật trạng thái
        result_b.push_back(best_b);
        coverage_count[best_b] = 0; 

        f0(i, 0, n - 1) {
            if (!covered[i] && a[i] % best_b == 0) {
                
                covered[i] = true;
                covered_count++;

                long long val = a[i];
                for (long long d : p_candidates) {
                    if (d != best_b && val % d == 0) {
                        if (coverage_count.count(d)) {
                            coverage_count[d]--;
                        }
                    }
                }
            }
        }
    }
    
    cout << result_b.size() << "\n";
    f0(i, 0, result_b.size() - 1) {
        cout << result_b[i] << (i == result_b.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

	cerr << "time elapsed: "<<TIME <<"s.\n";
    return 0;
}