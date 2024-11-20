#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    vector<vector<int>> Sum(H+1, vector<int>(W+1));
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            Sum[i][j] = Sum[i-1][j] + Sum[i][j-1] - Sum[i-1][j-1] + (S[i-1][j-1] == '1');
        }
    }

    int ans = 1e9;
    for (int i = 0; i < (1 << (H - 1)); i++) {
        vector<int> cut;
        cut.push_back(0);
        for (int j = 0; j < H - 1; j++) {
            if (i >> j & 1) {
                cut.push_back(j + 1);
            }
        }
        cut.push_back(H);

        int num = cut.size() - 1;
        int l = 0, r = 1;
        int cnt = 0;
        while (r <= W) {
            bool ok = true;
            for (int j = 0; j < num; j++) {
                int cnt = Sum[cut[j + 1]][r] - Sum[cut[j + 1]][l] - Sum[cut[j]][r] + Sum[cut[j]][l];
                if (cnt > K) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                r++;
            } else {
                if (l == r - 1) {
                    cnt = 1e9;
                    break;
                }
                cnt++;
                l = r - 1;
            }
        }
        ans = min(ans, cnt + num - 1);
    }

    cout << ans << endl;
}
