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

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> H >> W >> N >> M;
    vector<pair<int, int>> light(N), block(M);
    for (int i = 0; i < N; i++) {
        cin >> light[i].first >> light[i].second;
        light[i].first--;
        light[i].second--;
    }
    for (int i = 0; i < M; i++) {
        cin >> block[i].first >> block[i].second;
        block[i].first--;
        block[i].second--;
    }

    vector<vector<int>> grid1(H, vector<int>(W, 0));
    for (int i = 0; i < M; i++) {
        grid1[block[i].first][block[i].second] = -1;
    }
    vector<vector<int>> grid2 = grid1;

    for (int i = 0; i < N; i++) {
        if (grid1[light[i].first][light[i].second] == 1) continue;
        grid1[light[i].first][light[i].second] = 1;
        for (int j = 0; j < 2; j++) {
            int x = light[i].first;
            int y = light[i].second;
            while (canmove(x, y) && grid1[x][y] != -1) {
                grid1[x][y] = 1;
                x += dx[j];
                y += dy[j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (grid2[light[i].first][light[i].second] == 1) continue;
        grid2[light[i].first][light[i].second] = 1;
        for (int j = 2; j < 4; j++) {
            int x = light[i].first;
            int y = light[i].second;
            while (canmove(x, y) && grid2[x][y] != -1) {
                grid2[x][y] = 1;
                x += dx[j];
                y += dy[j];
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid1[i][j] == 1 || grid2[i][j] == 1) ans++;
        }
    }

    cout << ans << endl;
}
