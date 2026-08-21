#include<iostream>
using namespace std;
short m,n;
int cnt1,tmp,res=-2500000,cntdoc[260];
string s;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("task.inp","r",stdin);
    freopen("task.out","w",stdout);
    cin>>m>>n;
    while(m--){
        cin>>s;
        s=" "+s;
        tmp=0;
        for(size_t i=1;i<=n;++i){
            if(s[i]=='1'){
                cnt1++;
                tmp++;
                cntdoc[i]++;
            }
            else{
                res=(res>=tmp?res:tmp);
                tmp=0;
                res=(res>=cntdoc[i]?res:cntdoc[i]);
                cntdoc[i]=0;
            }
            if(i==n)
                res=(res>=tmp?res:tmp);
            if(m==0)
                res=(res>=cntdoc[i]?res:cntdoc[i]);
        }
    }
    cout<<cnt1<<" "<<res;
}
