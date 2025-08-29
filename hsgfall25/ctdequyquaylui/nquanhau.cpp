// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "queens"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(int (i)=(a);i<=(b);++i)
#define pb push_back
#define pob pop_back

int n = 8;
bool isinCol[13], isinDiag1[26], isinDiag2[26];
vector<int> curx, cury;
int cnt = 0;
char board[9][9];

void Try(int pos){
    FOR(curCol,1,n){
        if(board[pos][curCol] == '*') continue;
        int curDiag1 = pos + curCol;
        int curDiag2 = pos - curCol + 13;

        if(isinCol[curCol]) continue;
        if(isinDiag1[curDiag1]) continue;
        if(isinDiag2[curDiag2]) continue;

        curx.pb(pos);
        cury.pb(curCol);

        isinCol[curCol] = true;
        isinDiag1[curDiag1] = true;
        isinDiag2[curDiag2] = true;

        if((int)curx.size() == n){
            cnt++;
        } else Try(pos+1);

        curx.pob();
        cury.pob();

        isinCol[curCol] = false;
        isinDiag1[curDiag1] = false;
        isinDiag2[curDiag2] = false;
    }
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    FOR(i,1,8) FOR(j,1,8) cin >> board[i][j];
    Try(1);
    cout << cnt;
}
