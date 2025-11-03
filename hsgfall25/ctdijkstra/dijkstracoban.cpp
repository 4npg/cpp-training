// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define pb push_back

int n,m;
const int maxn = 2e5+10;
vector< pair<int,int64> > a[maxn];
// mảng các vector
// để lưu các đỉnh kề
const int64 inf = 2e18;
int pre[maxn];

void dijkstra(int s){
    vector<int64> d(n + 1, inf);
    // kc giữa các node hay các đỉnh ban đầu được xét là full inf
    // có nghĩa là giả dụ ban đầu khoảng cách từ đỉnh nguồn đến mọi đỉnh luôn là dương vô cùng
    d[s] = 0;
    // có nghĩa là khoảng cách từ đỉnh nguồn đến chính nó luôn 0
    priority_queue<pair<int64, int>, vector<pair<int64, int>> , greater<pair<int64,int>>> Q;  
    // hoạt động là lấy theo giá trị max, nhưng có greater thì lại xét theo min
    // thỏa mãn việc luôn chọn đỉnh có đường đi ngắn nhất và loại bỏ được đỉnh vừa chọn  
    Q.push({0, s});
    while(!Q.empty()){
    
        auto top = Q.top(); Q.pop();
        int u = top.second;
        int64 kc = top.first;
        if(kc > d[u]) continue;

        for(auto it : a[u]){
            int v = it.first;
            int64 w = it.second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << d[i] << ' ';
    }
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    f0(i,0,m-1){
        int u,v;
        int64 w;
        cin>>u>>v>>w;
        a[u].pb({v,w});
    }
    dijkstra(1);
    cerr << "time elapsed: "<<TIME <<"s.\n";
}
