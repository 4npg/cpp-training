// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file ""

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//long long Rand(long long l, long long r){
//	return l+rng()%(r-l+1);
//}

#define maxn 1
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

string t, h;

string sub(string a, string b){
    while(b.size()<a.size()) b = '0' + b;
    string res = "";
    int tam = 0;
    fd(i,a.size()-1,0){
        int x = a[i]-'0' - (b[i]-'0') - tam;
        if(x<0){ x+=10; tam=1;} else tam=0;
        res = char(x+'0') + res;
    }
    while(res.size()>1 && res[0]=='0') res.erase(res.begin());
    return res;
}

string div2(string a){
    string res = "";
    int du = 0;
    for(char c:a){
        int cur = du*10 + (c-'0');
        res += (cur/2)+'0';
        du = cur%2;
    }
    while(res.size()>1 && res[0]=='0') res.erase(res.begin());
    return res;
}

string add(string a, string b){
    while(b.size()<a.size()) b='0'+b;
    string res="";
    int du=0;
    fd(i,a.size()-1,0){
        int x = (a[i]-'0') + (b[i]-'0') + du;
        du = x/10;
        x%=10;
        res = char(x+'0') + res;
    }
    if(du) res = char(du+'0') + res;
    return res;
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>t>>h;
	string tu = sub(t, h);
	string mau = div2(tu);
	string a = sub(t, mau);
	string b = mau;

	cout<<a<<"\n"<<b;
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
