#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};
int H, W;

bool canmove(int x, int y) {
    if (0 <= x && x < H && 0 <= y && y < W) return true;
    else return false;
}

int bfs(vector<string> &S, vector<int> &dist, vector<int> starts) { //G, distを用意する
    //初期条件
    int res = 0;
    queue<int> q;
    dist.resize(H * W, -1);
    for (int start : starts) {
        q.push(start);
        dist[start] = 0;
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = v / W + dx[i];
            int ny = v % W + dy[i];
            if (!canmove(nx, ny) || S[nx][ny] == '#' || dist[nx * W + ny] != -1) continue;
            dist[nx * W + ny] = dist[v] + 1;
            q.push(nx * W + ny);
            res = max(res, dist[nx * W + ny]);
        }
    }

    return res;
}


int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> H >> W;

    vector<string> A(H);
    for (ll i = 0; i < H; i++) {
        cin >> A[i];
    }

    vector<int> dist;
    vector<int> starts;
    for (ll i = 0; i < H; i++) {
        for (ll j = 0; j < W; j++) {
            if (A[i][j] == '#') {
                starts.push_back(i * W + j);
            }
        }
    }

    int ans = bfs(A, dist, starts);
    cout << ans << endl;
}
