#include <bits/stdc++.h>
using namespace std;

// classic binary search template: find max/min that satisfies predicate

long long bs_lower(long long lo, long long hi, function<bool(long long)> ok){
    while(lo < hi){
        long long mid = lo + (hi-lo)/2;
        if(ok(mid)) hi = mid;
        else lo = mid+1;
    }
    return lo;
}

long long bs_upper(long long lo, long long hi, function<bool(long long)> ok){
    while(lo < hi){
        long long mid = lo + (hi-lo+1)/2;
        if(ok(mid)) lo = mid;
        else hi = mid-1;
    }
    return lo;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}
