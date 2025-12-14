#include<bits/stdc++.h>
#define maxn 1000006
using namespace std;
long long l, r;
int d[maxn];

void sang(){
    f0(i, 2, maxn){
        int64 st = (l+i-1)/i*i;
        for(int j=0; st+j<=r; j+=i)if(st+j!=i)d[st+j-l] = 1;
    }
}

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> l >> r;
    for (int i=2; i<=1e6; i++)
    {
        long long st = (l + i - 1) / i * i;
        for (int j=0; st + j <= r; j += i) if (st + j != i)
            d[st + j - l] = 1;
    }
    for (int i=0; i<=r-l; i++) if (d[i] == 0 && i + l > 1) cout << i + l << ' ';
}