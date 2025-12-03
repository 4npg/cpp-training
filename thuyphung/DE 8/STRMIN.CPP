// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "STRMIN"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(int (i)=(a);i<=(b);++i)
#define pb push_back

int n,x,y,z;
string res;
bool found = false;

void Try(string s,int cx,int cy,int cz,char prev){
	if(found)return;
	if(s.size()==n){
		if(cx>=x&&cy>=y&&cz>=z){
			res = s;
			found = true;
		}
		return;
	}
	for(char c='0';c<='9';++c){
		if(c==prev)continue;
		Try(s+c,cx,cy,cz+1,c);
		if(found)return;
	}
	for(char c='A';c<='B';++c){
		if(c==prev)continue;
		Try(s+c,cx+1,cy,cz,c);
		if(found)return;
	}
	for(char c='a';c<='b';++c){
		if(c==prev)continue;
		Try(s+c,cx,cy+1,cz,c);
		if(found)return;
	}
}

void subtask1(){
	Try("",0,0,0,0);
	cout<<res;
}

void subtask2(){
	string sx="",sy="",sz="";
	FOR(i,0,x-1){
		sx.pb(char(i%2+65));
	}
	FOR(i,0,y-1){
		sy.pb(char(i%2+97));
	}
	FOR(i,0,n-x-y-1){
		sz.pb(char(i%2+48));
	}
	cout<<sz+sx+sy;
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    cin>>n>>x>>y>>z;
    if(n<=10){
    	subtask1();
    }else{
    	subtask2();
    }
}


