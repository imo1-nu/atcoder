#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int H, W, K;
ll ans = 0;

vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};

bool canmove(int x, int y) {
    if (0 <= x && x < H && 0 <= y && y < W) return true;
    else return false;
}

void dfs(int i, int j, int depth, vector<string>& S, vector<vector<bool>>& visited)
{
    // 深さがKに達するまで探索
    if (depth == K) {
        ans++;
        return;
    }

    // 4方向に移動
    for (int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (canmove(nx, ny) && !visited[nx][ny] && S[nx][ny] == '.') {
            visited[nx][ny] = true;
            dfs(nx, ny, depth+1, S, visited);
            visited[nx][ny] = false;
        }
    }
}


int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> H >> W >> K;
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    // スタート地点を全探索
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '.') {
                vector<vector<bool>> visited(H, vector<bool>(W, false));
                visited[i][j] = true;
                dfs(i, j, 0, S, visited);
            }
        }
    }

    cout << ans << endl;
}
