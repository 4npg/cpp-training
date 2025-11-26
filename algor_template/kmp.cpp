#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(const string &s){
    int n = s.size();
    vector<int> pi(n);
    for(int i=1;i<n;i++){
        int j = pi[i-1];
        while(j>0 && s[i]!=s[j]) j = pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i]=j;
    }
    return pi;
}

// find occurrences of pattern p in text t
vector<int> kmp_search(const string &t, const string &p){
    string s = p + "#" + t;
    auto pi = prefix_function(s);
    vector<int> occurs;
    int m = p.size();
    for(int i=m+1;i<(int)s.size();++i){
        if(pi[i]==m) occurs.push_back(i-2*m); // 0-index position in t
    }
    return occurs;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}
