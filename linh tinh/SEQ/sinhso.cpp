#include <bits/stdc++.h>
using namespace std;

const string NAME = "WATERFILL";
const int NTEST = 30;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

long long Rand(long long L, long long R) {
    assert(L <= R);
    return L + rd() % (R - L + 1);
}

void make_folder(const string& path) {
#ifdef _WIN32
    string cmd = "mkdir " + path;
#else
    string cmd = "mkdir -p " + path;
#endif
    system(cmd.c_str());
}

int main() {
    bool allCorrect = true;
    vector<pair<string, string>> inputs_outputs;

    for (int iTest = 1; iTest <= NTEST; iTest++) {
        string inpFile = NAME + ".inp";
        string outFile = NAME + ".out";
        string ansFile = NAME + ".ans";

        ofstream inp(inpFile);

        int n;
        long long k;
        //if (iTest <= 15) {
            n = Rand(1, 100);            
            k = Rand(1, 1000);
        //} 
        // else {
        //     n = Rand(90000, 100000);      
        //     k = Rand(1, 1000000000);
        // }

        inp << n << " " << k << "\n";
        for (int i = 0; i < n; ++i) {
            //inp << Rand(1, 1000000000) << (i+1==n?'\n':' ');
            inp << Rand(1, 10000) << (i+1==n?'\n':' ');
        }
        inp.close();

        system((NAME + ".exe").c_str());
        system((NAME + "_trau.exe").c_str());

#ifdef _WIN32
        if (system(("fc " + outFile + " " + ansFile + " > nul").c_str()) != 0) {
#else
        if (system(("diff -w " + outFile + " " + ansFile).c_str()) != 0) {
#endif
            cout << "Test " << iTest << ": WRONG!\n";
            string cmd = "copy " + inpFile + " " + NAME + "_WRONG_" + to_string(iTest) + ".inp";
            system(cmd.c_str());
            allCorrect = false;
            break;
        }

        cout << "Test " << iTest << ": CORRECT!\n";

        ifstream finp(inpFile);
        ifstream fout(outFile);
        stringstream sinp, sout;
        sinp << finp.rdbuf();
        sout << fout.rdbuf();
        inputs_outputs.emplace_back(sinp.str(), sout.str());
    }

    if (allCorrect) {
        make_folder(NAME);
        for (int i = 1; i <= NTEST; ++i) {
            string testFolder = NAME + "/" + (i < 10 ? "0" : "") + to_string(i);
            make_folder(testFolder);

            ofstream fout1(testFolder + "/" + NAME + ".inp");
            fout1 << inputs_outputs[i - 1].first;
            fout1.close();

            ofstream fout2(testFolder + "/" + NAME + ".out");
            fout2 << inputs_outputs[i - 1].second;
            fout2.close();
        }
        cout << "✅ All tests correct! Test data saved in folder: " << NAME << "/\n";
    }

    return 0;
}
