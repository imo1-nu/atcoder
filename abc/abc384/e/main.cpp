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
    ll X;
    int P, Q;
    cin >> H >> W >> X >> P >> Q;
    P--; Q--;
    vector<vector<ll>> S(H, vector<ll>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> S[i][j];
        }
    }

    ll ans = S[P][Q];
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    visited[P][Q] = true;
    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> pq;
    pq.push({0, {P, Q}});

    while (!pq.empty()) {
        auto [s, p] = pq.top();
        pq.pop();
        if ((ans - 1) / X + 1 <= s) break;
        ans += s;
        int x = p.first;
        int y = p.second;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (canmove(nx, ny) && !visited[nx][ny]) {
                visited[nx][ny] = true;
                pq.push({S[nx][ny], {nx, ny}});
            }
        }
    }
    cout << ans << endl;
}
