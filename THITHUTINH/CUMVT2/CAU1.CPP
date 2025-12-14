// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

int xa, ya, xc, yc, xm, ym, xn, cailon;
int cnt;

inline bool valid(int xmin, int xmax, int ymin, int ymax, int x, int y){
    return (xmin < x && x < xmax && ymin < y && y < ymax);
}


int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>xa>>ya;
	cin>>xc>>yc;
	cin>>xm>>ym;
	cin>>xn>>cailon;

	int xmin = min(xa, xc);
	int xmax = max(xa, xc);
	int ymin = min(ya, yc);
	int ymax = max(ya, yc);

	cnt+=((valid(xmin, xmax, ymin, ymax, xm, ym))?1:0);
	cnt+=((valid(xmin, xmax, ymin, ymax, xn, cailon))?1:0);
	
	cout<<cnt;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


