// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}

int a[20][30];
bool isinCol[20][20],isinRow[20][20],isin3x3[20][20][20];

bool Try(int row = 0,int col = 0){
    if(row == 9)return true;
    if(col == 9)return Try(row+1,0);
    if(a[row][col]!=0)return Try(row,col+1);

    f0(i,1,9){
        if(!isinCol[col][i]&&!isinRow[row][i]&&!isin3x3[row/3][col/3][i]){
            a[row][col] = i;
            isinCol[col][i] = isinRow[row][i] = isin3x3[row/3][col/3][i] = true;
            if(Try(row,col+1))return true;
            a[row][col]  = 0;
            isinCol[col][i] = isinRow[row][i] = isin3x3[row/3][col/3][i] = false;
        }
    }
    return false;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);
    f0(i,0,8){
        f0(j,0,8){
            cin>>a[i][j];
            if(a[i][j]){
                isinCol[j][a[i][j]] = true;
                isinRow[i][a[i][j]] = true;
                isin3x3[i/3][j/3][a[i][j]] = true;
            }
        }
    }    
    if(Try()){
        f0(i,0,8){
            f0(j,0,8){
                cout<<a[i][j]<<" ";
            }
            cout<<'\n';
        }
    }

    cerr << "time elapsed: "<<TIME <<"s.\n";
}


