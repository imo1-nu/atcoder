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

    int s;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == 'S') s = i * W + j;
        }
    }

    queue<int> q;
    for (int i = 0; i < 4; i++) q.push(s + i * H * W);
    vector<int> par(4 * H * W, -1);
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    while (!q.empty()) {
        int current = q.front(); q.pop();
        int last_dir = current / (H * W);
        int x = current % (H * W) / W;
        int y = current % W;
        if (S[x][y] == 'G') {
            cout << "Yes" << endl;
            stack<char> route;
            while (current % (H * W) != s) {
                if (last_dir == 0) route.push('U');
                else if (last_dir == 1) route.push('D');
                else if (last_dir == 2) route.push('L');
                else route.push('R');
                current = par[current];
                last_dir = current / (H * W);
            }
            while (!route.empty()) {
                cout << route.top();
                route.pop();
            }
            cout << endl;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int next = nx * W + ny + i * H * W;
            if (!(0 <= nx && nx < H && 0 <= ny && ny < W)) continue;
            if (S[nx][ny] == '#') continue;
            if (S[x][y] == 'o' && i != last_dir) continue;
            if (S[x][y] == 'x' && i == last_dir) continue;
            if (par[next] != -1) continue;
            par[next] = current;
            q.push(next);
        }
    }
    cout << "No" << endl;
}
