#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    vector<pair<int, int>> P;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S[i][j] == 'P') {
                P.push_back(make_pair(i, j));
                S[i][j] = '.';
            }
        }
    }

    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    auto check = [&](int x, int y) {
        return 0 <= x && x < N && 0 <= y && y < N && S[x][y] == '.';
    };

    queue<tuple<int, int, int, int>> q;
    q.push(make_tuple(P[0].first, P[0].second, P[1].first, P[1].second));
    vector<vector<vector<vector<int>>>> dist(N, vector<vector<vector<int>>>(N, vector<vector<int>>(N, vector<int>(N, -1))));
    dist[P[0].first][P[0].second][P[1].first][P[1].second] = 0;
    while (!q.empty()) {
        auto [x1, y1, x2, y2] = q.front();
        q.pop();
        if (x1 == x2 && y1 == y2) {
            cout << dist[x1][y1][x2][y2] << endl;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int nx1 = x1 + dx[i];
            int ny1 = y1 + dy[i];
            int nx2 = x2 + dx[i];
            int ny2 = y2 + dy[i];
            if (check(nx1, ny1) == false) {
                nx1 = x1;
                ny1 = y1;
            }
            if (check(nx2, ny2) == false) {
                nx2 = x2;
                ny2 = y2;
            }
            if (dist[nx1][ny1][nx2][ny2] != -1) {
                continue;
            }
            dist[nx1][ny1][nx2][ny2] = dist[x1][y1][x2][y2] + 1;
            q.push(make_tuple(nx1, ny1, nx2, ny2));
        }
    }
    cout << -1 << endl;
}
