// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// void Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn 

i_love_Hoang_Ngan(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int N,M;
    cin>>N>>M;

    vector<vector<int>> g(N+1);
    f0(i,1,M){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<char> vis(N+1,0);
    int C=0;

    f0(i,1,N){
        if(!vis[i]){
            C++;
            stack<int> st;
            st.push(i);
            vis[i]=1;
            while(!st.empty()){
                int u=st.top(); st.pop();
                for(int v:g[u]){
                    if(!vis[v]){
                        vis[v]=1;
                        st.push(v);
                    }
                }
            }
        }
    }

    cout<<M-N+C;
    
    cerr << "time elapsed: "<<TIME <<"s.\n";
}





