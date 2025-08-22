// author : anphung
// github : 4npg  >>tqn
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define all(a) (a).begin(),(a).end()
struct viec {
	int an,bi,dif;
};
int n;
int64 res;
bool cmp(viec a,viec b){
	return a.dif<b.dif;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	vector<viec> a(2*n);
	f0(i,0,2*n-1){
		cin>>a[i].an>>a[i].bi;
		a[i].dif = a[i].an - a[i].bi;
	}	
	sort(all(a),cmp);
	f0(i,0,n-1){
		res+=a[i].an;
	}
	f0(i,n,2*n-1){
		res+=a[i].bi;
	}
	cout<<res;
}


