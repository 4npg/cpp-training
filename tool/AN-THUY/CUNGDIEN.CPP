// authur : anphung
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);i<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define pb push_back
#define pob pop_back
#define maxn 20

int n;
int a[maxn][maxn];
bool checkCol[13],checkdgc1[26],checkdgc2[26];
vector<int> curx;
vector<int> cury;
int cur = 0;
int mi = INT_MAX;

void print(){
    f0(i, 0, 3){
        //cout<<curx[i]<<" "<<cury[i]<<" "<<a[curx[i]][cury[i]]<<'\n';
        cur+= a[curx[i]][cury[i]];
    }
    // cout<<cur;
    // cout<<'\n';
}
void Try(int pos){
    f0(col,1,n){
        int dgc1 = pos + col;
        int dgc2 = pos - col + 13;

        if(checkCol[col])continue;
        if(checkdgc1[dgc1])continue;
        if(checkdgc2[dgc2])continue;

        curx.pb(pos);
        cury.pb(col);

        checkCol[col] = 1;
        checkdgc1[dgc1] = 1;
        checkdgc2[dgc2] = 1;

        if(curx.size()==n){
            cur = 0;
            print();
            mi = min(mi, cur);
        }else Try(pos+1);

        curx.pob();
        cury.pob();

        checkCol[col] = 0;
        checkdgc1[dgc1] = 0;
        checkdgc2[dgc2] = 0;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("CUNGDIEN");
    cin>>n;

    f0(i, 1, n){
        f0(j, 1, n){
            cin>>a[i][j];
        }
    }

    Try(1);

    cout<<mi;
    cerr << "time elapsed: "<<TIME <<"s.\n";
}
