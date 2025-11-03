// author : anphung >> npkly

#include<bits/stdc++.h>
#define el cout<<"\n"
#define f0(i,n) for(int i=0;i<n;++i)
#define maxn
#define file "chianhom"
using namespace std;
mt19937 rd(time(0));
int Rand(int l, int r) {
    return l + rd() % (r - l + 1);
}
void sinh1() {
    ofstream cout(file".inp");

    int n = Rand(1,13);
    cout<<n<<'\n';
    f0(i,n){
        int a= Rand(1,(int)100);
        cout<<a<<"\n";
    }
}

void sinh2(){
    ofstream cout( file".inp");

    int n = Rand(1,(int)500);
    cout<<n<<'\n';
    f0(i,n){
        int a = Rand(1,(int)1e4);
        cout<<a<<"\n";
    }
}

int main()
{
    for (int i=1; i<=100; i++) {
        if(i<=40)sinh1();
        else sinh2();
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
