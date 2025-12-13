// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    

    dãy số : 1 dãy các phần tử có quy luật liên hệ với
    nhau 
    (un) : u1 u2 u3 u4 ... un

    cấp số cộng : là dãy số mà các phần tử cách nhau 
    đúng bằng 1 số d ( công sai )

    u1 = 1;
    u2 = u1 + d;
    u3 = u2 + d;
    u3 = u1 + 2d;
    u4 = u3 + d;
    u4 = u1 + 3d;
    un = un-1 + d;
    un = u1 + (n-1)d

    tính sn = u1 + u2 + u3 +... + un
    
    viết các u theo u1 

    u1 + (u1+d) + (u1+2d) + ... + (u1 + (n-1)d)

    u1 + u1 + d + u1 + 2d + ... + u1 + (n-1)d

    n(u1) + d + 2d + 3d + ... + (n-1)d
            d ( 1 + ... + n-1)

    n*u1 + d * ( (n*(n-1))/2);
    u1 = 1;
    d = 2;
    n = 10;
    1 3 5 7 9 11 13 15 17 19 = 100
    1 2 3 4 5 6  7  8  9  10

    cấp số nhân : là dãy số mà phần tử sau gấp phần tử trước
    đúng bằng 1 số q ( công bội )
    u1 = 1;
    q = 2;
    u2 = u1 * q;
    u3 = u2 * q;
    un = u1 * q^(n-1) 
    tính tổng cấp số nhân (un) với u1 = 2 q = 3; n = 10;
    cerr << "time elapsed: "<<TIME <<"s.\n";
}


