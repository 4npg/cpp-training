// author : anphung

#include<bits/stdc++.h>
#define el cout<<"\n"
#define f0(i,n) for(int i=0;i<n;++i)
#define file "demsoduk"
using namespace std;
mt19937 rd(time(0));
int Rand(int l, int r) {
    return l + rd() % (r - l + 1);
}
void sinhsub1() {
    ofstream cout(file".inp");
    int n,k;
    n = Rand(1,2000);
    k = Rand(1,100);
    cout<<n<<" "<<k<<'\n';
    f0(i,n){
        int a = Rand(1,1000);
        cout<<a<<" ";
    }
}
void sinhsub2(){
    ofstream cout(file".inp");
    int n,k;
    n = Rand(1,2000);
    k = Rand(1,100);
    cout<<n<<" "<<k<<'\n';
    f0(i,n){
        int a = Rand(1,2000);
        cout<<a<<" ";
    }
}
void sinhsub3(){
    ofstream cout(file".inp");
    int n,k;
    n = Rand(1,2000);
    k = 0;
    cout<<n<<" "<<k<<'\n';
    f0(i,n){
        int a = Rand(1,2000);
        cout<<a<<" ";
    }
}
void sinhsub4(){
    ofstream cout(file".inp");
    int n,k;
    n = Rand(1,300000);
    k = Rand(1,100000);
    cout<<n<<" "<<k<<'\n';
    f0(i,n){
        int a = Rand(1,100000);
        cout<<a<<" ";
    }
}
int main()
{
    for (int i=1; i<=100; i++) {
        if(i>=1&&i<=20)sinhsub1();
        else if(i>=21&&i<=40)sinhsub2();
        else if(i>=41&&i<=60)sinhsub3();
        else if(i>=60)sinhsub4();
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
