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

    vector<vector<bool>> count(H, vector<bool>(W));
    vector<vector<bool>> stopped(H, vector<bool>(W));
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    auto can_move = [&](int x, int y) -> bool {
        return 0 <= x && x < H && 0 <= y && y < W && S[x][y] == '.';
    };

    function<void(int, int)> dfs = [&](int x, int y) {
        count[x][y] = true;
        stopped[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int nx = x;
            int ny = y;
            while (can_move(nx + dx[i], ny + dy[i])) {
                nx += dx[i];
                ny += dy[i];
                count[nx][ny] = true;
            }
            if (!stopped[nx][ny]) dfs(nx, ny);
        }
    };

    int ans = 0;
    dfs(1, 1);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (count[i][j]) ans++;
        }
    }
    cout << ans << endl;
}
