#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n;cin>>n;
    string str;
    for(ll i=0;i<n;i++){
        char c;cin>>c;
        str+=c;
    }
    ll x = 0, y = 0, huong = 0;
    ll dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    for (char c : str) {
        if (c == 'L') huong = (huong + 3) % 4;
        else if (c == 'R') huong = (huong + 1) % 4;
        else {
            ll m = (c == 'G') ? 1 : -1;
            x += m * dx[huong];
            y += m * dy[huong];
        }
    }
    cout<<x<<" "<<y;
}