#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#define ll long long
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
void pa(ll n,ll a[100][100]){
	ll val = 1;
	for(ll i=0;i<n;i++){
		if(i%2==0){
			for(ll j=0;j<n;j++){
				a[i][j]=val;
				val++;
			}
		}else if(i%2!=0){
			for(ll j=n-1;j>=0;j--){
				a[i][j]=val;
				val++;
			}
		}
	}
}
void pb(ll n,ll a[100][100]){
	ll val = n*n;
	for(ll j=0;j<n;j++){
		if(j%2==0){
			for(ll i=0;i<n;i++){
				a[i][j]=val;
				val--;
			}
		}else if(j%2!=0){
			for(ll i=n-1;i>=0;i--){
				a[i][j]=val;
				val--;
			}
		}
	}
}
void pc(ll n,ll a[100][100]) {
    ll val = 1;
    ll tren=0,duoi=n-1;
    ll trai=0,phai=n-1;
    while (val <= n * n) {
        for (ll j=trai;j<=phai;j++)a[tren][j]=val++;
    	tren++;
        for (ll i=tren;i<=duoi;i++)a[i][phai]=val++;
        phai--;
        if (tren<=duoi) {
            for (ll j=phai;j>=trai;j--)a[duoi][j]=val++;
            duoi--;
        }
        if (trai<=phai) {
            for (ll i=duoi;i>=tren;i--)a[i][trai]=val++;
            trai++;
        }
    }
}


void pd(ll n, ll a[100][100]) {
    ll val = 1;
    for (ll k = 0; k <= 2 * n - 2; k++) {
        if (k % 2 == 0) {
            for (ll i = 0; i <= k; i++) {
                ll j = k - i;
                if (i < n && j < n) {
                    a[i][j] = val++;
                }
            }
        } else {
            for (ll i = k; i >= 0; i--) {
                ll j = k - i;
                if (i < n && j < n) {
                    a[i][j] = val++;
                }
            }
        }
    }
}
void print(ll n,ll a[100][100]){
	for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
void READFILE(){
    freopen("INP.TXT","r",stdin);
    freopen("OUT.TXT","w",stdout);
}
int main() {
    fast;
    ll n;
    cin >> n;
    ll a[100][100]; 
    // pa(n,a);
    // print(n,a);
   	// pb(n,a);
   	// print(n,a);
    // pc(n,a);
    // print(n,a);
    pc(n, a);
	print(n,a);
}
