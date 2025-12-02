// author : anphung
#include <bits/stdc++.h>
using namespace std;

#define TASK_NAME "A_plus_B"

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
long long Rand(long long l, long long r) {
    return l + rd() % (r - l + 1);
}

void generate_test(ofstream &fin, long long &a, long long &b) {
    a = Rand(1, 1000000000);
    b = Rand(1, 1000000000);
    fin << a << " " << b << "\n";
}

int32_t main() {

    string task_name = TASK_NAME;
    system(("mkdir " + task_name).c_str());

    for (int i = 1; i <= 30; i++) {
        char buf[10];
        sprintf(buf, "test%02d", i); // test01 ... test30
        string test_folder = task_name + "\\" + buf;

        system(("mkdir " + test_folder).c_str());

        string inp = test_folder + "\\" + task_name + ".inp";
        string out = test_folder + "\\" + task_name + ".out";

        long long a, b;

        ofstream fi(inp);
        generate_test(fi, a, b);

        ofstream fo(out);
        fo << (a + b) << "\n";
    }

    return 0;
}
