#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};
int H, W;

bool canmove(int x, int y) {
    if (0 <= x && x < H && 0 <= y && y < W) return true;
    else return false;
}

int sx, sy;
int ans = -1;

void dfs(int x, int y, vector<string>& S, vector<vector<bool>>& visited, int depth) {
    if (depth != 0) visited[x][y] = true;
    if (depth != 0 && x == sx && y == sy) {
        if (depth > 2) ans = max(ans, depth);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!canmove(nx, ny)) continue;
        if (S[nx][ny] == '#') continue;
        if (visited[nx][ny]) continue;
        dfs(nx, ny, S, visited, depth + 1);
        visited[nx][ny] = false;
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; ++i) {
        cin >> S[i];
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            sx = i; sy = j;
            if (S[i][j] == '#') continue;
            vector<vector<bool>> visited(H, vector<bool>(W, false));
            dfs(i, j, S, visited, 0);
        }
    }

    cout << ans << endl;
}
