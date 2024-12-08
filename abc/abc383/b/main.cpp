#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int H, W, D;
    cin >> H >> W >> D;
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    vector<pair<int, int>> pos;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '.') {
                pos.push_back({i, j});
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < (int)pos.size(); i++) {
        for (int j = i + 1; j < (int)pos.size(); j++) {
            int cnt = 0;
            for (int k = 0; k < (int)pos.size(); k++) {
                if (abs(pos[i].first - pos[k].first) + abs(pos[i].second - pos[k].second) <= D || abs(pos[j].first - pos[k].first) + abs(pos[j].second - pos[k].second) <= D) {
                    cnt++;
                }
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
}
