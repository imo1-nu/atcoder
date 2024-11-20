#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

vector<int> dx = {0, 0, -1, 1, -1, -1, 1, 1};
vector<int> dy = {-1, 1, 0, 0, -1, 1, 1, -1};
int H, W;

bool canmove(int x, int y) {
    if (0 <= x && x < H && 0 <= y && y < W) return true;
    else return false;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> H >> W;
    int rs, cs, rt, ct;
    cin >> rs >> cs >> rt >> ct;
    rs--; cs--; rt--; ct--;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];
    vector<vector<vector<int>>> dist(H, vector<vector<int>>(W, vector<int>(4, 1000000000)));
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < 4; i++) {
        dist[rs][cs][i] = 0;
        q.push({rs, cs, i});
    }
    while (!q.empty()) {
        auto [x, y, d] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int cost = dist[x][y][d];
            if (d != i) cost++;
            if (!canmove(nx, ny)) continue;
            if (S[nx][ny] == '#') continue;
            if (dist[nx][ny][i] <= cost) continue;
            dist[nx][ny][i] = cost;
            if (d == i) q.push({nx, ny, i});
            else q.push({nx, ny, i});
        }
    }
    int ans = 1000000000;
    for (int i = 0; i < 4; i++) {
        ans = min(ans, dist[rt][ct][i]);
    }
    cout << ans << endl;
}
