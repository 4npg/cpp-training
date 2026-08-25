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
    int n = rd(10, 20);
    cout << n << '\n';

    for (int i = 0; i < n; i++) {
        int x = rd(10, 500);
        cout << x << ' ';
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
