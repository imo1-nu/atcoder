#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using T = tuple<int, int, int>;

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
    
    int Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // 最小値を取り出すpriority_queue
    priority_queue<T, vector<T>, greater<T>> pq;
    vector<vector<bool>> visited(H, vector<bool>(W));
    for (int i = 0; i < H; ++i) {
        if (visited[i][0] == false) {
            pq.push(make_tuple(A[i][0], i, 0));
            visited[i][0] = true;
        }
        if (visited[i][W - 1] == false) {
            pq.push(make_tuple(A[i][W - 1], i, W - 1));
            visited[i][W - 1] = true;
        }
    }
    for (int j = 1; j < W - 1; ++j) {
        if (visited[0][j] == false) {
            pq.push(make_tuple(A[0][j], 0, j));
            visited[0][j] = true;
        }
        if (visited[H - 1][j] == false) {
            pq.push(make_tuple(A[H - 1][j], H - 1, j));
            visited[H - 1][j] = true;
        }
    }

    int ans = H * W;
    for (int i = 1; i <= Y; ++i) {
        while (!pq.empty()) {
            auto [a, x, y] = pq.top();
            if (a > i) break;
            pq.pop();
            ans--;
            for (int j = 0; j < 4; ++j) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (canmove(nx, ny) && !visited[nx][ny]) {
                    pq.push(make_tuple(A[nx][ny], nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
        cout << ans << endl;
    }
}
