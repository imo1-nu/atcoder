#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};
int H, W, D;

bool canmove(int x, int y) {
    if (0 <= x && x < H && 0 <= y && y < W) return true;
    else return false;
}

void bfs(vector<string> &S, vector<vector<int>> &dist, vector<pair<int, int>> starts) { //G, distを用意する
    //初期条件
    queue<pair<int, int>> q;
    for (auto [x, y] : starts) {
        dist[x][y] = 0;
        q.push({x, y});
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (!canmove(nx, ny)) continue;
            if (S[nx][ny] == '#' || S[nx][ny] == 'H') continue;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> H >> W >> D;
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    vector<pair<int, int>> Hpos;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == 'H') {
                Hpos.push_back({i, j});
            }
        }
    }

    vector<vector<int>> dist(H, vector<int>(W, -1));
    bfs(S, dist, Hpos);

    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (dist[i][j] != -1 && dist[i][j] <= D) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
