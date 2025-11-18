// author : anphung >> npkly

#include<bits/stdc++.h>
#define el cout<<"\n"
#define int64 long long
#define f0(i,n) for(int i=0;i<n;++i)
#define file "SORT"
using namespace std;
mt19937 rd(time(0));
int Rand(int l, int r) {
    return l + rd() % (r - l + 1);
}
void sinh() {
    ofstream cout(file".inp");
    int n = Rand(2,1000000);
    cout<<n<<'\n';
    f0(i,n){
        int64 a = Rand(-1000000000,1000000000);
        cout<<a<<" ";
    }
}
int main()
{
    for (int i=1; i<=10000000; i++) {
        sinh();
        system(file);
        system(file"_trau");
        cout << "Test " << i << '\n';
        if (system("fc "file".out "file".ans")) {
            cout << "Wrong";
            break;
        }
        cout << "Correct\n";
    }

}
