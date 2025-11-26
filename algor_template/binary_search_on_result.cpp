#include <bits/stdc++.h>
using namespace std;

/*
 Example: Given array, find minimal x such that condition(x) true.
 Use bs_lower with predicate.
*/

bool condition(long long x){
    // implement problem-specific check
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long lo = 0, hi = 1e18;
    while(lo < hi){
        long long mid = (lo+hi)/2;
        if(condition(mid)) hi = mid;
        else lo = mid+1;
    }
    cout << lo << '\n';
    return 0;
}
