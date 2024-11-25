#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int H, W, M;
    cin >> H >> W >> M;
    vector<pair<int, int>> row(H), col(W);
    set<pair<int, int>> bombs;
    for (int i = 0; i < M; i++) {
        int h, w;
        cin >> h >> w;
        h--; w--;
        bombs.insert({h, w});
        row[h].first++;
        col[w].first++;
    }
    for (int i = 0; i < H; i++) row[i].second = i;
    for (int i = 0; i < W; i++) col[i].second = i;
    sort(row.begin(), row.end(), greater<pair<int, int>>());
    sort(col.begin(), col.end(), greater<pair<int, int>>());
    
    int max_row_num = 0;
    int max_col_num = 0;
    for (int i = 0; i < H; i++) {
        if (row[i].first != row[0].first) break;
        max_row_num++;
    }
    for (int i = 0; i < W; i++) {
        if (col[i].first != col[0].first) break;
        max_col_num++;
    }

    int ans = row[0].first + col[0].first - 1;

    int cnt = 0;
    for (int i = 0; i < max_row_num; i++) {
        for (int j = 0; j < max_col_num; j++) {
            if (!bombs.count({row[i].second, col[j].second}) || cnt == M) {
                cout << ans + 1 << endl;
                return 0;
            }
            cnt++;
        }
    }
    cout << ans << endl;
}
