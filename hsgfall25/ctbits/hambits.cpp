// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int64 n;


int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	cout<<__builtin_popcountll(n)<<" ";
	cout<<63 - __builtin_clzll(n)<<" ";
	cout<<__builtin_ctzll(n);
}


