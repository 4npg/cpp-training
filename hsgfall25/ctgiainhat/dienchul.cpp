// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

int n,x,y,cur_id=1;
vector<vector<int>> a;

void tile(int r,int c,int sz,int hr,int hc){
    if(sz==1)return;
    int mid=sz/2;
    int rm=r+mid-1, cm=c+mid-1;

    int q;
    if(hr<=rm && hc<=cm) q=0;
    else if(hr<=rm && hc>cm) q=1;
    else if(hr>rm && hc<=cm) q=2;
    else q=3;

    int id=cur_id++;
    if(q!=0) a[rm][cm]=id;
    if(q!=1) a[rm][cm+1]=id;
    if(q!=2) a[rm+1][cm]=id;
    if(q!=3) a[rm+1][cm+1]=id;

    if(q==0) tile(r,c,mid,hr,hc);
    else tile(r,c,mid,rm-r,cm-c);

    if(q==1) tile(r,c+mid,mid,hr,hc);
    else tile(r,c+mid,mid,rm-r,(cm+1)-(c+mid));

    if(q==2) tile(r+mid,c,mid,hr,hc);
    else tile(r+mid,c,mid,(rm+1)-(r+mid),cm-c);

    if(q==3) tile(r+mid,c+mid,mid,hr,hc);
    else tile(r+mid,c+mid,mid,(rm+1)-(r+mid),(cm+1)-(c+mid));
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>x>>y;
    int N=1<<n;
    a.assign(N, vector<int>(N,0));

    tile(0,0,N,x-1,y-1);

    f0(i,0,N-1){
        f0(j,0,N-1){
            cout<<a[i][j];
            if(j+1<N)cout<<' ';
        }
        cout<<'\n';
    }

    cerr<<"time elapsed: "<<TIME<<"s.\n";
}
