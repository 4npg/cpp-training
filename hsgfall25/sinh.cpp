// author : anphung >> npkly

#include<bits/stdc++.h>
#define el cout<<"\n"
#define f0(i,n) for(int i=0;i<n;++i)
#define file ""
using namespace std;
mt19937 rd(time(0));
int Rand(int l, int r) {
    return l + rd() % (r - l + 1);
}
void sinh() {
    ofstream cout(file".inp");

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
