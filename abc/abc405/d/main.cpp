#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    queue<pair<int, int>> q;
    vector<vector<int>> dist(H, vector<int>(W, -1));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == 'E') {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    auto check = [&](int x, int y) {
        return 0 <= x && x < H && 0 <= y && y < W;
    };
    vector<string> ans = S;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!check(nx, ny)) continue;
            if (dist[nx][ny] != -1) continue;
            if (S[nx][ny] == '#') continue;
            dist[nx][ny] = dist[x][y] + 1;
            if (i == 0) ans[nx][ny] = '^';
            else if (i == 1) ans[nx][ny] = 'v';
            else if (i == 2) ans[nx][ny] = '<';
            else if (i == 3) ans[nx][ny] = '>';
            q.push({nx, ny});
        }
    }

    for (int i = 0; i < H; i++) {
        cout << ans[i] << endl;
    }
}
