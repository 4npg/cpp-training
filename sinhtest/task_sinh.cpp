#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file "task"

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rd(int l, int r){
	return uniform_int_distribution<int>(l, r)(rng);
}

void Sinh(){
	ofstream cout(file".inp");

    int m = rd(1, 10000);
    int n = rd(1, 260);

    cout << m << ' ' << n << '\n';
    for (int i = 0 ; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int op = rd(48, 49);
            cout << (char)op;
        }
        cout << '\n';
    }
}

int32_t main(){

	for(int i=10000000; ~i; i--){
		Sinh();
		system(file);
		system(file"_trau");

		if(system("fc " file".out " file".ans")){
			cout<<"Wrong";
			break;
		}

		cout<<"Correct\n";
	}

	cerr << "\ntime elapsed: "<<TIME<<"s.\n";
}
