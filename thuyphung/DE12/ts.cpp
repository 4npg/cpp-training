#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n,k; cin >> n >> k;
    double sum = 0; double a[n]; 
    double maxa = -1e9;

    for (ll i = 0; i < n; i++){
        cin >> a[i];
        if (k==1) maxa = max(maxa, a[i]);
    }

    double ava;
    for (ll i = 0; i < n-k; i++) {
        sum = a[i];
        for (ll j = i+1; j <n; j++) {
            sum += a[j]; 
            if ((j-i+1)>=k)maxa = max(maxa,sum/(double)(j-i+1));
            
        }
    }
    cout << fixed << setprecision(3) << maxa;
}