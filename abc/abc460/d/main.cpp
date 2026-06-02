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
    for (auto& s : S) cin >> s;

    auto check = [&](int x, int y) {
        if (0 <= x && x < H && 0 <= y && y < W) return true;
        return false;
    };
    vector<int> dx = {0, -1, -1, -1, 0, 1, 1, 1};
    vector<int> dy = {1, 1, 0, -1, -1, -1, 0, 1};

    auto nS = S;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                nS[i][j] = '.';
                continue;
            }
            for (int k = 0; k < 8; k++) {
                int ni = i + dx[k], nj = j + dy[k];
                if (!check(ni, nj)) continue;
                if (S[ni][nj] == '#') nS[i][j] = '#';
            }
        }
    }
    S = nS;

    queue<pair<int, int>> q;
    vector<vector<int>> kakutei(H, vector<int>(W, -1));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                q.push({i, j});
                kakutei[i][j] = 0;
            }
        }
    }

    if (q.empty()) {
        for (auto s : S) cout << s << endl;
        return 0;
    }

    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!check(nx, ny) || kakutei[nx][ny] != -1) continue;
            kakutei[nx][ny] = kakutei[x][y] ^ 1;
            q.push({nx, ny});
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << (kakutei[i][j] ? '#' : '.');
        }
        cout << endl;
    }
}
