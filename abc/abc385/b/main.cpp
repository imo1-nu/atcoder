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
    int sx, sy;
    cin >> sx >> sy;
    --sx, --sy;
    vector<string> S(H);
    for (int i = 0; i < H; ++i) {
        cin >> S[i];
    }
    string T;
    cin >> T;

    map<char, pair<int, int>> dir = {
        {'U', {-1, 0}},
        {'D', {1, 0}},
        {'L', {0, -1}},
        {'R', {0, 1}}
    };

    auto can_move = [&](int x, int y) {
        return 0 <= x && x < H && 0 <= y && y < W && S[x][y] != '#';
    };

    int ans = 0;
    for (auto c : T) {
        if (can_move(sx + dir[c].first, sy + dir[c].second)) {
            sx += dir[c].first;
            sy += dir[c].second;
            if (S[sx][sy] == '@') {
                ++ans;
                S[sx][sy] = 'x';
            }
        }
    }
    cout << sx + 1 << " " << sy + 1 << ' ' << ans << endl;
}
