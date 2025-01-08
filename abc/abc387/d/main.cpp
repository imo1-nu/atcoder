#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    int sx, sy;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }

    auto is_in = [&](int x, int y) {
        return 0 <= x && x < H && 0 <= y && y < W;
    };
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    vector<vector<vector<int>>> dist(H, vector<vector<int>>(W, vector<int>(2, -1)));
    queue<tuple<int, int, int>> q;
    q.push({sx, sy, 0});
    q.push({sx, sy, 1});
    dist[sx][sy][0] = 0;
    dist[sx][sy][1] = 0;
    while (!q.empty()) {
        auto [x, y, c] = q.front();
        q.pop();
        if (S[x][y] == 'G') {
            cout << dist[x][y][c] << endl;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            if ((c ^ i) % 2 == 0) continue;
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nc = c ^ 1;
            if (!is_in(nx, ny)) continue;
            if (S[nx][ny] == '#') continue;
            if (dist[nx][ny][nc] != -1) continue;
            dist[nx][ny][nc] = dist[x][y][c] + 1;
            q.push({nx, ny, nc});
        }
    }
    cout << -1 << endl;
}
