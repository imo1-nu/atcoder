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
    vector<string> G(H);
    for (int i = 0; i < H; i++) {
        cin >> G[i];
    }

    int x = 0, y = 0;
    vector<vector<bool>> vis(H, vector<bool>(W));
    vis[0][0] = true;
    bool ok = true;
    auto check = [&](int i, int j) {
        return 0 <= i && i < H && 0 <= j && j < W;
    };
    map<char, pair<int, int>> dir = {
        {'U', {-1, 0}},
        {'D', {1, 0}},
        {'L', {0, -1}},
        {'R', {0, 1}}
    };
    while (true) {
        int nx = x + dir[G[x][y]].first;
        int ny = y + dir[G[x][y]].second;
        if (!check(nx, ny)) break;
        if (vis[nx][ny]) {
            ok = false;
            break;
        }
        vis[nx][ny] = true;
        x = nx;
        y = ny;
    }

    if (ok) cout << x + 1 << ' ' << y + 1 << endl;
    else cout << -1 << endl;
}
