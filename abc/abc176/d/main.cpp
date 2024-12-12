#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
vector<int> dx2; 
vector<int> dy2;
int H, W;

bool canmove(int x, int y) {
    if (0 <= x && x < H && 0 <= y && y < W) return true;
    else return false;
}

void bfs(vector<string> &S, vector<vector<int>> &dist, pair<int, int> start) { //G, distを用意する
    //初期条件
    dist[start.first][start.second] = 0;
    deque<pair<int, int>> dq;
    dq.push_back(start);

    while (!dq.empty()) {
        auto [x, y] = dq.front();
        dq.pop_front();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!canmove(nx, ny)) continue;
            if (S[nx][ny] == '#') continue;
            if (dist[nx][ny] <= dist[x][y]) continue;
            dist[nx][ny] = dist[x][y];
            dq.push_front({nx, ny});
        }

        for (int i = 0; i < dx2.size(); ++i) {
            int nx = x + dx2[i];
            int ny = y + dy2[i];
            if (!canmove(nx, ny)) continue;
            if (S[nx][ny] == '#') continue;
            if (dist[nx][ny] <= dist[x][y] + 1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            dq.push_back({nx, ny});
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> H >> W;
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    --sx; --sy; --gx; --gy;
    vector<string> S(H);
    for (int i = 0; i < H; ++i) {
        cin >> S[i];
    }

    for (int i = -2; i <= 2; ++i) {
        for (int j = -2; j <= 2; ++j) {
            if (abs(i) + abs(j) <= 1) continue;
            dx2.push_back(i);
            dy2.push_back(j);
        }
    }

    vector<vector<int>> dist(H, vector<int>(W, 1e9));
    bfs(S, dist, {sx, sy});
    if (dist[gx][gy] == 1e9) cout << -1 << endl;
    else cout << dist[gx][gy] << endl;
}
