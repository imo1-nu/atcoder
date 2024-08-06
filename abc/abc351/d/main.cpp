#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    vector<vector<pair<int, int>>> g(H, vector<pair<int, int>>(W, make_pair(-1, -1)));
    int ans = 0;
    vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                for (int k = 0; k < 4; k++) {
                    if (i + dx[k] >= 0 && i + dx[k] < H && j + dy[k] >= 0 && j + dy[k] < W && S[i + dx[k]][j + dy[k]] != '#') {
                        S[i + dx[k]][j + dy[k]] = 'a';
                        ans = 1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (g[i][j].first > -1 || S[i][j] == 'a' || S[i][j] == '#') continue;
            queue<pair<int, int>> q;
            pair<int, int> p = make_pair(i, j);
            q.push(p);
            g[i][j] = p;
            int cnt = 0;

            while (!q.empty()) {
                pair<int, int> v = q.front();
                q.pop();
                cnt++;
                cout << v.first << ' ' << v.second << endl;

                if (S[v.first][v.second] == 'a') continue;

                for (int k = 0; k < 4; k++) {
                    if (v.first + dx[k] >= 0 && v.first + dx[k] < H && v.second + dy[k] >= 0 && v.second + dy[k] < W) {
                        if (g[v.first + dx[k]][v.second + dy[k]] != p) {
                            q.push(make_pair(v.first + dx[k], v.second + dy[k]));
                            g[v.first + dx[k]][v.second + dy[k]] = p;
                        }
                    }
                }
            }
            ans = max(ans, cnt);
            cout << cnt << endl << endl;  
        }
    }
    cout << ans << endl;
}