#include <bits/stdc++.h>
using namespace std;

// returns vector d1 (odd radii) and d2 (even radii)
pair<vector<int>,vector<int>> manacher(const string &s){
    int n = s.size();
    vector<int> d1(n);
    int l=0,r=-1;
    for(int i=0;i<n;i++){
        int k = (i>r) ? 1 : min(d1[l + r - i], r-i+1);
        while(0 <= i-k && i+k < n && s[i-k] == s[i+k]) k++;
        d1[i] = k--;
        if(i+k>r){ l = i-k; r = i+k; }
    }
    vector<int> d2(n);
    l=0; r=-1;
    for(int i=0;i<n;i++){
        int k = (i>r) ? 0 : min(d2[l+r-i+1], r-i+1);
        while(i-k-1 >=0 && i+k < n && s[i-k-1]==s[i+k]) k++;
        d2[i]=k--;
        if(i+k>r){ l = i-k-1; r = i+k; }
    }
    return {d1,d2};
}

int main(){ ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }
