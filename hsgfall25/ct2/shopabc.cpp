// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

int64 n,i,j, f[200005],l,r=0,d=0; 
string s;
void tinh(char x){
	for(i=1;i<=n;i++){
		if(s[i]==x)r++; 
		else r--; 
		if(r>0)d=max(d,i); 
		else{ 
			if(f[abs(r)]==0){
				f[abs(r)]=i;
			} 
			if(f[abs(r)+1]!=0)d=max(d,i-f[abs(r)+1]); 
		} 
	} 
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>s;
	s = " " + s;
	tinh('a');
	tinh('b');
	tinh('c');
	cout<<d;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


