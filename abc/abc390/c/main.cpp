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
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    int x1 = H - 1, x2 = 0, y1 = W - 1, y2 = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                x1 = min(x1, i);
                x2 = max(x2, i);
                y1 = min(y1, j);
                y2 = max(y2, j);
            }
        }
    }

    bool ok = true;
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            if (S[i][j] == '.') {
                ok = false;
                break;
            }
        }
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}
