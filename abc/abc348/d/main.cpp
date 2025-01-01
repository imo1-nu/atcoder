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
    for (int i = 0; i < H; ++i) {
        cin >> S[i];
    }

    int sx, sy, gx, gy;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (S[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            else if (S[i][j] == 'T') {
                gx = i;
                gy = j;
            }
        }
    }

    int N;
    cin >> N;
    vector<int> R, C, E;
    R.push_back(sx);
    C.push_back(sy);
    E.push_back(0);
    for (int i = 0; i < N; ++i) {
        int r, c, e;
        cin >> r >> c >> e;
        r--; c--;
        R.push_back(r);
        C.push_back(c);
        E.push_back(e);
    }
    R.push_back(gx);
    C.push_back(gy);
    E.push_back(0);

    vector<vector<int>> G(N + 2);
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    auto check = [&](int x, int y) {
        return 0 <= x && x < H && 0 <= y && y < W;
    };
    auto bfs = [&](int s) {
        vector<vector<int>> dist(H, vector<int>(W, -1));
        queue<pair<int, int>> que;
        que.push({R[s], C[s]});
        dist[R[s]][C[s]] = 0;
        while (!que.empty()) {
            auto [x, y] = que.front();
            que.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (!check(nx, ny) || S[nx][ny] == '#') {
                    continue;
                }
                if (dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    que.push({nx, ny});
                }
            }
        }

        for (int i = 0; i < N + 2; ++i) {
            if (i == s) {
                continue;
            }
            if (dist[R[i]][C[i]] != -1 && dist[R[i]][C[i]] <= E[s]) {
                G[s].push_back(i);
            }
        }
    };

    for (int i = 0; i < N + 2; ++i) {
        bfs(i);
    }

    vector<bool> used(N + 2, false);
    used[0] = true;
    function<bool(int)> dfs = [&](int v) {
        if (v == N + 1) {
            return true;
        }
        for (int u : G[v]) {
            if (used[u]) continue;
            used[u] = true;
            if (dfs(u)) {
                return true;
            }
        }
        return false;
    };

    if (dfs(0)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
