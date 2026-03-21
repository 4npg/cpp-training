#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file "task"

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int Rand(int l, int r){
	return l+rng()%(r-l+1);
}

void Sinh(){
	ofstream cout(file".inp");

	int a = Rand(1, 1000);
	int b = Rand(1, 1000);

	cout<<a<<" "<<b;
}

int32_t main(){

	for(int i=10; ~i; i--){
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