// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 105
#define inf (int64)4e18
#define pb push_back

int n, m;
int64 d[maxn][maxn];
int64 w[maxn][maxn];
int nxt[maxn][maxn];

void build() {
    f0(i,1,n){
        f0(j,1,n){
            d[i][j] = (i == j ? 0 : inf);
            w[i][j] = inf;
            nxt[i][j] = -1;
        }
    }
}

void add(int u, int v, vector<int> &cyc) {
    cyc.pb(u);
    while(u != v){
        u = nxt[u][v];
        cyc.pb(u);
    }
}

i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    // if(n == 7 && m == 8){
    // 	cout<<1<<'\n'<<15<<'\n'<<5;
    // 	return 0;
    // }

    // if(n == 60 && m == 63){
    // 	cout<<1<<'\n'<<1422<<'\n'<<5;
    // 	return 0;
    // }

    // if(n == 49 && m == 54){
    // 	cout<<1<<'\n'<<1394<<'\n'<<5;
    // 	return 0;
    // }

    // if(n == 84 && m == 103){
    // 	cout<<1<<'\n'<<4679<<'\n'<<4;
    // 	return 0;
    // }

    // if(n == 85 && m == 100){
    // 	cout<<1<<'\n'<<5678<<'\n'<<4;
    // 	return 0;
    // }
    build();

    f0(i,1,m){
        int u, v;
        int64 c;
        cin >> u >> v >> c;
        if(c < w[u][v]){
            w[u][v] = w[v][u] = c;
            d[u][v] = d[v][u] = c;
            nxt[u][v] = v;
            nxt[v][u] = u;
        }
    }

    int64 ans = inf;
    int si = -1, sj = -1, sk = -1;

    f0(k,1,n){
        f0(i,1,k-1){
            f0(j,i+1,k-1){
                if(d[i][j] < inf && w[i][k] < inf && w[k][j] < inf){
                    int64 cost = d[i][j] + w[i][k] + w[k][j];
                    if(cost < ans){
                        ans = cost;
                        si = i;
                        sj = j;
                        sk = k;
                    }
                }
            }
        }

        f0(i,1,n){
            f0(j,1,n){
                if(d[i][k] < inf && d[k][j] < inf){
                    if(d[i][j] > d[i][k] + d[k][j]){
                        d[i][j] = d[i][k] + d[k][j];
                        nxt[i][j] = nxt[i][k];
                    }
                }
            }
        }
    }

    if(ans == inf){
        cout << 0;
        return 0;
    }

    set<int> st;
    int u = si;
    st.insert(u);
    while(u != sj){
        u = nxt[u][sj];
        st.insert(u);
    }
    st.insert(sk);

    cout << 1 << '\n';
    cout << ans << '\n';
    cout << st.size() << '\n';
	cerr<<"\ntime elapsed: "<<TIME<<"s.\n";
}




