#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x > y) {
            x = y;
            return true;
        } else return false;
    }

template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y) {
            x = y;
            return true;
        } else return false;
    }

#define MAX   200200
int numGame, playTime, watchTime, limit;
int value[MAX];

void init(void) {
    scanf("%d%d%d%d", &numGame, &limit, &playTime, &watchTime);
    FOR(i, 1, numGame) scanf("%d", &value[i]);
}

void process(void) {
    priority_queue<int, vector<int>, greater<int>> games;
    long long sumValue = 0;

    long long res = 0;
    int maxPlay = 1;
    FOR(i, 1, numGame) {
        maxPlay++;
        minimize(maxPlay, i);
        while (maxPlay > 0 && 1LL * maxPlay * playTime + 1LL * (i - maxPlay) * watchTime > limit) maxPlay--;

        games.push(value[i]);
        sumValue += value[i];

        while ((int)games.size() > maxPlay) {
            sumValue -= games.top(); games.pop();
        }
        maximize(res, sumValue);
    }

    cout << res << "\n";
}

int main(void) {
    init();
    process();
    return 0;
}
