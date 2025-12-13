// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    /*
     
    Ham tim kiem nhi phan built-in

    1. lower_bound : tim vi tri phan tu dau tien >= x
    2. upper_bound : tim vi tri phan tu dau tien > x

    
    Cach su dung

    VD : Cho mang a do dai n va so x can tim thi ta se co 2 ham nhu sau 
    
    - Voi mang tinh
    
    lower_bound(a, a+n, x);
    upper_bound(a, a+n, x);

    Luu y : neu su dung chi so la 1 --> thi doi thanh 

    lower_bound(a+1, a+n+1, x);
    upper_bound(a+1, a+n+1, x);


    - Voi mang dong ( vector )
    

    lower_bound(tenvec.begin(), tenvec.end(), x);
    upper_bound(tenvec.begin(), tenvec.end(), x);

    Luu y neu nhu bien vi tri la int thi phai - a hoac - a.begin()
    Con neu la iterator thi khong can 
    Vi du 
    cho mang tinh a do dai n 
    chi so cua a bat dau tu 0 den n-1

    goi vi tri so dau tien >= x la pos1 
    goi vi tri so dau tien > x la pos2
    
    ta co 
    int pos1 = lower_bound(a, a+n, x) - a;
    int pos2 = upper_bound(a, a+n, x) - a;

    con voi mang dong a thi se la

    int pos1 = lower_bound(a.begin(), a.end(), x) - a.begin();
    int pos2 = upper_bound(a.begin(), a.end(), x) - a.begin();

    */
    

    cerr << "time elapsed: "<<TIME <<"s.\n";
}


