#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int monkey_dx[] = {0, 0, -1, 1};
int monkey_dy[] = {-1, 1, 0, 0};

int horse_dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int horse_dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

struct node {
    int x, y;
    int depth;
    int countK;
};

int BFS(int w, int h, int k, const vector<vector<int>>& v) {
    vector<vector<vector<bool>>> visited(h, vector<vector<bool>>(w, vector<bool>(k + 1, false)));
    queue<node> q;
    visited[0][0][0] = true;
    q.push({0, 0, 0, 0});

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().depth;
        int countK = q.front().countK;
        q.pop();

        if (x == h - 1 && y == w - 1) {
            return d;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + monkey_dx[i];
            int ny = y + monkey_dy[i];

            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny][countK] && v[nx][ny] == 0) {
                visited[nx][ny][countK] = true;
                q.push({nx, ny, d + 1, countK});
            }
        }

        if (countK < k) {
            for (int i = 0; i < 8; i++) {
            int nx = x + horse_dx[i];
            int ny = y + horse_dy[i];

            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny][countK + 1] && v[nx][ny] == 0) {
                visited[nx][ny][countK + 1] = true;
                q.push({nx, ny, d + 1, countK + 1});

                }
            }
        }
    }

    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k, w, h;
    cin >> k >> w >> h;
    
    vector<vector<int>> v(h, vector<int>(w, 0));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> v[i][j];
        }
    }

    cout << BFS(w, h, k, v);
    return 0;
}
