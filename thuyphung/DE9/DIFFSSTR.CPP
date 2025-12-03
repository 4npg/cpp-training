// authur : anphung
// github : 4npg
#include<bits/stdc++.h>
#define TASK "DIFFSSTR"
using namespace std;
#define int64 long long
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define all(a) (a).begin(),(a).end()
int n;
string s;
unordered_map<string,int> freq;
int32_t main(){
	fast;
	if(fopen(TASK".inp","r")){
		freopen(TASK ".inp","r",stdin);
		freopen(TASK ".out","w",stdout);
	}
	cin>>n>>s;
	s=  "ABC";
	do {
		cout<<s;
		freq[s]++;
		if(freq[s]>=2){
			memset((all(freq)),0);
			break;
		}
		el;
	}while(next_permutation(all(s)));
}