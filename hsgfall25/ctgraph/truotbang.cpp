// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}

int n,m;
vector<string> a;
bool vis[205][205];
bool inq[205][205];

struct Node{
    int x,y;
};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};


int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    cin>>n>>m;
    a.resize(n);
    for(int i=0;i<n;i++) cin>>a[i];

    queue<Node> q;
    q.push({1,1});
    vis[1][1]=true;
    inq[1][1]=true;

    while(!q.empty()){
        auto cur=q.front(); q.pop();

        for(int d=0; d<4; d++){
            int x=cur.x, y=cur.y;
            while(true){
                int nx=x+dx[d], ny=y+dy[d];
                if(a[nx][ny]=='#') break;
                x=nx; y=ny;
                vis[x][y]=true;
            }
            if(!inq[x][y]){
                inq[x][y]=true;
                q.push({x,y});
            }
        }
    }

    int ans=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(vis[i][j]) ans++;
    cout<<ans;

    cerr << "time elapsed: "<<TIME <<"s.\n";
}


