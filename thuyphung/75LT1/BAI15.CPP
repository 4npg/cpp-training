#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define oo 1e9
void xuli(const vector<vector<int>>& h,vector<vector<int>>& M,int m, int n,int dir){
    if (dir == 0) { 
        for (int j = 0; j < n; j++) {
            int cur = -oo;
            for (int i = 0; i < m; i++) {
                M[i][j] = cur;
                cur = max(cur, h[i][j]);
            }
        }
    }
    else if (dir == 1) { 
        for (int j = 0; j < n; j++) {
            int cur = -oo;
            for (int i = m-1; i >= 0; i--) {
                M[i][j] = cur;
                cur = max(cur, h[i][j]);
            }
        }
    }
    else if (dir == 2) { 
        for (int i = 0; i < m; i++) {
            int cur = -oo;
            for (int j = 0; j < n; j++) {
                M[i][j] = cur;
                cur = max(cur, h[i][j]);
            }
        }
    }
    else {
        for (int i = 0; i < m; i++) {
            int cur = -oo;
            for (int j = n-1; j >= 0; j--) {
                M[i][j] = cur;
                cur = max(cur, h[i][j]);
            }
        }
    }
}

int main(){
	fast;
    int m, n;
    cin >> m >> n;
    vector<vector<int>> h(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> h[i][j];

    vector<vector<int>> MB(m, vector<int>(n)); 
    vector<vector<int>> MN(m, vector<int>(n)); 
    vector<vector<int>> MT(m, vector<int>(n)); 
    vector<vector<int>> MD(m, vector<int>(n)); 

    xuli(h, MB, m, n, 0);
    xuli(h, MN, m, n, 1);
    xuli(h, MT, m, n, 2);
    xuli(h, MD, m, n, 3);

    int result = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int cnt = 0;
            if (h[i][j] >= MB[i][j]) cnt++;
            if (h[i][j] >= MN[i][j]) cnt++;
            if (h[i][j] >= MT[i][j]) cnt++;
            if (h[i][j] >= MD[i][j]) cnt++;
            if (cnt == 1) result++;
        }
    }

    cout << result;
}
