// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define pb push_back

int n, q;
string s;


i_love_Hoang_Ngan(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>q>>s;

	vector< deque<int> > pos(26);

	f0(i, 0, n-1){
		pos[s[i]-'A'].pb(i);
	}

	vector<int> unvis(n, 1);

	while(q--){
		int type; cin>>type;

		if(type == 0){
			f0(c, 0, 25){
				while(!pos[c].empty() && !unvis[pos[c].front()])
					pos[c].pop_front();

				if(!pos[c].empty()){
					unvis[pos[c].front()] = 0;
					pos[c].pop_front();
					break;
				}
			}
		}else {
			for(int c=25; c>=0; --c){
				while(!pos[c].empty() && !unvis[pos[c].front()])
					pos[c].pop_front();

				if(!pos[c].empty()){
					unvis[pos[c].front()] = 0;
					pos[c].pop_front();
					break;
				}
			}
		}
		
	}	
	f0(i, 0, n-1){
			if(unvis[i])cout<<s[i];
	}
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


