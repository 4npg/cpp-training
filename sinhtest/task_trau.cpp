#include<iostream>
using namespace std;
int n,x,res=0,suoc[5000010];
#define file "task"

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".ans","w",stdout);
    cin>>n;
    for(int i=1;i<=5000010;++i)
        for(int j=i+i;j<=5000010;j+=i)
            suoc[j]+=i;
    for(int i=0;i<n;++i){
        cin>>x;
        if(suoc[x]<x)
            res++;
    }
    cout<<res;
}
