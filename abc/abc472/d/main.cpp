#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> S(H);
    for (auto& s : S) cin >> s;

    set<int> X, Y;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                X.insert(i);
                Y.insert(j);
            }
        }
    }

    queue<pair<int, int>> q;
    vector<vector<int>> dist(H, vector<int>(W, -1));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#' || X.count(i) || Y.count(j)) continue;
            q.push({i, j});
            dist[i][j] = 0;
        }
    }

    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};

    auto can_move = [&](int x, int y) {
        if (0 <= x && x < H && 0 <= y && y < W) return true;
        else return false;
    };


    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!can_move(nx, ny) || S[nx][ny] == '#' || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (dist[i][j] != -1 && dist[i][j] <= K) ans++;
        }
    }
    cout << ans << endl;
}
