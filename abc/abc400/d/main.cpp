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
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    A--, B--, C--, D--;
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    auto check = [&](int x, int y) {
        return 0 <= x && x < H && 0 <= y && y < W;
    };

    vector<vector<pair<int, int>>> G(H * W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (!check(ni, nj)) continue;
                if (S[ni][nj] == '.') G[i * W + j].emplace_back(ni * W + nj, 0);
                G[i * W + j].emplace_back(ni * W + nj, 1);
                ni += dx[k];
                nj += dy[k];
                if (!check(ni, nj)) continue;
                G[i * W + j].emplace_back(ni * W + nj, 1);
            }
        }
    }

    vector<int> dist(H * W, 1e9);
    int start = A * W + B;
    dist[start] = 0;
    deque<int> q;
    q.push_back(start);
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();

        for (auto [to, cost] : G[v]) {
            if (dist[to] <= dist[v] + cost) continue; //発見済みの点はスルー
            dist[to] = dist[v] + cost;
            if (cost == 0) q.push_front(to);
            else q.push_back(to);
        }
    }
    cout << dist[C * W + D] << endl;
}
