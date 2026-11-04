#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int BFS(int x, int y, int n, int m, vector<vector<int>>& picture, vector<vector<bool>>& visited) {
    int mark = picture[x][y];
    visited[x][y] = true;
    queue<pair<int, int>> q;
    q.push({x, y});
    int depth = 1;

    while (!q.empty()) {
        for (int i = 0; i < 4; i++) {
            int nx = q.front().first + dx[i];
            int ny = q.front().second + dy[i];

            if (isValid(nx, ny, n, m) && picture[nx][ny] == mark && !visited[nx][ny]) {
                depth++;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }

        q.pop();
    }

    return depth;
}

vector<int> solution(int n, int m, vector<vector<int>> picture) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int count = 0;
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] || picture[i][j] == 0) {
                continue;
            }  

            int currentArea = BFS(i, j, n, m, picture, visited);
            maxArea = max(currentArea, maxArea);
            count++;
        }
    }

    return {count, maxArea};
}