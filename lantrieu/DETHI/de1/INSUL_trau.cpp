#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
long long res=0;
int main(){
    freopen("INSUL.INP","r",stdin);
    freopen("INSUL.out","w",stdout);
    cin>>n;
    vector<int> an(n+1);
    an[0]=0;
    for(int i=1;i<=n;++i){
        cin>>an[i];
        res+=an[i];
    }
    sort(an.begin(),an.end());
    for(int i=1;i<=n/2;++i)
        res+=(an[n-i+1]-an[i]);
    cout<<res;
}
