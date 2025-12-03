#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define N 10

int n;
int cost[N][N]; // ma trận chi phí

struct Node {
    vector<vector<int>> reduced; // ma trận chi phí đã rút gọn
    vector<int> path;            // đường đi hiện tại
    int cost;                    // chi phí ước lượng hiện tại (bound)
    int vertex;                  // đỉnh hiện tại
    int level;                   // số đỉnh đã thăm
};

// Giảm hàng và cột để tính bound (chi phí ước lượng)
int reduceMatrix(vector<vector<int>>& mat) {
    int reduction = 0;

    // Giảm hàng
    for (int i = 0; i < n; i++) {
        int rowMin = INF;
        for (int j = 0; j < n; j++) rowMin = min(rowMin, mat[i][j]);
        if (rowMin != INF && rowMin > 0) {
            reduction += rowMin;
            for (int j = 0; j < n; j++) if (mat[i][j] != INF) mat[i][j] -= rowMin;
        }
    }

    // Giảm cột
    for (int j = 0; j < n; j++) {
        int colMin = INF;
        for (int i = 0; i < n; i++) colMin = min(colMin, mat[i][j]);
        if (colMin != INF && colMin > 0) {
            reduction += colMin;
            for (int i = 0; i < n; i++) if (mat[i][j] != INF) mat[i][j] -= colMin;
        }
    }

    return reduction;
}

// Tạo node con sau khi đi từ u -> v
Node createChild(Node parent, int u, int v) {
    Node child;
    child.reduced = parent.reduced;

    // Vô hiệu hóa đường đi quay lại u và rời khỏi v
    for (int i = 0; i < n; i++) {
        child.reduced[u][i] = INF;
        child.reduced[i][v] = INF;
    }
    // Không cho quay lại điểm bắt đầu từ điểm cuối
    child.reduced[v][parent.path[0]] = INF;

    child.path = parent.path;
    child.path.push_back(v);
    child.level = parent.level + 1;
    child.vertex = v;

    int reduction = reduceMatrix(child.reduced);
    child.cost = parent.cost + parent.reduced[u][v] + reduction;

    return child;
}

void solveTSP() {
    vector<vector<int>> init = cost;
    int reduction = reduceMatrix(init);

    priority_queue<pair<int, Node>, vector<pair<int, Node>>, greater<>> pq;

    Node start;
    start.reduced = init;
    start.cost = reduction;
    start.path = {0};
    start.level = 0;
    start.vertex = 0;

    pq.push({start.cost, start});

    int bestCost = INF;
    vector<int> bestPath;

    while (!pq.empty()) {
        auto [_, current] = pq.top(); pq.pop();

        if (current.level == n - 1) {
            int last = current.vertex;
            int first = current.path[0];
            int finalCost = current.cost + cost[last][first];
            if (finalCost < bestCost) {
                bestCost = finalCost;
                bestPath = current.path;
                bestPath.push_back(first);
            }
            continue;
        }

        for (int v = 0; v < n; v++) {
            if (current.reduced[current.vertex][v] != INF) {
                Node child = createChild(current, current.vertex, v);
                pq.push({child.cost, child});
            }
        }
    }

    cout << "Best cost: " << bestCost << "\nPath: ";
    for (int x : bestPath) cout << x << " ";
    cout << "\n";
}

int main() {
    cin >> n;
    FOR(i, 0, n-1) FOR(j, 0, n-1) cin >> cost[i][j];
    solveTSP();
}
