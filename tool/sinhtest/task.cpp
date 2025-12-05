#include<bits/stdc++.h>
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
int t;bool snt[3000000];
void sang(){
    memset(snt,true,sizeof(snt));
    snt[0]=snt[1]=false;
    for(int i=2;i*i<=3000000;i++){
        if(snt[i]==true){
        for(int j=i*i;j<=3000000;j+=i)snt[j]=false;
        }
    }
}
int tong(int x){
    int sum=0;
    while(x!=0){
        sum+=x%10;
        x/=10;
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("task.INP","r",stdin);
    freopen("task.OUT","w",stdout);
    cin>>t;sang();vector<int>a;
    for(int i=0;i<3000000;i++){
        if(snt[i]==true&&tong(i)%5==0){
            a.push_back(i);
        }
    }
    for(int i=0;i<t;i++){
        int l,r,ans=0;
        cin>>l>>r;
        int left=lower_bound(a.begin(),a.end(),l)-a.begin();
        int right=upper_bound(a.begin(),a.end(),r)-a.begin();
        ans = right - left;
        cout<<ans<<endl;
    }
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
