#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int BFS(int n, int m, vector<vector<int>> maps) {
    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
    queue<pair<pair<int, int>, int>> q;

    visited[n][m] = true;
    int depth = 1;
    q.push({{n, m}, depth});

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();

        if (x == 0 && y == 0) {
            return d;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx <= n && ny >= 0 && ny <= m && !visited[nx][ny] && maps[nx][ny] == 1) {
                q.push({{nx, ny}, d + 1});
                visited[nx][ny] = true;
            }
        }
    }

    return -1;
}

int solution(vector<vector<int>> maps) {
    int n = maps.size() - 1;
    int m = maps[0].size() - 1;
    int answer = BFS(n, m, maps);

    return answer;
}