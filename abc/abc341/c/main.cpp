#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W, N;
    cin >> H >> W >> N;
    string T;
    cin >> T;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];
    int ans = 0, k;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') continue;
            int x = i, y = j;
            for (k = 0; k < N; k++) {
                if (T[k] == 'L') y--;
                if (T[k] == 'R') y++;
                if (T[k] == 'U') x--;
                if (T[k] == 'D') x++;
                if (S[x][y] == '#') break;
            }
            if (k == N) ans++;
        }
    }
    cout << ans << endl;
}
