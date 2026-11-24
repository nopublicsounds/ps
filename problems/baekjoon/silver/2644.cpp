#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s, e;
    int m;
    cin >> n >> s >> e >> m;
    vector<vector<int>> v(n + 1, vector<int>());

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    queue<pair<int, int>> q;
    vector<bool> visited(n + 1, false);
    visited[s] = true;
    q.push({s, 0});

    while(!q.empty()) {
        int next = q.front().first;
        int depth = q.front().second;
        if (next == e)
        {
            cout << depth;
            return 0;
        }

        for (int i = 0; i < v[next].size(); i++) {
            if (visited[v[next][i]]) {
                continue;
            }
            q.push({v[next][i], depth + 1});
            visited[v[next][i]] = true;
        }

        q.pop();
    }

    cout << -1;
    return 0;
}
