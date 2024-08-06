#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {1, 0, -1, 0, 1, 1, -1, -1};
vector<int> dy = {0, 1, 0, -1, 1, -1, 1, -1};

int ans = 0, H, W;

int check(vector<string> &S, int i, int j) {
    S[i][j] = '0';
    //for (int k = 0; k < H; k++) cout << S[k] << endl;
    for (int k = 0; k < 8; k++) {
        int y = i + dy[k];
        int x = j + dx[k];
        if (0 <= x && x < W && 0 <= y && y < H) {
            if (S[y][x] == '#') check(S, y, x);
        }
    }
    return 0;
}

int main()
{
    cin >> H >> W;
    vector<string> S(H, string(W, '.'));
    for (int i = 0; i < H; i++) cin >> S[i];

    int cnt = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                //cout << i << " " << j << endl;
                check(S, i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
}
