// author : anphung
// github : 4npg  >>tqn
#include<bits/stdc++.h>
using namespace std;
#define TASK "CAU3"
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

string s;
int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	if(fopen(TASK".inp","r")){
		freopen(TASK".inp","r",stdin);
		freopen(TASK".out","w",stdout);
	}
	cin>>s;
	int sum = 0;
	for(auto &x:s){
		sum+= x-48;
	}
	sum%=3;
	vector<int> cnt(3,0);
	cnt[0] = 1;
	int pre=0;
	int ans=0;
	for(int j=0;j<s.size();++j){
		pre += s[j]-'0';
		int target = ((pre%3) - sum+3)%3;
		ans += cnt[target];
		cnt[pre%3]++;
	}
	if(sum==0)ans++;
	cout<<ans;
}


