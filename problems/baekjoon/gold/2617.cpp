#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 1, vector<int>(n + 1, INT32_MAX));
    for (int i = 1; i <= n; i++) {
        v[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x][y] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (v[i][k] != INT32_MAX && v[k][j] != INT32_MAX) {
                    v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
                }
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        int heavier = 0, lighter = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (v[j][i] != INT32_MAX) heavier++;
            if (v[i][j] != INT32_MAX) lighter++;
        }
        if (heavier > n / 2 || lighter > n / 2) answer++;
    }
    cout << answer << '\n';

    return 0;
}
